// ==UserScript==
// @name         Alphabetical Follow Sort
// @namespace    http://tampermonkey.net/
// @version      1.0
// @description  Sorts a.follow elements by div.name text alphabetically
// @author       You
// @match        *://anilist.co/*
// @grant        none
// ==/UserScript==

(function() {
    'use strict';

    const observer = new MutationObserver((mutations) => {
        for (const m of mutations) {
            if (m.addedNodes.length > 0) {
                sortFollows();
                break;
            }
        }
    });

    observer.observe(document.body, { childList: true, subtree: true });

    function sortFollows() {
        observer.disconnect();
        try {
            const container = document.querySelector('a.follow')?.parentElement;
            if (!container) return;

            const items = [...container.querySelectorAll(':scope > a.follow')];
            if (items.length < 2) return;

            items.sort((a, b) => {
                const nameA = a.querySelector('div.name')?.textContent ?? '';
                const nameB = b.querySelector('div.name')?.textContent ?? '';
                return nameA.localeCompare(nameB);
            });

            items.forEach(el => container.appendChild(el));
        } catch (e) {
            console.warn('sortFollows:', e);
        } finally {
            observer.observe(document.body, { childList: true, subtree: true });
        }
    }

    sortFollows();
})();
