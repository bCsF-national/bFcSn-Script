// ==UserScript==
// @name         Bypass Fly.inc
// @namespace    Violentmonkey Scripts
// @version      14.1
// @author       bFsCnBlogger
// @run-at       document-body
// @grant        none
// @description  Bypass Fly.inc no need focus
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
// @match        *://techedifier.com/*
// @match        *://phineypet.com/*
// @match        *://talkforfitness.com/*
// ==/UserScript==

(function(){
'use strict'
function docReady(fn){ if (document.readyState === "complete" || document.readyState === "interactive") {setTimeout(fn, 3000);} else {document.addEventListener("DOMContentLoaded", fn);}}
function flypass(){
const h = new URL(location.href);
if (h.pathname === '/adblock.html' || h.pathname === '/bypass.html'){ location.href = h.host + '?redirect_to=random' }
const existo = selector => document.querySelector(selector);
const _recaptcha_s = (selector, tiempo_de_espera = 1) => { const t= window.setInterval( function() { if (window.grecaptcha && !!window.grecaptcha.getResponse()) { selector.submit(); clearInterval(t);}}, tiempo_de_espera * 2500);}
const _elemento_s = (selector, tiempo_de_espera = 1) => { window.setTimeout(function() { selector.submit();}, tiempo_de_espera * 2500);}
var formstotal = document.forms.length;
for (var f=0; f<formstotal;f++){ var form = document.getElementsByTagName("form")[f]; var sipaso = form.getAttribute("action");
if (sipaso==='/adblock.html' || sipaso==='/bypass.html' ){console.log('flybite');} else {console.log('flypass ok');
if (existo(".g-recaptcha")) { _recaptcha_s(form, 2); break;}
else { _elemento_s(form, 7); break;}}};
}
docReady(flypass);
})();
