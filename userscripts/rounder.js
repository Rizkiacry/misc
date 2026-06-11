// ==UserScript==
// @name         Smart Score Rounder (Intervals of 5)
// @namespace    http://tampermonkey.net/
// @version      4.0
// @description  Floors scores to nearest 5 (100-scale) or nearest 0.5 (10-scale). Keeps 75 and 7.5 clean.
// @author       You
// @match        *://anilist.co/*
// @match        *://*/*
// @grant        none
// ==/UserScript==

(function() {
    'use strict';

    function roundScores() {
        // Find all spans inside user links
        const scoreElements = document.querySelectorAll('a[href*="/user/"] span');

        scoreElements.forEach(span => {
            // Prevent double-processing
            if (span.getAttribute('data-processed')) return;

            const originalText = span.innerText.trim();

            // Extract the number
            const match = originalText.match(/^([\d\.]+)/);

            if (match) {
                const originalNumber = parseFloat(match[1]);

                if (!isNaN(originalNumber)) {
                    let targetScore;

                    // --- UPDATED LOGIC ---
                    if (originalNumber > 10) {
                        // 100-SCALE: Floor to nearest 5
                        // 75 -> 75 (Clean)
                        // 72 -> 70 (Rounded)
                        // 79 -> 75 (Rounded)
                        targetScore = Math.floor(originalNumber / 5) * 5;
                    } else {
                        // 10-SCALE: Floor to nearest 0.5
                        // 7.5 -> 7.5 (Clean)
                        // 7.7 -> 7.5 (Rounded)
                        // 7.2 -> 7.0 (Rounded)
                        targetScore = Math.floor(originalNumber * 2) / 2;
                    }
                    // ---------------------

                    // Only apply changes if the number is different
                    if (originalNumber !== targetScore) {

                        // Preserve the /10 or /100 suffix
                        let suffix = "";
                        if (originalText.includes("/100")) suffix = "/100";
                        else if (originalText.includes("/10")) suffix = "/10";

                        // Update text with tilde
                        span.innerText = `~${targetScore}${suffix}`;

                        // CSS overrides to ensure visibility
                        span.style.visibility = "visible";
                        span.style.content = "normal";
                    }

                    // Mark as processed
                    span.setAttribute('data-processed', 'true');
                }
            }
        });
    }

    roundScores();

    // Observer for dynamic content (scrolling/loading)
    const observer = new MutationObserver((mutations) => {
        let shouldRun = false;
        for (let m of mutations) {
            if (m.addedNodes.length > 0) {
                shouldRun = true;
                break;
            }
        }
        if (shouldRun) roundScores();
    });

    observer.observe(document.body, { childList: true, subtree: true });

})();
