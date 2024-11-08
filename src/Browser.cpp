#include "Browser.h"
#include "SafariUtils.h"

/**
 * Outlook email client
 */
ZCENUM_V(Browser, OUTLOOK, &Manufacturer::MICROSOFT, {}, 100, "Outlook", { "MSOffice" }, {}, & BrowserType::EMAIL_CLIENT, & RenderingEngine::WORD, std::make_shared<PatternBasedVersionFetcher>("MSOffice (([0-9]+))"));// before IE7
/**
 * Microsoft Outlook 2007 identifies itself as MSIE7 but uses the html rendering engine of Word 2007.
 * Example user agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0; SLCC1; .NET CLR 2.0.50727; .NET CLR 3.0.04506; .NET CLR 1.1.4322; MSOffice 12)
 */
ZCENUM_V(Browser,OUTLOOK2007,&Manufacturer::MICROSOFT,&Browser::OUTLOOK, 107, "Outlook 2007", { "MSOffice 12" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::WORD, {});// before IE7
ZCENUM_V(Browser,OUTLOOK2013,&Manufacturer::MICROSOFT,&Browser::OUTLOOK, 109, "Outlook 2013", { "Microsoft Outlook 15" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::WORD, {});// before IE7
/**
 * Outlook 2010 is still using the rendering engine of Word. http://www.fixoutlook.org
 */
ZCENUM_V(Browser,OUTLOOK2010,&Manufacturer::MICROSOFT,&Browser::OUTLOOK, 108, "Outlook 2010", { "MSOffice 14", "Microsoft Outlook 14" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::WORD, {});// before IE7

/**
 * Family of Internet Explorer browsers
 */
ZCENUM_V(Browser,IE,&Manufacturer::MICROSOFT,{}, 1, "Internet Explorer", { "MSIE", "Trident", "IE " }, { "BingPreview", "Xbox", "Xbox One" }, &BrowserType::WEB_BROWSER, &RenderingEngine::TRIDENT, std::make_shared<PatternBasedVersionFetcher>("MSIE (([\\d]+).([\\w]+))"));// before Mozilla
/**
 * Since version 7 Outlook Express is identifying itself. By detecting Outlook Express we can not
 * identify the Internet Explorer version which is probably used for the rendering.
 * Obviously this product is now called Windows Live Mail Desktop or just Windows Live Mail.
 */
ZCENUM_V(Browser,OUTLOOK_EXPRESS7,&Manufacturer::MICROSOFT,&Browser::IE, 110, "Windows Live Mail", { "Outlook-Express/7.0" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::TRIDENT, {});// before IE7, previously known as Outlook Express. First released in 2006, offered with different name later
/**
 * Since 2007 the mobile edition of Internet Explorer identifies itself as IEMobile in the user-agent.
 * If previous versions have to be detected, use the operating system information as well.
 */
ZCENUM_V(Browser,IEMOBILE11,&Manufacturer::MICROSOFT,&Browser::IE, 125, "IE Mobile 11",  { "IEMobile/11" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::TRIDENT, std::make_shared<PatternBasedVersionFetcher>("(?:Trident\\/7|IE)(?:.[0-9]*;)?(?:.*rv:| )(([0-9]+).?([0-9]+))"));// before Mozilla
ZCENUM_V(Browser,IEMOBILE10,&Manufacturer::MICROSOFT,&Browser::IE, 124, "IE Mobile 10",  { "IEMobile/10" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::TRIDENT, {});// before MSIE strings
ZCENUM_V(Browser,IEMOBILE9,&Manufacturer::MICROSOFT,&Browser::IE, 123, "IE Mobile 9",  { "IEMobile/9" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::TRIDENT, {});// before MSIE strings
ZCENUM_V(Browser,IEMOBILE7,&Manufacturer::MICROSOFT,&Browser::IE, 121, "IE Mobile 7",  { "IEMobile 7" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::TRIDENT, {});// before MSIE strings
ZCENUM_V(Browser,IEMOBILE6,&Manufacturer::MICROSOFT,&Browser::IE, 120, "IE Mobile 6",  { "IEMobile 6" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::TRIDENT, {});// before MSIE
ZCENUM_V(Browser,IE_XBOX,&Manufacturer::MICROSOFT,&Browser::IE, 360, "Xbox", { "xbox" }, {}, &BrowserType::WEB_BROWSER, &RenderingEngine::TRIDENT, {});
ZCENUM_V(Browser,IE11,&Manufacturer::MICROSOFT,&Browser::IE, 95, "Internet Explorer 11",  { "Trident/7", "IE 11." },  {"MSIE 7", "BingPreview"}, &BrowserType::WEB_BROWSER, &RenderingEngine::TRIDENT, std::make_shared<PatternBasedVersionFetcher>("(?:Trident\\/7|IE)(?:.[0-9]*;)?(?:.*rv:| )(([0-9]+).?([0-9]+))"));//  // before Mozilla
ZCENUM_V(Browser,IE10,&Manufacturer::MICROSOFT,&Browser::IE, 92, "Internet Explorer 10",  { "MSIE 10" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::TRIDENT, {});//  // before MSIE
ZCENUM_V(Browser,IE9,&Manufacturer::MICROSOFT,&Browser::IE, 90, "Internet Explorer 9",  { "MSIE 9" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::TRIDENT, {});//  // before MSIE
ZCENUM_V(Browser,IE8,&Manufacturer::MICROSOFT,&Browser::IE, 80, "Internet Explorer 8",  { "MSIE 8" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::TRIDENT, {});//  // before MSIE
ZCENUM_V(Browser,IE7,&Manufacturer::MICROSOFT,&Browser::IE, 70, "Internet Explorer 7",  { "MSIE 7" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::TRIDENT, {});//  // before MSIE
ZCENUM_V(Browser,IE6,&Manufacturer::MICROSOFT,&Browser::IE, 60, "Internet Explorer 6",  { "MSIE 6" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::TRIDENT, {});//  // before MSIE
ZCENUM_V(Browser,IE5_5,&Manufacturer::MICROSOFT,&Browser::IE, 55, "Internet Explorer 5.5",  { "MSIE 5.5" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::TRIDENT, {});// before MSIE
ZCENUM_V(Browser,IE5,&Manufacturer::MICROSOFT,&Browser::IE, 50, "Internet Explorer 5",  { "MSIE 5" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::TRIDENT, {});// before MSIE

/**
 * Family of Microsoft Edge browsers. Pretends to be Chrome and claims to be webkit compatible.
 * Numbering used here is actually the rendering engine version, not the displayed edge version.
 * For instance 14.14332 is Edge 37 while 14.14342 is Edge 38. User agent only provides the version of the rendering engine.
 * @see <a href="https://en.wikipedia.org/wiki/Microsoft_Edge#Release_history">Microsoft Edge release history</a>
 */
ZCENUM_V(Browser,EDGE,&Manufacturer::MICROSOFT,{}, 300, "Microsoft Edge", { "Edge" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::EDGE_HTML, std::make_shared<PatternBasedVersionFetcher>("(?:Edge\\/(([0-9]+).([0-9]*)))"));
ZCENUM_V(Browser,EDGE_MOBILE,&Manufacturer::MICROSOFT,&Browser::EDGE, 304, "Microsoft Edge Mobile",  {"Mobile Safari"},{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::EDGE_HTML, {});
ZCENUM_V(Browser,EDGE_MOBILE15,&Manufacturer::MICROSOFT,&Browser::EDGE_MOBILE, 310, "Microsoft Edge Mobile (layout engine 15)",  {"Edge/15"},{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::EDGE_HTML, {});
ZCENUM_V(Browser,EDGE_MOBILE14,&Manufacturer::MICROSOFT,&Browser::EDGE_MOBILE, 307, "Microsoft Edge Mobile (layout engine 14)",  {"Edge/14"},{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::EDGE_HTML, {});
ZCENUM_V(Browser,EDGE_MOBILE13,&Manufacturer::MICROSOFT,&Browser::EDGE_MOBILE, 308, "Microsoft Edge Mobile (layout engine 13)",  {"Edge/13"},{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::EDGE_HTML, {});
ZCENUM_V(Browser,EDGE_MOBILE12,&Manufacturer::MICROSOFT,&Browser::EDGE_MOBILE, 302, "Microsoft Edge Mobile (layout engine 12)",  {"Edge/12"},{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::EDGE_HTML, {});
ZCENUM_V(Browser,EDGE16,&Manufacturer::MICROSOFT,&Browser::EDGE, 312, "Microsoft Edge (layout engine 16)", { "Edge/16" }, { "Mobile" }, &BrowserType::WEB_BROWSER, &RenderingEngine::EDGE_HTML, {});
ZCENUM_V(Browser,EDGE15,&Manufacturer::MICROSOFT,&Browser::EDGE, 309, "Microsoft Edge (layout engine 15)",  {"Edge/15"},  {"Mobile"}, &BrowserType::WEB_BROWSER, &RenderingEngine::EDGE_HTML, {});
ZCENUM_V(Browser,EDGE14,&Manufacturer::MICROSOFT,&Browser::EDGE, 305, "Microsoft Edge (layout engine 14)",  {"Edge/14"},  {"Mobile"}, &BrowserType::WEB_BROWSER, &RenderingEngine::EDGE_HTML, {});
ZCENUM_V(Browser,EDGE13,&Manufacturer::MICROSOFT,&Browser::EDGE, 303, "Microsoft Edge (layout engine 13)",  {"Edge/13"},  {"Mobile"}, &BrowserType::WEB_BROWSER, &RenderingEngine::EDGE_HTML, {});
ZCENUM_V(Browser,EDGE12,&Manufacturer::MICROSOFT,&Browser::EDGE, 301, "Microsoft Edge (layout engine 12)",  {"Edge/12"},  {"Mobile"}, &BrowserType::WEB_BROWSER, &RenderingEngine::EDGE_HTML, {});

/**
 * Google Chrome browser
 */
ZCENUM_V(Browser,CHROME,&Manufacturer::GOOGLE,{}, 1, "Chrome", { "Chrome", "CrMo", "CriOS" }, { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("Chrome\\/(([0-9]+).?([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));// before Mozilla
ZCENUM_V(Browser,CHROME_MOBILE,&Manufacturer::GOOGLE,&Browser::CHROME, 100, "Chrome Mobile", { "CrMo","CriOS", "Mobile Safari" }, { "OPR/" }, &BrowserType::MOBILE_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("(?:CriOS|CrMo|Chrome)\\/(([0-9]+).?([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,CHROME65,&Manufacturer::GOOGLE,&Browser::CHROME, 71, "Chrome 65", { "Chrome/65" }, { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME64,&Manufacturer::GOOGLE,&Browser::CHROME, 70, "Chrome 64",  { "Chrome/64" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME63,&Manufacturer::GOOGLE,&Browser::CHROME, 69, "Chrome 63",  { "Chrome/63" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME62,&Manufacturer::GOOGLE,&Browser::CHROME, 68, "Chrome 62",  { "Chrome/62" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME61,&Manufacturer::GOOGLE,&Browser::CHROME, 67, "Chrome 61",  { "Chrome/61" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME60,&Manufacturer::GOOGLE,&Browser::CHROME, 66, "Chrome 60",  { "Chrome/60" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME59,&Manufacturer::GOOGLE,&Browser::CHROME, 65, "Chrome 59",  { "Chrome/59" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME58,&Manufacturer::GOOGLE,&Browser::CHROME, 64, "Chrome 58",  { "Chrome/58" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME57,&Manufacturer::GOOGLE,&Browser::CHROME, 63, "Chrome 57",  { "Chrome/57" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME56,&Manufacturer::GOOGLE,&Browser::CHROME, 62, "Chrome 56",  { "Chrome/56" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME55,&Manufacturer::GOOGLE,&Browser::CHROME, 61, "Chrome 55",  { "Chrome/55" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME54,&Manufacturer::GOOGLE,&Browser::CHROME, 60, "Chrome 54",  { "Chrome/54" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME53,&Manufacturer::GOOGLE,&Browser::CHROME, 59, "Chrome 53",  { "Chrome/53" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME52,&Manufacturer::GOOGLE,&Browser::CHROME, 58, "Chrome 52",  { "Chrome/52" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME51,&Manufacturer::GOOGLE,&Browser::CHROME, 57, "Chrome 51",  { "Chrome/51" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME50,&Manufacturer::GOOGLE,&Browser::CHROME, 56, "Chrome 50",  { "Chrome/50" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME49,&Manufacturer::GOOGLE,&Browser::CHROME, 55, "Chrome 49",  { "Chrome/49" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME48,&Manufacturer::GOOGLE,&Browser::CHROME, 53, "Chrome 48",  { "Chrome/48" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME47,&Manufacturer::GOOGLE,&Browser::CHROME, 52, "Chrome 47",  { "Chrome/47" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME46,&Manufacturer::GOOGLE,&Browser::CHROME, 51, "Chrome 46",  { "Chrome/46" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME45,&Manufacturer::GOOGLE,&Browser::CHROME, 50, "Chrome 45",  { "Chrome/45" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME44,&Manufacturer::GOOGLE,&Browser::CHROME, 49, "Chrome 44",  { "Chrome/44" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME43,&Manufacturer::GOOGLE,&Browser::CHROME, 48, "Chrome 43",  { "Chrome/43" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME42,&Manufacturer::GOOGLE,&Browser::CHROME, 47, "Chrome 42",  { "Chrome/42" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME41,&Manufacturer::GOOGLE,&Browser::CHROME, 46, "Chrome 41",  { "Chrome/41" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME40,&Manufacturer::GOOGLE,&Browser::CHROME, 45, "Chrome 40",  { "Chrome/40" },  { "OPR/", "Web Preview", "Vivaldi" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME39,&Manufacturer::GOOGLE,&Browser::CHROME, 44, "Chrome 39",  { "Chrome/39" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME38,&Manufacturer::GOOGLE,&Browser::CHROME, 43, "Chrome 38",  { "Chrome/38" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME37,&Manufacturer::GOOGLE,&Browser::CHROME, 42, "Chrome 37",  { "Chrome/37" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME36,&Manufacturer::GOOGLE,&Browser::CHROME, 41, "Chrome 36",  { "Chrome/36" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME35,&Manufacturer::GOOGLE,&Browser::CHROME, 40, "Chrome 35",  { "Chrome/35" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME34,&Manufacturer::GOOGLE,&Browser::CHROME, 39, "Chrome 34",  { "Chrome/34" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME33,&Manufacturer::GOOGLE,&Browser::CHROME, 38, "Chrome 33",  { "Chrome/33" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME32,&Manufacturer::GOOGLE,&Browser::CHROME, 37, "Chrome 32",  { "Chrome/32" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME31,&Manufacturer::GOOGLE,&Browser::CHROME, 36, "Chrome 31",  { "Chrome/31" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME30,&Manufacturer::GOOGLE,&Browser::CHROME, 35, "Chrome 30",  { "Chrome/30" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME29,&Manufacturer::GOOGLE,&Browser::CHROME, 34, "Chrome 29",  { "Chrome/29" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME28,&Manufacturer::GOOGLE,&Browser::CHROME, 33, "Chrome 28",  { "Chrome/28" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME27,&Manufacturer::GOOGLE,&Browser::CHROME, 32, "Chrome 27",  { "Chrome/27" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME26,&Manufacturer::GOOGLE,&Browser::CHROME, 31, "Chrome 26",  { "Chrome/26" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME25,&Manufacturer::GOOGLE,&Browser::CHROME, 30, "Chrome 25",  { "Chrome/25" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME24,&Manufacturer::GOOGLE,&Browser::CHROME, 29, "Chrome 24",  { "Chrome/24" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME23,&Manufacturer::GOOGLE,&Browser::CHROME, 28, "Chrome 23",  { "Chrome/23" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME22,&Manufacturer::GOOGLE,&Browser::CHROME, 27, "Chrome 22",  { "Chrome/22" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME21,&Manufacturer::GOOGLE,&Browser::CHROME, 26, "Chrome 21",  { "Chrome/21" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME20,&Manufacturer::GOOGLE,&Browser::CHROME, 25, "Chrome 20",  { "Chrome/20" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME19,&Manufacturer::GOOGLE,&Browser::CHROME, 24, "Chrome 19",  { "Chrome/19" },  { "OPR/", "Web Preview" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME18,&Manufacturer::GOOGLE,&Browser::CHROME, 23, "Chrome 18",  { "Chrome/18" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME17,&Manufacturer::GOOGLE,&Browser::CHROME, 22, "Chrome 17",  { "Chrome/17" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME16,&Manufacturer::GOOGLE,&Browser::CHROME, 21, "Chrome 16",  { "Chrome/16" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME15,&Manufacturer::GOOGLE,&Browser::CHROME, 20, "Chrome 15",  { "Chrome/15" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME14,&Manufacturer::GOOGLE,&Browser::CHROME, 19, "Chrome 14",  { "Chrome/14" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME13,&Manufacturer::GOOGLE,&Browser::CHROME, 18, "Chrome 13",  { "Chrome/13" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME12,&Manufacturer::GOOGLE,&Browser::CHROME, 17, "Chrome 12",  { "Chrome/12" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME11,&Manufacturer::GOOGLE,&Browser::CHROME, 16, "Chrome 11",  { "Chrome/11" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME10,&Manufacturer::GOOGLE,&Browser::CHROME, 15, "Chrome 10",  { "Chrome/10" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME9,&Manufacturer::GOOGLE,&Browser::CHROME, 10, "Chrome 9", { "Chrome/9" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla
ZCENUM_V(Browser,CHROME8,&Manufacturer::GOOGLE,&Browser::CHROME, 5, "Chrome 8",  { "Chrome/8" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// before Mozilla

ZCENUM_V(Browser,OMNIWEB,&Manufacturer::OTHER,{}, 2, "Omniweb", { "OmniWeb" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});//

ZCENUM_V(Browser,FIREFOX,&Manufacturer::MOZILLA,{}, 10, "Firefox",  { "Firefox", "FxiOS" },  {"camino", "flock", "ggpht.com", "WordPress.com mShots"}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, std::make_shared<PatternBasedVersionFetcher>("Firefox\\/(([0-9]+).?([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX3MOBILE,&Manufacturer::MOZILLA,&Browser::FIREFOX, 31, "Firefox 3 Mobile", { "Firefox/3.5 Maemo" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX_MOBILE,&Manufacturer::MOZILLA,&Browser::FIREFOX, 200, "Firefox Mobile",  { "Mobile" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX_MOBILE23,&Manufacturer::MOZILLA,&Browser::FIREFOX_MOBILE, 223, "Firefox Mobile 23", { "Firefox/23" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
/**
 * Firefox for iOS devices. This Firefox version is using webkit instead of gecko rendering engine.
 */
ZCENUM_V(Browser,FIREFOX_MOBILE_IOS,&Manufacturer::MOZILLA,&Browser::FIREFOX_MOBILE, 224, "Firefox Mobile (iOS)", { "FxiOS" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::WEBKIT, {});
ZCENUM_V(Browser,FIREFOX59,&Manufacturer::MOZILLA,&Browser::FIREFOX, 238, "Firefox 59", { "Firefox/59" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX58,&Manufacturer::MOZILLA,&Browser::FIREFOX, 237, "Firefox 58",  { "Firefox/58" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX57,&Manufacturer::MOZILLA,&Browser::FIREFOX, 236, "Firefox 57",  { "Firefox/57" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX56,&Manufacturer::MOZILLA,&Browser::FIREFOX, 235, "Firefox 56",  { "Firefox/56" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX55,&Manufacturer::MOZILLA,&Browser::FIREFOX, 234, "Firefox 55",  { "Firefox/55" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX54,&Manufacturer::MOZILLA,&Browser::FIREFOX, 233, "Firefox 54",  { "Firefox/54" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX53,&Manufacturer::MOZILLA,&Browser::FIREFOX, 232, "Firefox 53",  { "Firefox/53" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX52,&Manufacturer::MOZILLA,&Browser::FIREFOX, 231, "Firefox 52",  { "Firefox/52" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX51,&Manufacturer::MOZILLA,&Browser::FIREFOX, 230, "Firefox 51",  { "Firefox/51" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX50,&Manufacturer::MOZILLA,&Browser::FIREFOX, 229, "Firefox 50",  { "Firefox/50" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX49,&Manufacturer::MOZILLA,&Browser::FIREFOX, 228, "Firefox 49",  { "Firefox/49" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX48,&Manufacturer::MOZILLA,&Browser::FIREFOX, 227, "Firefox 48",  { "Firefox/48" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX47,&Manufacturer::MOZILLA,&Browser::FIREFOX, 226, "Firefox 47",  { "Firefox/47" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX46,&Manufacturer::MOZILLA,&Browser::FIREFOX, 225, "Firefox 46",  { "Firefox/46" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX45,&Manufacturer::MOZILLA,&Browser::FIREFOX, 222, "Firefox 45",  { "Firefox/45" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX44,&Manufacturer::MOZILLA,&Browser::FIREFOX, 221, "Firefox 44",  { "Firefox/44" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX43,&Manufacturer::MOZILLA,&Browser::FIREFOX, 220, "Firefox 43",  { "Firefox/43" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX42,&Manufacturer::MOZILLA,&Browser::FIREFOX, 219, "Firefox 42",  { "Firefox/42" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX41,&Manufacturer::MOZILLA,&Browser::FIREFOX, 218, "Firefox 41",  { "Firefox/41" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX40,&Manufacturer::MOZILLA,&Browser::FIREFOX, 217, "Firefox 40",  { "Firefox/40" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX39,&Manufacturer::MOZILLA,&Browser::FIREFOX, 216, "Firefox 39",  { "Firefox/39" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX38,&Manufacturer::MOZILLA,&Browser::FIREFOX, 215, "Firefox 38",  { "Firefox/38" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX37,&Manufacturer::MOZILLA,&Browser::FIREFOX, 214, "Firefox 37",  { "Firefox/37" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX36,&Manufacturer::MOZILLA,&Browser::FIREFOX, 213, "Firefox 36",  { "Firefox/36" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX35,&Manufacturer::MOZILLA,&Browser::FIREFOX, 212, "Firefox 35",  { "Firefox/35" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX34,&Manufacturer::MOZILLA,&Browser::FIREFOX, 211, "Firefox 34",  { "Firefox/34" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX33,&Manufacturer::MOZILLA,&Browser::FIREFOX, 210, "Firefox 33",  { "Firefox/33" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX32,&Manufacturer::MOZILLA,&Browser::FIREFOX, 109, "Firefox 32",  { "Firefox/32" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX31,&Manufacturer::MOZILLA,&Browser::FIREFOX, 310, "Firefox 31",  { "Firefox/31" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX30,&Manufacturer::MOZILLA,&Browser::FIREFOX, 300, "Firefox 30",  { "Firefox/30" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX29,&Manufacturer::MOZILLA,&Browser::FIREFOX, 290, "Firefox 29",  { "Firefox/29" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX28,&Manufacturer::MOZILLA,&Browser::FIREFOX, 280, "Firefox 28",  { "Firefox/28" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX27,&Manufacturer::MOZILLA,&Browser::FIREFOX, 108, "Firefox 27",  { "Firefox/27" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX26,&Manufacturer::MOZILLA,&Browser::FIREFOX, 107, "Firefox 26",  { "Firefox/26" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX25,&Manufacturer::MOZILLA,&Browser::FIREFOX, 106, "Firefox 25",  { "Firefox/25" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX24,&Manufacturer::MOZILLA,&Browser::FIREFOX, 105, "Firefox 24",  { "Firefox/24" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX23,&Manufacturer::MOZILLA,&Browser::FIREFOX, 104, "Firefox 23",  { "Firefox/23" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX22,&Manufacturer::MOZILLA,&Browser::FIREFOX, 103, "Firefox 22",  { "Firefox/22" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX21,&Manufacturer::MOZILLA,&Browser::FIREFOX, 102, "Firefox 21",  { "Firefox/21" }, {"WordPress.com mShots"}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX20,&Manufacturer::MOZILLA,&Browser::FIREFOX, 101, "Firefox 20",  { "Firefox/20" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX19,&Manufacturer::MOZILLA,&Browser::FIREFOX, 100, "Firefox 19",  { "Firefox/19" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX18,&Manufacturer::MOZILLA,&Browser::FIREFOX, 99, "Firefox 18",  { "Firefox/18" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX17,&Manufacturer::MOZILLA,&Browser::FIREFOX, 98, "Firefox 17",  { "Firefox/17" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX16,&Manufacturer::MOZILLA,&Browser::FIREFOX, 97, "Firefox 16",  { "Firefox/16" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX15,&Manufacturer::MOZILLA,&Browser::FIREFOX, 96, "Firefox 15",  { "Firefox/15" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX14,&Manufacturer::MOZILLA,&Browser::FIREFOX, 95, "Firefox 14",  { "Firefox/14" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX13,&Manufacturer::MOZILLA,&Browser::FIREFOX, 94, "Firefox 13",  { "Firefox/13" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX12,&Manufacturer::MOZILLA,&Browser::FIREFOX, 93, "Firefox 12",  { "Firefox/12" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX11,&Manufacturer::MOZILLA,&Browser::FIREFOX, 92, "Firefox 11",  { "Firefox/11" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX10,&Manufacturer::MOZILLA,&Browser::FIREFOX, 91, "Firefox 10",  { "Firefox/10" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX9,&Manufacturer::MOZILLA,&Browser::FIREFOX, 90, "Firefox 9", { "Firefox/9" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX8,&Manufacturer::MOZILLA,&Browser::FIREFOX, 80, "Firefox 8",  { "Firefox/8" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX7,&Manufacturer::MOZILLA,&Browser::FIREFOX, 70, "Firefox 7",  { "Firefox/7" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX6,&Manufacturer::MOZILLA,&Browser::FIREFOX, 60, "Firefox 6",  { "Firefox/6." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX5,&Manufacturer::MOZILLA,&Browser::FIREFOX, 50, "Firefox 5",  { "Firefox/5." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX4,&Manufacturer::MOZILLA,&Browser::FIREFOX, 40, "Firefox 4",  { "Firefox/4." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX3,&Manufacturer::MOZILLA,&Browser::FIREFOX, 30, "Firefox 3",  { "Firefox/3." },  {"Camino", "Flock", "ggpht.com"}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX2,&Manufacturer::MOZILLA,&Browser::FIREFOX, 20, "Firefox 2",  { "Firefox/2." }, {"Camino", "WordPress.com mShots"}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,FIREFOX1_5,&Manufacturer::MOZILLA,&Browser::FIREFOX, 15, "Firefox 1.5", { "Firefox/1.5" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine


ZCENUM_V(Browser,SAFARI,&Manufacturer::APPLE,{}, 1, "Safari", { "Safari" }, { "bot", "preview", "OPR/", "Coast/", "Vivaldi","CFNetwork", "Phantom" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT,
		std::make_shared<SequentialVersionFetcher>(std::initializer_list<VersionFetcher::ptr>{
				std::make_shared<PatternBasedVersionFetcher>("Version\\/(([0-9]+).?([\\w]+)?(.[\\w]+)?)"), // before AppleWebKit
				std::make_shared<VersionFetcherFromMap>(std::regex("AppleWebKit/(\\d+(?:.\\d+){1,2})"), SafariUtils::instance()->getWebKitToSafariVersion())
		})
);
ZCENUM_V(Browser,BLACKBERRY10 ,&Manufacturer::BLACKBERRY,&Browser::SAFARI, 10, "BlackBerry", { "BB10" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::WEBKIT, {});
ZCENUM_V(Browser,MOBILE_SAFARI ,&Manufacturer::APPLE,&Browser::SAFARI, 2, "Mobile Safari", { "Mobile Safari","Mobile/" }, { "bot", "preview", "OPR/", "Coast/", "Vivaldi", "CFNetwork", "FxiOS" }, &BrowserType::MOBILE_BROWSER, &RenderingEngine::WEBKIT, {});// // before Safari
ZCENUM_V(Browser,SILK ,&Manufacturer::AMAZON,&Browser::SAFARI, 15, "Silk", { "Silk/" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("Silk\\/(([0-9]+).?([\\w]+)?(.[\\w]+)?(\\-[\\w]+)?)"));// // http://en.wikipedia.org/wiki/Amazon_Silk
ZCENUM_V(Browser,SAFARI11 ,&Manufacturer::APPLE,&Browser::SAFARI, 12, "Safari 11", { "Version/11" }, { "bot" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// // before AppleWebKit
ZCENUM_V(Browser,SAFARI10 ,&Manufacturer::APPLE,&Browser::SAFARI, 11, "Safari 10",  { "Version/10" },  { "bot" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// // before AppleWebKit
ZCENUM_V(Browser,SAFARI9 ,&Manufacturer::APPLE,&Browser::SAFARI, 9, "Safari 9", { "Version/9" }, { "bot" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// // before AppleWebKit
ZCENUM_V(Browser,SAFARI8 ,&Manufacturer::APPLE,&Browser::SAFARI, 8, "Safari 8",  { "Version/8" },  { "bot" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// // before AppleWebKit
ZCENUM_V(Browser,SAFARI7 ,&Manufacturer::APPLE,&Browser::SAFARI, 7, "Safari 7",  { "Version/7" }, {"bing"}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// // before AppleWebKit
ZCENUM_V(Browser,SAFARI6 ,&Manufacturer::APPLE,&Browser::SAFARI, 6, "Safari 6",  { "Version/6" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// // before AppleWebKit
ZCENUM_V(Browser,SAFARI5 ,&Manufacturer::APPLE,&Browser::SAFARI, 3, "Safari 5",  { "Version/5", "AppleWebKit/533", "AppleWebKit/534" }, {"Google Web Preview"}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// // before AppleWebKit
ZCENUM_V(Browser,SAFARI4 ,&Manufacturer::APPLE,&Browser::SAFARI, 4, "Safari 4",  { "Version/4" },  { "Googlebot-Mobile" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// // before AppleWebKit

/**
 * Opera Coast mobile browser, http://en.wikipedia.org/wiki/Opera_Coast
 */
ZCENUM_V(Browser,COAST,&Manufacturer::OPERA,{}, 500, "Opera", { " Coast/" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("Coast\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,COAST1,&Manufacturer::OPERA,&Browser::COAST, 501, "Opera", { " Coast/1." },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("Coast\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));

ZCENUM_V(Browser,OPERA,&Manufacturer::OPERA,{}, 1, "Opera", { " OPR/", "Opera" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::PRESTO, std::make_shared<PatternBasedVersionFetcher>("[o][p][e]?[r][a]?\\/(([\\d]+).([\\w]+)(.([\\w]+))?(.([\\w]+))?)"));//  // before MSIE
ZCENUM_V(Browser,OPERA_MOBILE,&Manufacturer::OPERA,&Browser::OPERA, 100, "Opera Mobile", { "Mobile Safari" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::BLINK, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));// Another Opera for mobile devices
ZCENUM_V(Browser,OPERA_MINI,&Manufacturer::OPERA,&Browser::OPERA, 20, "Opera Mini", { "Opera Mini" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::PRESTO, {});// Opera for mobile devices
ZCENUM_V(Browser,OPERA51,&Manufacturer::OPERA,&Browser::OPERA, 51, "Opera 51", { "OPR/51." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA50,&Manufacturer::OPERA,&Browser::OPERA, 50, "Opera 50",  { "OPR/50." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA49,&Manufacturer::OPERA,&Browser::OPERA, 49, "Opera 49",  { "OPR/49." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA48,&Manufacturer::OPERA,&Browser::OPERA, 48, "Opera 48",  { "OPR/48." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA47,&Manufacturer::OPERA,&Browser::OPERA, 47, "Opera 47",  { "OPR/47." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA46,&Manufacturer::OPERA,&Browser::OPERA, 46, "Opera 46",  { "OPR/46." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA45,&Manufacturer::OPERA,&Browser::OPERA, 45, "Opera 45",  { "OPR/45." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA44,&Manufacturer::OPERA,&Browser::OPERA, 44, "Opera 44",  { "OPR/44." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA43,&Manufacturer::OPERA,&Browser::OPERA, 43, "Opera 43",  { "OPR/43." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA42,&Manufacturer::OPERA,&Browser::OPERA, 42, "Opera 42",  { "OPR/42." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA34,&Manufacturer::OPERA,&Browser::OPERA, 34, "Opera 34",  { "OPR/34." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA33,&Manufacturer::OPERA,&Browser::OPERA, 33, "Opera 33",  { "OPR/33." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA32,&Manufacturer::OPERA,&Browser::OPERA, 32, "Opera 32",  { "OPR/32." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA31,&Manufacturer::OPERA,&Browser::OPERA, 31, "Opera 31",  { "OPR/31." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA30,&Manufacturer::OPERA,&Browser::OPERA, 30, "Opera 30",  { "OPR/30." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA29,&Manufacturer::OPERA,&Browser::OPERA, 29, "Opera 29",  { "OPR/29." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA28,&Manufacturer::OPERA,&Browser::OPERA, 28, "Opera 28",  { "OPR/28." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA27,&Manufacturer::OPERA,&Browser::OPERA, 27, "Opera 27",  { "OPR/27." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA26,&Manufacturer::OPERA,&Browser::OPERA, 26, "Opera 26",  { "OPR/26." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA25,&Manufacturer::OPERA,&Browser::OPERA, 25, "Opera 25",  { "OPR/25." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA24,&Manufacturer::OPERA,&Browser::OPERA, 24, "Opera 24",  { "OPR/24." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA23,&Manufacturer::OPERA,&Browser::OPERA, 23, "Opera 23",  { "OPR/23." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA20,&Manufacturer::OPERA,&Browser::OPERA, 21, "Opera 20",  { "OPR/20." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA19,&Manufacturer::OPERA,&Browser::OPERA, 19, "Opera 19",  { "OPR/19." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA18,&Manufacturer::OPERA,&Browser::OPERA, 18, "Opera 18",  { "OPR/18." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA17,&Manufacturer::OPERA,&Browser::OPERA, 17, "Opera 17",  { "OPR/17." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA16,&Manufacturer::OPERA,&Browser::OPERA, 16, "Opera 16",  { "OPR/16." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA15,&Manufacturer::OPERA,&Browser::OPERA, 15, "Opera 15",  { "OPR/15." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, std::make_shared<PatternBasedVersionFetcher>("OPR\\/(([\\d]+).([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));
ZCENUM_V(Browser,OPERA12,&Manufacturer::OPERA,&Browser::OPERA, 12, "Opera 12",  { "Opera/12", "Version/12." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::PRESTO, std::make_shared<PatternBasedVersionFetcher>("Version\\/(([\\d]+).([\\w]+))"));
ZCENUM_V(Browser,OPERA11,&Manufacturer::OPERA,&Browser::OPERA, 11, "Opera 11",  { "Version/11." },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::PRESTO, std::make_shared<PatternBasedVersionFetcher>("Version\\/(([\\d]+).([\\w]+))"));
ZCENUM_V(Browser,OPERA10,&Manufacturer::OPERA,&Browser::OPERA, 10, "Opera 10",  { "Opera/9.8" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::PRESTO, std::make_shared<PatternBasedVersionFetcher>("Version\\/(([\\d]+).([\\w]+))"));
ZCENUM_V(Browser,OPERA9,&Manufacturer::OPERA,&Browser::OPERA, 5, "Opera 9", { "Opera/9" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::PRESTO, {});
ZCENUM_V(Browser,KONQUEROR,&Manufacturer::OTHER,{}, 1, "Konqueror", { "Konqueror" }, { "Exabot" }, &BrowserType::WEB_BROWSER, &RenderingEngine::KHTML, std::make_shared<PatternBasedVersionFetcher>("Konqueror\\/(([0-9]+).?([\\w]+)?(-[\\w]+)?)"));

ZCENUM_V(Browser,DOLFIN2,&Manufacturer::SAMSUNG,{}, 1, "Samsung Dolphin 2", { "Dolfin/2" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::WEBKIT, {});// webkit based browser for the bada os

/*
 * Apple WebKit compatible client. Can be a browser or an application with embedded browser using UIWebView.
 */
ZCENUM_V(Browser,APPLE_WEB_KIT,&Manufacturer::APPLE,{}, 50, "Apple WebKit", { "AppleWebKit" }, { "bot", "preview", "OPR/", "Coast/", "Vivaldi", "Phantom" }, &BrowserType::WEB_BROWSER, &RenderingEngine::WEBKIT, {});// Microsoft Entrourage/Outlook 2010 also only identifies itself as AppleWebKit
ZCENUM_V(Browser,APPLE_ITUNES,&Manufacturer::APPLE,&Browser::APPLE_WEB_KIT, 52, "iTunes", { "iTunes" },{}, &BrowserType::APP, &RenderingEngine::WEBKIT, {});// Microsoft Entrourage/Outlook 2010 also only identifies itself as AppleWebKit
ZCENUM_V(Browser,APPLE_APPSTORE,&Manufacturer::APPLE,&Browser::APPLE_WEB_KIT, 53, "App Store", { "MacAppStore" },{}, &BrowserType::APP, &RenderingEngine::WEBKIT, {});// Microsoft Entrourage/Outlook 2010 also only identifies itself as AppleWebKit
ZCENUM_V(Browser,ADOBE_AIR,&Manufacturer::ADOBE,&Browser::APPLE_WEB_KIT, 1, "Adobe AIR application", { "AdobeAIR" },{}, &BrowserType::APP, &RenderingEngine::WEBKIT, {});// Microsoft Entrourage/Outlook 2010 also only identifies itself as AppleWebKit

ZCENUM_V(Browser,LOTUS_NOTES,&Manufacturer::OTHER,{}, 3, "Lotus Notes", { "Lotus-Notes" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::OTHER, std::make_shared<PatternBasedVersionFetcher>("Lotus-Notes\\/(([\\d]+).([\\w]+))"));// // before Mozilla

ZCENUM_V(Browser,CAMINO,&Manufacturer::OTHER,{}, 5, "Camino", { "Camino" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, std::make_shared<PatternBasedVersionFetcher>("Camino\\/(([0-9]+).?([\\w]+)?(.[\\w]+)?)"));// // using Gecko Engine
ZCENUM_V(Browser,CAMINO2,&Manufacturer::OTHER,&Browser::CAMINO, 17, "Camino 2", { "Camino/2" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, {});// // using Gecko Engine

ZCENUM_V(Browser,FLOCK,&Manufacturer::OTHER,{}, 4, "Flock", { "Flock" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, std::make_shared<PatternBasedVersionFetcher>("Flock\\/(([0-9]+).?([\\w]+)?(.[\\w]+)?)"));

/*
	* Thunderbird email client, based on the same Gecko engine Firefox is using.
	*/
ZCENUM_V(Browser,THUNDERBIRD,&Manufacturer::MOZILLA,{}, 110, "Thunderbird", { "Thunderbird" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::GECKO, std::make_shared<PatternBasedVersionFetcher>("Thunderbird\\/(([0-9]+).?([\\w]+)?(.[\\w]+)?(.[\\w]+)?)"));// // using Gecko Engine
ZCENUM_V(Browser,THUNDERBIRD12,&Manufacturer::MOZILLA,&Browser::THUNDERBIRD, 185, "Thunderbird 12", { "Thunderbird/12" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,THUNDERBIRD11,&Manufacturer::MOZILLA,&Browser::THUNDERBIRD, 184, "Thunderbird 11", { "Thunderbird/11" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,THUNDERBIRD10,&Manufacturer::MOZILLA,&Browser::THUNDERBIRD, 183, "Thunderbird 10", { "Thunderbird/10" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,THUNDERBIRD8,&Manufacturer::MOZILLA,&Browser::THUNDERBIRD, 180, "Thunderbird 8", { "Thunderbird/8" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,THUNDERBIRD7,&Manufacturer::MOZILLA,&Browser::THUNDERBIRD, 170, "Thunderbird 7",  { "Thunderbird/7" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,THUNDERBIRD6,&Manufacturer::MOZILLA,&Browser::THUNDERBIRD, 160, "Thunderbird 6",  { "Thunderbird/6" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,THUNDERBIRD3,&Manufacturer::MOZILLA,&Browser::THUNDERBIRD, 130, "Thunderbird 3",  { "Thunderbird/3" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::GECKO, {});// // using Gecko Engine
ZCENUM_V(Browser,THUNDERBIRD2,&Manufacturer::MOZILLA,&Browser::THUNDERBIRD, 120, "Thunderbird 2",  { "Thunderbird/2" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::GECKO, {});// // using Gecko Engine

ZCENUM_V(Browser,VIVALDI,&Manufacturer::OTHER,{}, 108338, "Vivaldi", { "Vivaldi" }, {}, &BrowserType::WEB_BROWSER, &RenderingEngine::BLINK, std::make_shared<PatternBasedVersionFetcher>("Vivaldi/(([\\d]+).([\\d]+).([\\d]+).([\\d]+))"));

ZCENUM_V(Browser,SEAMONKEY,&Manufacturer::OTHER,{}, 15, "SeaMonkey", { "SeaMonkey" },{}, &BrowserType::WEB_BROWSER, &RenderingEngine::GECKO, std::make_shared<PatternBasedVersionFetcher>("SeaMonkey\\/(([0-9]+).?([\\w]+)?(.[\\w]+)?)"));// using Gecko Engine

ZCENUM_V(Browser,BOT,&Manufacturer::OTHER,{}, 12, "Robot/Spider", { "Googlebot", "Mediapartners-Google", "Web Preview", "bot", "Applebot" , "spider", "crawler", "Feedfetcher", "Slurp", "Twiceler", "Nutch", "BecomeBot",
	"bingbot", "BingPreview", "Google Web Preview", "WordPress.com mShots", "Seznam", "facebookexternalhit" , "YandexMarket", "Teoma", "ThumbSniper", "Phantom",
	"Go-http-client", "Java/", "python-requests", "YandexBot", "AdsBot-Google", "AhrefsBot" },{}, &BrowserType::ROBOT, &RenderingEngine::OTHER, {});
ZCENUM_V(Browser,BOT_MOBILE,&Manufacturer::OTHER,&Browser::BOT, 20, "Mobile Robot/Spider", { "Googlebot-Mobile" },{}, &BrowserType::ROBOT, &RenderingEngine::OTHER, {});

ZCENUM_V(Browser,MOZILLA,&Manufacturer::MOZILLA,{}, 1, "Mozilla", { "Mozilla", "Moozilla" }, { "ggpht.com" }, &BrowserType::WEB_BROWSER, &RenderingEngine::OTHER, {});// rest of the mozilla browsers

ZCENUM_V(Browser,CFNETWORK,&Manufacturer::OTHER,{}, 6, "CFNetwork", { "CFNetwork" },{}, &BrowserType::UNKNOWN, &RenderingEngine::OTHER, std::make_shared<PatternBasedVersionFetcher>("CFNetwork/(([\\d]+)(?:.([\\d]))?(?:.([\\d]+))?)"));// Mac OS X cocoa library

ZCENUM_V(Browser,EUDORA,&Manufacturer::OTHER,{}, 7, "Eudora", { "Eudora", "EUDORA" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::OTHER, {});// // email client by Qualcomm

ZCENUM_V(Browser,POCOMAIL ,&Manufacturer::OTHER,{}, 8, "PocoMail", { "PocoMail" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::OTHER, {});

ZCENUM_V(Browser,THEBAT ,&Manufacturer::OTHER,{}, 9, "The Bat!", { "The Bat" },{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::OTHER, {});// Email Client

ZCENUM_V(Browser,NETFRONT ,&Manufacturer::OTHER,{}, 10, "NetFront", { "NetFront" },{}, &BrowserType::MOBILE_BROWSER, &RenderingEngine::OTHER, {});// mobile device browser

ZCENUM_V(Browser,EVOLUTION ,&Manufacturer::OTHER,{}, 11, "Evolution", {"CamelHttpStream"},{}, &BrowserType::EMAIL_CLIENT, &RenderingEngine::OTHER, {});// http://www.go-evolution.org/Camel.Stream

ZCENUM_V(Browser,LYNX ,&Manufacturer::OTHER,{}, 13, "Lynx", { "Lynx" },{}, &BrowserType::TEXT_BROWSER, &RenderingEngine::OTHER, std::make_shared<PatternBasedVersionFetcher>("Lynx\\/(([0-9]+).([\\d]+).?([\\w-+]+)?.?([\\w-+]+)?)"));

ZCENUM_V(Browser,DOWNLOAD ,&Manufacturer::OTHER,{}, 16, "Downloading Tool", { "cURL","wget", "ggpht.com", "Apache-HttpClient" },{}, &BrowserType::TOOL, &RenderingEngine::OTHER, {});

ZCENUM_V(Browser,UNKNOWN,&Manufacturer::OTHER,{}, 14, "Unknown", {},{}, &BrowserType::UNKNOWN, &RenderingEngine::OTHER, {});

