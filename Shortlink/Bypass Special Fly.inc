// ==UserScript==
// @name        Special Fly.inc Pass
// @namespace   bFcsn scripts
// @match       *://thumb8.net/*
// @match       *://thumb9.net/*
// @match       *://crewbase.net/*
// @match       *://crewus.net/*
// @match       *://shinchu.net/*
// @match       *://shinbhu.net/*
// @match       *://ultraten.net/*
// @match       *://uniqueten.net/*
// @match       *://topcryptoz.net/*
// @match       *://allcryptoz.net/*
// @match       *://techedifier.com/*
// @match       *://phineypet.com/*
// @match       *://talkforfitness.com/*
// @grant       none
// @version     14.3
// @author      bFsCnBlogger
// @description Bypass fly.inc no need recaptcha
// @run-at      document-body
// ==/UserScript==

(function(){
'use strict'
function docReady(fn){ if (document.readyState === "complete" || document.readyState === "interactive") {setTimeout(fn, 5000);} else {document.addEventListener("DOMContentLoaded", fn);}};function flypass(){const h = new URL(location.href);function recaptcha(selector, timeInSec = 1, funcName = 'setTimeout') {if (existo(selector)) {window[funcName](function() {submit(selector);}, timeInSec * 3000);}};function submit(selector) {existo(selector).submit();}if (h.pathname === '/adblock.html' || h.pathname === '/bypass.html'){ location.href = h.host + '?redirect_to=random' }const existo = selector => document.querySelector(selector);recaptcha("form.text-center", 2); const _recaptcha_s = (selector, tiempo_de_espera = 1) => { const t= window.setInterval( function() { if (window.grecaptcha && !!window.grecaptcha.getResponse()) { selector.submit(); clearInterval(t);}}, tiempo_de_espera * 1000);}; const _elemento_s = (selector, tiempo_de_espera = 1) => { window.setTimeout(function() { selector.submit();}, tiempo_de_espera * 3000);}; var formstotal = document.forms.length; for (var f=0; f<formstotal;f++){ var form = document.getElementsByTagName("form")[f];var sipaso = form.getAttribute("action");if (sipaso==='/adblock.html' || sipaso==='/bypass.html' ){console.log('flybite');}else {console.log('flypass ok');if (existo(".g-recaptcha")) { _recaptcha_s(form, 2); break;}else { _elemento_s(form, 5); break;}}};} docReady(flypass);})();
