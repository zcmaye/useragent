#include "RenderingEngine.h"

/**
 * EdgeHTML is a proprietary layout engine developed for the Microsoft Edge web browser, developed by Microsoft.
 */
ZCENUM_V(RenderingEngine, EDGE_HTML, "EdgeHTML");
/**
 * Trident is the the Microsoft layout engine, mainly used by Internet Explorer.
 */
ZCENUM_V(RenderingEngine, TRIDENT, "Trident");
/**
 * HTML parsing and rendering engine of Microsoft Office Word, used by some other products of the Office suite instead of Trident.
 */
ZCENUM_V(RenderingEngine, WORD, "Microsoft Office Word");
/**
 * Open source and cross platform layout engine, used by Firefox and many other browsers.
 */
ZCENUM_V(RenderingEngine, GECKO, "Gecko");
/**
 * Layout engine based on KHTML, used by Safari, Chrome and some other browsers.
 */
ZCENUM_V(RenderingEngine, WEBKIT, "WebKit");
/**
 * Proprietary layout engine by Opera Software ASA
 */
ZCENUM_V(RenderingEngine, PRESTO, "Presto");
/**
 * Original layout engine of the Mozilla browser and related products. Predecessor of Gecko.
 */
ZCENUM_V(RenderingEngine, MOZILLA, "Mozilla");
/**
 * Layout engine of the KDE project
 */
ZCENUM_V(RenderingEngine, KHTML, "KHTML");
/**
 * Other or unknown layout engine.
 */
ZCENUM_V(RenderingEngine, BLINK, "Blink");
/**
 * Layout engine developed as part ofthe Chromium project. Fored from WebKit.
 */
ZCENUM_V(RenderingEngine, OTHER, "Other");

