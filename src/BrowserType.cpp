#include "BrowserType.h"

/**
 * Standard web-browser
 */
ZCENUM_V(BrowserType,WEB_BROWSER,"Browser");
/**
 * Special web-browser for mobile devices
 */
ZCENUM_V(BrowserType,MOBILE_BROWSER,"Browser (mobile)");
/**
 * Text only browser like the good old Lynx
 */
ZCENUM_V(BrowserType,TEXT_BROWSER,"Browser (text only)");
/**
 * Email client like Thunderbird
 */
ZCENUM_V(BrowserType,EMAIL_CLIENT,"Email Client");
/**
 * Search robot, spider, crawler,...
 */
ZCENUM_V(BrowserType,ROBOT,"Robot");
/**
 * Downloading tools
 */
ZCENUM_V(BrowserType,TOOL,"Downloading tool");
/**
 * Application
 */
ZCENUM_V(BrowserType,APP,"Application");

ZCENUM_V(BrowserType,UNKNOWN,"unknown");

