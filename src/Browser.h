#pragma once

#include "BaseEnum.hpp"

#include "Manufacturer.h"
#include "BrowserType.h"
#include "RenderingEngine.h"
#include "VersionFetcher.h"
#include "Utils.h"

#include <string>
#include <vector>
#include <regex>


/**
 * Enum constants for most common browsers, including e-mail clients and bots.
 * @author zcmaye
 *
 */
//struct Browser 
ZCENUM_CLASS(Browser)
{
	ZCENUM_INIT(Browser);
	friend  class UserAgent;
private:
	/**
	 * Outlook email client
	 */
	ZCENUM_K(Browser,OUTLOOK);// (Manufacturer::MICROSOFT, nullptr, 100, "Outlook", new const std::vector<std::string>& { "MSOffice" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.WORD, new PatternBasedVersionFetcher("MSOffice (([0-9]+))")), // before IE7
	/**
	 * Microsoft Outlook 2007 identifies itself as MSIE7 but uses the html rendering engine of Word 2007.
	 * Example user agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0; SLCC1; .NET CLR 2.0.50727; .NET CLR 3.0.04506; .NET CLR 1.1.4322; MSOffice 12)
	 */
	ZCENUM_K(Browser,OUTLOOK2007);// (Manufacturer.MICROSOFT, Browser::OUTLOOK, 107, "Outlook 2007", new const std::vector<std::string>& { "MSOffice 12" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.WORD, null), // before IE7
	ZCENUM_K(Browser,OUTLOOK2013);// (Manufacturer.MICROSOFT, Browser::OUTLOOK, 109, "Outlook 2013", new const std::vector<std::string>& { "Microsoft Outlook 15" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.WORD, null), // before IE7
	/**
	 * Outlook 2010 is still using the rendering engine of Word. http://www.fixoutlook.org
	 */
	ZCENUM_K(Browser,OUTLOOK2010);// (Manufacturer.MICROSOFT, Browser::OUTLOOK, 108, "Outlook 2010", new const std::vector<std::string>& { "MSOffice 14", "Microsoft Outlook 14" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.WORD, null), // before IE7

	/**
	 * Family of Internet Explorer browsers
	 */
	ZCENUM_K(Browser,IE);// (Manufacturer.MICROSOFT, null, 1, "Internet Explorer", new const std::vector<std::string>& { "MSIE", "Trident", "IE " }, new const std::vector<std::string>& { "BingPreview", "Xbox", "Xbox One" }, BrowserType.WEB_BROWSER, RenderingEngine.TRIDENT, new PatternBasedVersionFetcher("MSIE (([\\d]+)\\.([\\w]+))")), // before Mozilla
	/**
	 * Since version 7 Outlook Express is identifying itself. By detecting Outlook Express we can not
	 * identify the Internet Explorer version which is probably used for the rendering.
	 * Obviously this product is now called Windows Live Mail Desktop or just Windows Live Mail.
	 */
	ZCENUM_K(Browser,OUTLOOK_EXPRESS7);// (Manufacturer.MICROSOFT, Browser::IE, 110, "Windows Live Mail", new const std::vector<std::string>& { "Outlook-Express/7.0" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.TRIDENT, null), // before IE7, previously known as Outlook Express. First released in 2006, offered with different m_name later
	/**
	 * Since 2007 the mobile edition of Internet Explorer identifies itself as IEMobile in the user-agent.
	 * If previous versions have to be detected, use the operating system information as well.
	 */
	ZCENUM_K(Browser,IEMOBILE11);//(		Manufacturer.MICROSOFT, Browser::IE, 125, "IE Mobile 11", new const std::vector<std::string>&  { "IEMobile/11" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.TRIDENT, new PatternBasedVersionFetcher("(?:Trident\\/7|IE)(?:\\.[0-9]*;)?(?:.*rv:| )(([0-9]+)\\.?([0-9]+))") ), // before Mozilla
	ZCENUM_K(Browser,IEMOBILE10);//(		Manufacturer.MICROSOFT, Browser::IE, 124, "IE Mobile 10", new const std::vector<std::string>&  { "IEMobile/10" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.TRIDENT, null), // before MSIE strings
	ZCENUM_K(Browser,IEMOBILE9);//(		Manufacturer.MICROSOFT, Browser::IE, 123, "IE Mobile 9", new const std::vector<std::string>&  { "IEMobile/9" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.TRIDENT, null), // before MSIE strings
	ZCENUM_K(Browser,IEMOBILE7);//(		Manufacturer.MICROSOFT, Browser::IE, 121, "IE Mobile 7", new const std::vector<std::string>&  { "IEMobile 7" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.TRIDENT, null), // before MSIE strings
	ZCENUM_K(Browser,IEMOBILE6);//(		Manufacturer.MICROSOFT, Browser::IE, 120, "IE Mobile 6", new const std::vector<std::string>&  { "IEMobile 6" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.TRIDENT, null), // before MSIE
	ZCENUM_K(Browser,IE_XBOX);// (Manufacturer.MICROSOFT, Browser::IE, 360, "Xbox", new const std::vector<std::string>& { "xbox" }, new const std::vector<std::string>& {}, BrowserType.WEB_BROWSER, RenderingEngine.TRIDENT, null),
	ZCENUM_K(Browser,IE11);//(			Manufacturer.MICROSOFT, Browser::IE, 95, "Internet Explorer 11", new const std::vector<std::string>&  { "Trident/7", "IE 11." }, new const std::vector<std::string>&  {"MSIE 7", "BingPreview"}, BrowserType.WEB_BROWSER, RenderingEngine.TRIDENT, new PatternBasedVersionFetcher("(?:Trident\\/7|IE)(?:\\.[0-9]*;)?(?:.*rv:| )(([0-9]+)\\.?([0-9]+))") ),   // before Mozilla
	ZCENUM_K(Browser,IE10);//(			Manufacturer.MICROSOFT, Browser::IE, 92, "Internet Explorer 10", new const std::vector<std::string>&  { "MSIE 10" }, null, BrowserType.WEB_BROWSER, RenderingEngine.TRIDENT, null ),   // before MSIE
	ZCENUM_K(Browser,IE9);//(			Manufacturer.MICROSOFT, Browser::IE, 90, "Internet Explorer 9", new const std::vector<std::string>&  { "MSIE 9" }, null, BrowserType.WEB_BROWSER, RenderingEngine.TRIDENT, null ),   // before MSIE
	ZCENUM_K(Browser,IE8);//(			Manufacturer.MICROSOFT, Browser::IE, 80, "Internet Explorer 8", new const std::vector<std::string>&  { "MSIE 8" }, null, BrowserType.WEB_BROWSER, RenderingEngine.TRIDENT, null ),   // before MSIE
	ZCENUM_K(Browser,IE7);//(			Manufacturer.MICROSOFT, Browser::IE, 70, "Internet Explorer 7", new const std::vector<std::string>&  { "MSIE 7" }, null, BrowserType.WEB_BROWSER, RenderingEngine.TRIDENT, null),   // before MSIE
	ZCENUM_K(Browser,IE6);//(			Manufacturer.MICROSOFT, Browser::IE, 60, "Internet Explorer 6", new const std::vector<std::string>&  { "MSIE 6" }, null, BrowserType.WEB_BROWSER, RenderingEngine.TRIDENT, null ),   // before MSIE
	ZCENUM_K(Browser,IE5_5);//(			Manufacturer.MICROSOFT, Browser::IE, 55, "Internet Explorer 5.5", new const std::vector<std::string>&  { "MSIE 5.5" }, null, BrowserType.WEB_BROWSER, RenderingEngine.TRIDENT, null), // before MSIE
	ZCENUM_K(Browser,IE5);//(			Manufacturer.MICROSOFT, Browser::IE, 50, "Internet Explorer 5", new const std::vector<std::string>&  { "MSIE 5" }, null, BrowserType.WEB_BROWSER, RenderingEngine.TRIDENT, null ), // before MSIE

	/**
	 * Family of Microsoft Edge browsers. Pretends to be Chrome and claims to be webkit compatible.
	 * Numbering used here is actually the rendering engine version, not the displayed edge version.
	 * For instance 14.14332 is Edge 37 while 14.14342 is Edge 38. User agent only provides the version of the rendering engine.
	 * @see <a href="https://en.wikipedia.org/wiki/Microsoft_Edge#Release_history">Microsoft Edge release history</a>
	 */
	ZCENUM_K(Browser,EDGE);// (Manufacturer.MICROSOFT, null, 300, "Microsoft Edge", new const std::vector<std::string>& { "Edge" }, null, BrowserType.WEB_BROWSER, RenderingEngine.EDGE_HTML, new PatternBasedVersionFetcher("(?:Edge\\/(([0-9]+)\\.([0-9]*)))")),
	ZCENUM_K(Browser,EDGE_MOBILE);//(	Manufacturer.MICROSOFT, Browser::EDGE, 304, "Microsoft Edge Mobile", new const std::vector<std::string>&  {"Mobile Safari"}, null, BrowserType.MOBILE_BROWSER, RenderingEngine.EDGE_HTML, null ),
	ZCENUM_K(Browser,EDGE_MOBILE15);//(Manufacturer.MICROSOFT, Browser::EDGE_MOBILE, 310, "Microsoft Edge Mobile (layout engine 15)", new const std::vector<std::string>&  {"Edge/15"}, null, BrowserType.MOBILE_BROWSER, RenderingEngine.EDGE_HTML, null ),
	ZCENUM_K(Browser,EDGE_MOBILE14);//(Manufacturer.MICROSOFT, Browser::EDGE_MOBILE, 307, "Microsoft Edge Mobile (layout engine 14)", new const std::vector<std::string>&  {"Edge/14"}, null, BrowserType.MOBILE_BROWSER, RenderingEngine.EDGE_HTML, null ),
	ZCENUM_K(Browser,EDGE_MOBILE13);//(Manufacturer.MICROSOFT, Browser::EDGE_MOBILE, 308, "Microsoft Edge Mobile (layout engine 13)", new const std::vector<std::string>&  {"Edge/13"}, null, BrowserType.MOBILE_BROWSER, RenderingEngine.EDGE_HTML, null ),
	ZCENUM_K(Browser,EDGE_MOBILE12);//(Manufacturer.MICROSOFT, Browser::EDGE_MOBILE, 302, "Microsoft Edge Mobile (layout engine 12)", new const std::vector<std::string>&  {"Edge/12"}, null, BrowserType.MOBILE_BROWSER, RenderingEngine.EDGE_HTML, null ),
	ZCENUM_K(Browser,EDGE16);// (Manufacturer.MICROSOFT, Browser::EDGE, 312, "Microsoft Edge (layout engine 16)", new const std::vector<std::string>& { "Edge/16" }, new const std::vector<std::string>& { "Mobile" }, BrowserType.WEB_BROWSER, RenderingEngine.EDGE_HTML, null),
	ZCENUM_K(Browser,EDGE15);// (		Manufacturer.MICROSOFT, Browser::EDGE, 309, "Microsoft Edge (layout engine 15)", new const std::vector<std::string>&  {"Edge/15"}, new const std::vector<std::string>&  {"Mobile"}, BrowserType.WEB_BROWSER, RenderingEngine.EDGE_HTML, null ),
	ZCENUM_K(Browser,EDGE14);// (		Manufacturer.MICROSOFT, Browser::EDGE, 305, "Microsoft Edge (layout engine 14)", new const std::vector<std::string>&  {"Edge/14"}, new const std::vector<std::string>&  {"Mobile"}, BrowserType.WEB_BROWSER, RenderingEngine.EDGE_HTML, null ),
	ZCENUM_K(Browser,EDGE13);// (		Manufacturer.MICROSOFT, Browser::EDGE, 303, "Microsoft Edge (layout engine 13)", new const std::vector<std::string>&  {"Edge/13"}, new const std::vector<std::string>&  {"Mobile"}, BrowserType.WEB_BROWSER, RenderingEngine.EDGE_HTML, null ),
	ZCENUM_K(Browser,EDGE12);// (		Manufacturer.MICROSOFT, Browser::EDGE, 301, "Microsoft Edge (layout engine 12)", new const std::vector<std::string>&  {"Edge/12"}, new const std::vector<std::string>&  {"Mobile"}, BrowserType.WEB_BROWSER, RenderingEngine.EDGE_HTML, null ),

	/**
	 * Google Chrome browser
	 */
	ZCENUM_K(Browser,CHROME);// (Manufacturer.GOOGLE, null, 1, "Chrome", new const std::vector<std::string>& { "Chrome", "CrMo", "CriOS" }, new const std::vector<std::string>& { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("Chrome\\/(([0-9]+)\\.?([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")), // before Mozilla
	ZCENUM_K(Browser,CHROME_MOBILE);// (Manufacturer.GOOGLE, Browser::CHROME, 100, "Chrome Mobile", new const std::vector<std::string>& { "CrMo","CriOS", "Mobile Safari" }, new const std::vector<std::string>& { "OPR/" }, BrowserType.MOBILE_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("(?:CriOS|CrMo|Chrome)\\/(([0-9]+)\\.?([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,CHROME65);// (Manufacturer.GOOGLE, Browser::CHROME, 71, "Chrome 65", new const std::vector<std::string>& { "Chrome/65" }, new const std::vector<std::string>& { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null), // before Mozilla
	ZCENUM_K(Browser,CHROME64);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 70, "Chrome 64", new const std::vector<std::string>&  { "Chrome/64" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME63);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 69, "Chrome 63", new const std::vector<std::string>&  { "Chrome/63" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME62);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 68, "Chrome 62", new const std::vector<std::string>&  { "Chrome/62" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME61);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 67, "Chrome 61", new const std::vector<std::string>&  { "Chrome/61" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME60);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 66, "Chrome 60", new const std::vector<std::string>&  { "Chrome/60" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME59);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 65, "Chrome 59", new const std::vector<std::string>&  { "Chrome/59" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME58);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 64, "Chrome 58", new const std::vector<std::string>&  { "Chrome/58" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME57);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 63, "Chrome 57", new const std::vector<std::string>&  { "Chrome/57" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME56);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 62, "Chrome 56", new const std::vector<std::string>&  { "Chrome/56" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME55);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 61, "Chrome 55", new const std::vector<std::string>&  { "Chrome/55" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME54);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 60, "Chrome 54", new const std::vector<std::string>&  { "Chrome/54" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME53);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 59, "Chrome 53", new const std::vector<std::string>&  { "Chrome/53" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME52);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 58, "Chrome 52", new const std::vector<std::string>&  { "Chrome/52" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME51);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 57, "Chrome 51", new const std::vector<std::string>&  { "Chrome/51" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME50);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 56, "Chrome 50", new const std::vector<std::string>&  { "Chrome/50" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME49);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 55, "Chrome 49", new const std::vector<std::string>&  { "Chrome/49" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME48);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 53, "Chrome 48", new const std::vector<std::string>&  { "Chrome/48" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME47);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 52, "Chrome 47", new const std::vector<std::string>&  { "Chrome/47" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME46);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 51, "Chrome 46", new const std::vector<std::string>&  { "Chrome/46" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME45);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 50, "Chrome 45", new const std::vector<std::string>&  { "Chrome/45" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME44);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 49, "Chrome 44", new const std::vector<std::string>&  { "Chrome/44" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME43);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 48, "Chrome 43", new const std::vector<std::string>&  { "Chrome/43" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME42);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 47, "Chrome 42", new const std::vector<std::string>&  { "Chrome/42" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME41);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 46, "Chrome 41", new const std::vector<std::string>&  { "Chrome/41" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME40);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 45, "Chrome 40", new const std::vector<std::string>&  { "Chrome/40" }, new const std::vector<std::string>&  { "OPR/", "Web Preview", "Vivaldi" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME39);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 44, "Chrome 39", new const std::vector<std::string>&  { "Chrome/39" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME38);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 43, "Chrome 38", new const std::vector<std::string>&  { "Chrome/38" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME37);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 42, "Chrome 37", new const std::vector<std::string>&  { "Chrome/37" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME36);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 41, "Chrome 36", new const std::vector<std::string>&  { "Chrome/36" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME35);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 40, "Chrome 35", new const std::vector<std::string>&  { "Chrome/35" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME34);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 39, "Chrome 34", new const std::vector<std::string>&  { "Chrome/34" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME33);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 38, "Chrome 33", new const std::vector<std::string>&  { "Chrome/33" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME32);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 37, "Chrome 32", new const std::vector<std::string>&  { "Chrome/32" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME31);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 36, "Chrome 31", new const std::vector<std::string>&  { "Chrome/31" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME30);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 35, "Chrome 30", new const std::vector<std::string>&  { "Chrome/30" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME29);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 34, "Chrome 29", new const std::vector<std::string>&  { "Chrome/29" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME28);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 33, "Chrome 28", new const std::vector<std::string>&  { "Chrome/28" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME27);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 32, "Chrome 27", new const std::vector<std::string>&  { "Chrome/27" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME26);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 31, "Chrome 26", new const std::vector<std::string>&  { "Chrome/26" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME25);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 30, "Chrome 25", new const std::vector<std::string>&  { "Chrome/25" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME24);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 29, "Chrome 24", new const std::vector<std::string>&  { "Chrome/24" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME23);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 28, "Chrome 23", new const std::vector<std::string>&  { "Chrome/23" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME22);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 27, "Chrome 22", new const std::vector<std::string>&  { "Chrome/22" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME21);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 26, "Chrome 21", new const std::vector<std::string>&  { "Chrome/21" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME20);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 25, "Chrome 20", new const std::vector<std::string>&  { "Chrome/20" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME19);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 24, "Chrome 19", new const std::vector<std::string>&  { "Chrome/19" }, new const std::vector<std::string>&  { "OPR/", "Web Preview" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME18);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 23, "Chrome 18", new const std::vector<std::string>&  { "Chrome/18" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME17);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 22, "Chrome 17", new const std::vector<std::string>&  { "Chrome/17" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME16);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 21, "Chrome 16", new const std::vector<std::string>&  { "Chrome/16" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME15);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 20, "Chrome 15", new const std::vector<std::string>&  { "Chrome/15" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME14);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 19, "Chrome 14", new const std::vector<std::string>&  { "Chrome/14" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME13);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 18, "Chrome 13", new const std::vector<std::string>&  { "Chrome/13" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME12);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 17, "Chrome 12", new const std::vector<std::string>&  { "Chrome/12" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME11);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 16, "Chrome 11", new const std::vector<std::string>&  { "Chrome/11" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME10);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 15, "Chrome 10", new const std::vector<std::string>&  { "Chrome/10" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla
	ZCENUM_K(Browser,CHROME9);// (Manufacturer.GOOGLE, Browser::CHROME, 10, "Chrome 9", new const std::vector<std::string>& { "Chrome/9" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null), // before Mozilla
	ZCENUM_K(Browser,CHROME8);// ( 		Manufacturer.GOOGLE, Browser::CHROME, 5, "Chrome 8", new const std::vector<std::string>&  { "Chrome/8" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ), // before Mozilla

	ZCENUM_K(Browser,OMNIWEB);// (Manufacturer.OTHER, null, 2, "Omniweb", new const std::vector<std::string>& { "OmniWeb" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null), //

	ZCENUM_K(Browser,FIREFOX);// (		Manufacturer.MOZILLA, null, 10, "Firefox", new const std::vector<std::string>&  { "Firefox", "FxiOS" }, new const std::vector<std::string>&  {"camino", "flock", "ggpht.com", "WordPress.com mShots"}, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, new PatternBasedVersionFetcher("Firefox\\/(([0-9]+)\\.?([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX3MOBILE);// (Manufacturer.MOZILLA, Browser::FIREFOX, 31, "Firefox 3 Mobile", new const std::vector<std::string>& { "Firefox/3.5 Maemo" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.GECKO, null),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX_MOBILE);// (	Manufacturer.MOZILLA, Browser::FIREFOX, 200, "Firefox Mobile", new const std::vector<std::string>&  { "Mobile" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX_MOBILE23);//(Manufacturer.MOZILLA, FIREFOX_MOBILE, 223, "Firefox Mobile 23", new const std::vector<std::string>& { "Firefox/23" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.GECKO, null),  // using Gecko Engine
	/**
	 * Firefox for iOS devices. This Firefox version is using webkit instead of gecko rendering engine.
	 */
	ZCENUM_K(Browser,FIREFOX_MOBILE_IOS);// (Manufacturer.MOZILLA, FIREFOX_MOBILE, 224, "Firefox Mobile (iOS)", new const std::vector<std::string>& { "FxiOS" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.WEBKIT, null),
	ZCENUM_K(Browser,FIREFOX59);// (Manufacturer.MOZILLA, Browser::FIREFOX, 238, "Firefox 59", new const std::vector<std::string>& { "Firefox/59" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX58);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 237, "Firefox 58", new const std::vector<std::string>&  { "Firefox/58" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX57);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 236, "Firefox 57", new const std::vector<std::string>&  { "Firefox/57" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX56);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 235, "Firefox 56", new const std::vector<std::string>&  { "Firefox/56" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX55);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 234, "Firefox 55", new const std::vector<std::string>&  { "Firefox/55" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX54);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 233, "Firefox 54", new const std::vector<std::string>&  { "Firefox/54" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX53);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 232, "Firefox 53", new const std::vector<std::string>&  { "Firefox/53" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX52);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 231, "Firefox 52", new const std::vector<std::string>&  { "Firefox/52" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX51);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 230, "Firefox 51", new const std::vector<std::string>&  { "Firefox/51" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX50);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 229, "Firefox 50", new const std::vector<std::string>&  { "Firefox/50" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX49);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 228, "Firefox 49", new const std::vector<std::string>&  { "Firefox/49" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX48);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 227, "Firefox 48", new const std::vector<std::string>&  { "Firefox/48" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX47);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 226, "Firefox 47", new const std::vector<std::string>&  { "Firefox/47" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX46);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 225, "Firefox 46", new const std::vector<std::string>&  { "Firefox/46" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX45);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 222, "Firefox 45", new const std::vector<std::string>&  { "Firefox/45" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX44);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 221, "Firefox 44", new const std::vector<std::string>&  { "Firefox/44" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX43);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 220, "Firefox 43", new const std::vector<std::string>&  { "Firefox/43" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX42);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 219, "Firefox 42", new const std::vector<std::string>&  { "Firefox/42" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX41);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 218, "Firefox 41", new const std::vector<std::string>&  { "Firefox/41" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX40);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 217, "Firefox 40", new const std::vector<std::string>&  { "Firefox/40" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX39);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 216, "Firefox 39", new const std::vector<std::string>&  { "Firefox/39" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX38);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 215, "Firefox 38", new const std::vector<std::string>&  { "Firefox/38" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX37);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 214, "Firefox 37", new const std::vector<std::string>&  { "Firefox/37" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX36);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 213, "Firefox 36", new const std::vector<std::string>&  { "Firefox/36" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX35);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 212, "Firefox 35", new const std::vector<std::string>&  { "Firefox/35" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX34);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 211, "Firefox 34", new const std::vector<std::string>&  { "Firefox/34" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX33);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 210, "Firefox 33", new const std::vector<std::string>&  { "Firefox/33" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX32);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 109, "Firefox 32", new const std::vector<std::string>&  { "Firefox/32" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX31);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 310, "Firefox 31", new const std::vector<std::string>&  { "Firefox/31" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX30);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 300, "Firefox 30", new const std::vector<std::string>&  { "Firefox/30" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX29);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 290, "Firefox 29", new const std::vector<std::string>&  { "Firefox/29" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX28);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 280, "Firefox 28", new const std::vector<std::string>&  { "Firefox/28" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX27);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 108, "Firefox 27", new const std::vector<std::string>&  { "Firefox/27" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX26);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 107, "Firefox 26", new const std::vector<std::string>&  { "Firefox/26" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX25);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 106, "Firefox 25", new const std::vector<std::string>&  { "Firefox/25" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX24);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 105, "Firefox 24", new const std::vector<std::string>&  { "Firefox/24" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX23);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 104, "Firefox 23", new const std::vector<std::string>&  { "Firefox/23" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX22);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 103, "Firefox 22", new const std::vector<std::string>&  { "Firefox/22" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX21);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 102, "Firefox 21", new const std::vector<std::string>&  { "Firefox/21" }, new const std::vector<std::string>& {"WordPress.com mShots"}, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX20);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 101, "Firefox 20", new const std::vector<std::string>&  { "Firefox/20" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX19);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 100, "Firefox 19", new const std::vector<std::string>&  { "Firefox/19" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX18);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 99, "Firefox 18", new const std::vector<std::string>&  { "Firefox/18" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX17);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 98, "Firefox 17", new const std::vector<std::string>&  { "Firefox/17" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX16);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 97, "Firefox 16", new const std::vector<std::string>&  { "Firefox/16" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX15);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 96, "Firefox 15", new const std::vector<std::string>&  { "Firefox/15" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX14);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 95, "Firefox 14", new const std::vector<std::string>&  { "Firefox/14" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX13);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 94, "Firefox 13", new const std::vector<std::string>&  { "Firefox/13" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX12);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 93, "Firefox 12", new const std::vector<std::string>&  { "Firefox/12" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX11);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 92, "Firefox 11", new const std::vector<std::string>&  { "Firefox/11" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX10);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 91, "Firefox 10", new const std::vector<std::string>&  { "Firefox/10" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX9);// (Manufacturer.MOZILLA, Browser::FIREFOX, 90, "Firefox 9", new const std::vector<std::string>& { "Firefox/9" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX8);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 80, "Firefox 8", new const std::vector<std::string>&  { "Firefox/8" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX7);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 70, "Firefox 7", new const std::vector<std::string>&  { "Firefox/7" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX6);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 60, "Firefox 6", new const std::vector<std::string>&  { "Firefox/6." }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX5);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 50, "Firefox 5", new const std::vector<std::string>&  { "Firefox/5." }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX4);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 40, "Firefox 4", new const std::vector<std::string>&  { "Firefox/4." }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX3);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 30, "Firefox 3", new const std::vector<std::string>&  { "Firefox/3." }, new const std::vector<std::string>&  {"Camino", "Flock", "ggpht.com"}, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX2);// (		Manufacturer.MOZILLA, Browser::FIREFOX, 20, "Firefox 2", new const std::vector<std::string>&  { "Firefox/2." }, new const std::vector<std::string>& {"Camino", "WordPress.com mShots"}, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,FIREFOX1_5);// (Manufacturer.MOZILLA, Browser::FIREFOX, 15, "Firefox 1.5", new const std::vector<std::string>& { "Firefox/1.5" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null),  // using Gecko Engine


	ZCENUM_K(Browser,SAFARI);// (Manufacturer.APPLE, null, 1, "Safari", new const std::vector<std::string>& { "Safari" }, new const std::vector<std::string>& { "bot", "preview", "OPR/", "Coast/", "Vivaldi","CFNetwork", "Phantom" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT,
	//		new SequentialVersionFetcher(
	//				new PatternBasedVersionFetcher("Version\\/(([0-9]+)\\.?([\\w]+)?(\\.[\\w]+)?)"), // before AppleWebKit
	//				new VersionFetcherFromMap(Pattern.compile("AppleWebKit/(\\d+(?:.\\d+){1,2})"), SafariUtils.getWebKitToSafariVersion())
	//		) 
	//	),  
	ZCENUM_K(Browser,BLACKBERRY10);// (Manufacturer.BLACKBERRY, Browser::SAFARI, 10, "BlackBerry", new const std::vector<std::string>& { "BB10" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.WEBKIT, null),
	ZCENUM_K(Browser,MOBILE_SAFARI);// (Manufacturer.APPLE, Browser::SAFARI, 2, "Mobile Safari", new const std::vector<std::string>& { "Mobile Safari","Mobile/" }, new const std::vector<std::string>& { "bot", "preview", "OPR/", "Coast/", "Vivaldi", "CFNetwork", "FxiOS" }, BrowserType.MOBILE_BROWSER, RenderingEngine.WEBKIT, null),  // before Safari
	ZCENUM_K(Browser,SILK);// (Manufacturer.AMAZON, Browser::SAFARI, 15, "Silk", new const std::vector<std::string>& { "Silk/" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("Silk\\/(([0-9]+)\\.?([\\w]+)?(\\.[\\w]+)?(\\-[\\w]+)?)")),  // http://en.wikipedia.org/wiki/Amazon_Silk
	ZCENUM_K(Browser,SAFARI11);// (Manufacturer.APPLE, Browser::SAFARI, 12, "Safari 11", new const std::vector<std::string>& { "Version/11" }, new const std::vector<std::string>& { "bot" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null),  // before AppleWebKit
	ZCENUM_K(Browser,SAFARI10);// (		Manufacturer.APPLE, Browser::SAFARI, 11, "Safari 10", new const std::vector<std::string>&  { "Version/10" }, new const std::vector<std::string>&  { "bot" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ),  // before AppleWebKit
	ZCENUM_K(Browser,SAFARI9);// (Manufacturer.APPLE, Browser::SAFARI, 9, "Safari 9", new const std::vector<std::string>& { "Version/9" }, new const std::vector<std::string>& { "bot" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null),  // before AppleWebKit
	ZCENUM_K(Browser,SAFARI8);// (		Manufacturer.APPLE, Browser::SAFARI, 8, "Safari 8", new const std::vector<std::string>&  { "Version/8" }, new const std::vector<std::string>&  { "bot" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ),  // before AppleWebKit
	ZCENUM_K(Browser,SAFARI7);// (		Manufacturer.APPLE, Browser::SAFARI, 7, "Safari 7", new const std::vector<std::string>&  { "Version/7" }, new const std::vector<std::string>& {"bing"}, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ),  // before AppleWebKit
	ZCENUM_K(Browser,SAFARI6);// (		Manufacturer.APPLE, Browser::SAFARI, 6, "Safari 6", new const std::vector<std::string>&  { "Version/6" }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ),  // before AppleWebKit
	ZCENUM_K(Browser,SAFARI5);// (		Manufacturer.APPLE, Browser::SAFARI, 3, "Safari 5", new const std::vector<std::string>&  { "Version/5", "AppleWebKit/533", "AppleWebKit/534" }, new const std::vector<std::string>& {"Google Web Preview"}, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ),  // before AppleWebKit
	ZCENUM_K(Browser,SAFARI4);// (		Manufacturer.APPLE, Browser::SAFARI, 4, "Safari 4", new const std::vector<std::string>&  { "Version/4" }, new const std::vector<std::string>&  { "Googlebot-Mobile" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null ),  // before AppleWebKit

	/**
	 * Opera Coast mobile browser, http://en.wikipedia.org/wiki/Opera_Coast
	 */
	ZCENUM_K(Browser,COAST);// (Manufacturer.OPERA, null, 500, "Opera", new const std::vector<std::string>& { " Coast/" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("Coast\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,COAST1);// (Manufacturer.OPERA, Browser::COAST, 501, "Opera", new const std::vector<std::string>& { " Coast/1." }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("Coast\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),

	ZCENUM_K(Browser,OPERA);// (Manufacturer.OPERA, null, 1, "Opera", new const std::vector<std::string>& { " OPR/", "Opera" }, null, BrowserType.WEB_BROWSER, RenderingEngine.PRESTO, new PatternBasedVersionFetcher("[o][p][e]?[r][a]?\\/(([\\d]+)\\.([\\w]+)(\\.([\\w]+))?(\\.([\\w]+))?)")),   // before MSIE
	ZCENUM_K(Browser,OPERA_MOBILE);// (Manufacturer.OPERA, Browser::OPERA, 100, "Opera Mobile", new const std::vector<std::string>& { "Mobile Safari" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.BLINK, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")), // Another Opera for mobile devices
	ZCENUM_K(Browser,OPERA_MINI);// (Manufacturer.OPERA, Browser::OPERA, 20, "Opera Mini", new const std::vector<std::string>& { "Opera Mini" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.PRESTO, null), // Opera for mobile devices
	ZCENUM_K(Browser,OPERA51);// (Manufacturer.OPERA, Browser::OPERA, 51, "Opera 51", new const std::vector<std::string>& { "OPR/51." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA50);// (		Manufacturer.OPERA, Browser::OPERA, 50, "Opera 50", new const std::vector<std::string>&  { "OPR/50." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA49);// (		Manufacturer.OPERA, Browser::OPERA, 49, "Opera 49", new const std::vector<std::string>&  { "OPR/49." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA48);// (		Manufacturer.OPERA, Browser::OPERA, 48, "Opera 48", new const std::vector<std::string>&  { "OPR/48." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA47);// (		Manufacturer.OPERA, Browser::OPERA, 47, "Opera 47", new const std::vector<std::string>&  { "OPR/47." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA46);// (		Manufacturer.OPERA, Browser::OPERA, 46, "Opera 46", new const std::vector<std::string>&  { "OPR/46." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA45);// (		Manufacturer.OPERA, Browser::OPERA, 45, "Opera 45", new const std::vector<std::string>&  { "OPR/45." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA44);// (		Manufacturer.OPERA, Browser::OPERA, 44, "Opera 44", new const std::vector<std::string>&  { "OPR/44." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA43);// (		Manufacturer.OPERA, Browser::OPERA, 43, "Opera 43", new const std::vector<std::string>&  { "OPR/43." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA42);// (		Manufacturer.OPERA, Browser::OPERA, 42, "Opera 42", new const std::vector<std::string>&  { "OPR/42." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA34);// (		Manufacturer.OPERA, Browser::OPERA, 34, "Opera 34", new const std::vector<std::string>&  { "OPR/34." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA33);// (		Manufacturer.OPERA, Browser::OPERA, 33, "Opera 33", new const std::vector<std::string>&  { "OPR/33." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA32);// (		Manufacturer.OPERA, Browser::OPERA, 32, "Opera 32", new const std::vector<std::string>&  { "OPR/32." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA31);// (		Manufacturer.OPERA, Browser::OPERA, 31, "Opera 31", new const std::vector<std::string>&  { "OPR/31." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA30);// (		Manufacturer.OPERA, Browser::OPERA, 30, "Opera 30", new const std::vector<std::string>&  { "OPR/30." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA29);// (		Manufacturer.OPERA, Browser::OPERA, 29, "Opera 29", new const std::vector<std::string>&  { "OPR/29." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA28);// (		Manufacturer.OPERA, Browser::OPERA, 28, "Opera 28", new const std::vector<std::string>&  { "OPR/28." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA27);// (		Manufacturer.OPERA, Browser::OPERA, 27, "Opera 27", new const std::vector<std::string>&  { "OPR/27." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA26);// (		Manufacturer.OPERA, Browser::OPERA, 26, "Opera 26", new const std::vector<std::string>&  { "OPR/26." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA25);// (		Manufacturer.OPERA, Browser::OPERA, 25, "Opera 25", new const std::vector<std::string>&  { "OPR/25." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA24);// (		Manufacturer.OPERA, Browser::OPERA, 24, "Opera 24", new const std::vector<std::string>&  { "OPR/24." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA23);// (		Manufacturer.OPERA, Browser::OPERA, 23, "Opera 23", new const std::vector<std::string>&  { "OPR/23." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA20);// (		Manufacturer.OPERA, Browser::OPERA, 21, "Opera 20", new const std::vector<std::string>&  { "OPR/20." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA19);// (		Manufacturer.OPERA, Browser::OPERA, 19, "Opera 19", new const std::vector<std::string>&  { "OPR/19." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA18);// (		Manufacturer.OPERA, Browser::OPERA, 18, "Opera 18", new const std::vector<std::string>&  { "OPR/18." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA17);// (		Manufacturer.OPERA, Browser::OPERA, 17, "Opera 17", new const std::vector<std::string>&  { "OPR/17." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA16);// (		Manufacturer.OPERA, Browser::OPERA, 16, "Opera 16", new const std::vector<std::string>&  { "OPR/16." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA15);// (		Manufacturer.OPERA, Browser::OPERA, 15, "Opera 15", new const std::vector<std::string>&  { "OPR/15." }, null, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, new PatternBasedVersionFetcher("OPR\\/(([\\d]+)\\.([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),
	ZCENUM_K(Browser,OPERA12);// (		Manufacturer.OPERA, Browser::OPERA, 12, "Opera 12", new const std::vector<std::string>&  { "Opera/12", "Version/12." }, null, BrowserType.WEB_BROWSER, RenderingEngine.PRESTO, new PatternBasedVersionFetcher("Version\\/(([\\d]+)\\.([\\w]+))")),
	ZCENUM_K(Browser,OPERA11);// (		Manufacturer.OPERA, Browser::OPERA, 11, "Opera 11", new const std::vector<std::string>&  { "Version/11." }, null, BrowserType.WEB_BROWSER, RenderingEngine.PRESTO, new PatternBasedVersionFetcher("Version\\/(([\\d]+)\\.([\\w]+))")),
	ZCENUM_K(Browser,OPERA10);// (		Manufacturer.OPERA, Browser::OPERA, 10, "Opera 10", new const std::vector<std::string>&  { "Opera/9.8" }, null, BrowserType.WEB_BROWSER, RenderingEngine.PRESTO, new PatternBasedVersionFetcher("Version\\/(([\\d]+)\\.([\\w]+))")),
	ZCENUM_K(Browser,OPERA9);// (Manufacturer.OPERA, Browser::OPERA, 5, "Opera 9", new const std::vector<std::string>& { "Opera/9" }, null, BrowserType.WEB_BROWSER, RenderingEngine.PRESTO, null),
	ZCENUM_K(Browser,KONQUEROR);// (Manufacturer.OTHER, null, 1, "Konqueror", new const std::vector<std::string>& { "Konqueror" }, new const std::vector<std::string>& { "Exabot" }, BrowserType.WEB_BROWSER, RenderingEngine.KHTML, new PatternBasedVersionFetcher("Konqueror\\/(([0-9]+)\\.?([\\w]+)?(-[\\w]+)?)")),

	ZCENUM_K(Browser,DOLFIN2);// (Manufacturer.SAMSUNG, null, 1, "Samsung Dolphin 2", new const std::vector<std::string>& { "Dolfin/2" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.WEBKIT, null), // webkit based browser for the bada os

	/*
	 * Apple WebKit compatible client. Can be a browser or an application with embedded browser using UIWebView.
	 */
	ZCENUM_K(Browser,APPLE_WEB_KIT);// (Manufacturer.APPLE, null, 50, "Apple WebKit", new const std::vector<std::string>& { "AppleWebKit" }, new const std::vector<std::string>& { "bot", "preview", "OPR/", "Coast/", "Vivaldi", "Phantom" }, BrowserType.WEB_BROWSER, RenderingEngine.WEBKIT, null), // Microsoft Entrourage/Outlook 2010 also only identifies itself as AppleWebKit
	ZCENUM_K(Browser,APPLE_ITUNES);// (Manufacturer.APPLE, Browser::APPLE_WEB_KIT, 52, "iTunes", new const std::vector<std::string>& { "iTunes" }, null, BrowserType.APP, RenderingEngine.WEBKIT, null), // Microsoft Entrourage/Outlook 2010 also only identifies itself as AppleWebKit
	ZCENUM_K(Browser,APPLE_APPSTORE);// (Manufacturer.APPLE, Browser::APPLE_WEB_KIT, 53, "App Store", new const std::vector<std::string>& { "MacAppStore" }, null, BrowserType.APP, RenderingEngine.WEBKIT, null), // Microsoft Entrourage/Outlook 2010 also only identifies itself as AppleWebKit
	ZCENUM_K(Browser,ADOBE_AIR);// (Manufacturer.ADOBE, Browser::APPLE_WEB_KIT, 1, "Adobe AIR application", new const std::vector<std::string>& { "AdobeAIR" }, null, BrowserType.APP, RenderingEngine.WEBKIT, null), // Microsoft Entrourage/Outlook 2010 also only identifies itself as AppleWebKit

	ZCENUM_K(Browser,LOTUS_NOTES);// (Manufacturer.OTHER, null, 3, "Lotus Notes", new const std::vector<std::string>& { "Lotus-Notes" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.OTHER, new PatternBasedVersionFetcher("Lotus-Notes\\/(([\\d]+)\\.([\\w]+))")),  // before Mozilla

	ZCENUM_K(Browser,CAMINO);// (Manufacturer.OTHER, null, 5, "Camino", new const std::vector<std::string>& { "Camino" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, new PatternBasedVersionFetcher("Camino\\/(([0-9]+)\\.?([\\w]+)?(\\.[\\w]+)?)")),  // using Gecko Engine
	ZCENUM_K(Browser,CAMINO2);// (Manufacturer.OTHER, Browser::CAMINO, 17, "Camino 2", new const std::vector<std::string>& { "Camino/2" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, null),  // using Gecko Engine

	ZCENUM_K(Browser,FLOCK);// (Manufacturer.OTHER, null, 4, "Flock", new const std::vector<std::string>& { "Flock" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, new PatternBasedVersionFetcher("Flock\\/(([0-9]+)\\.?([\\w]+)?(\\.[\\w]+)?)")),

	/*
		* Thunderbird email client, based on the same Gecko engine Firefox is using.
		*/
	ZCENUM_K(Browser,THUNDERBIRD);// (Manufacturer.MOZILLA, null, 110, "Thunderbird", new const std::vector<std::string>& { "Thunderbird" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.GECKO, new PatternBasedVersionFetcher("Thunderbird\\/(([0-9]+)\\.?([\\w]+)?(\\.[\\w]+)?(\\.[\\w]+)?)")),  // using Gecko Engine
	ZCENUM_K(Browser,THUNDERBIRD12);// (Manufacturer.MOZILLA, Browser::THUNDERBIRD, 185, "Thunderbird 12", new const std::vector<std::string>& { "Thunderbird/12" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.GECKO, null),  // using Gecko Engine
	ZCENUM_K(Browser,THUNDERBIRD11);// (Manufacturer.MOZILLA, Browser::THUNDERBIRD, 184, "Thunderbird 11", new const std::vector<std::string>& { "Thunderbird/11" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.GECKO, null),  // using Gecko Engine
	ZCENUM_K(Browser,THUNDERBIRD10);// (Manufacturer.MOZILLA, Browser::THUNDERBIRD, 183, "Thunderbird 10", new const std::vector<std::string>& { "Thunderbird/10" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.GECKO, null),  // using Gecko Engine
	ZCENUM_K(Browser,THUNDERBIRD8);// (Manufacturer.MOZILLA, Browser::THUNDERBIRD, 180, "Thunderbird 8", new const std::vector<std::string>& { "Thunderbird/8" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.GECKO, null),  // using Gecko Engine
	ZCENUM_K(Browser,THUNDERBIRD7);// (  	Manufacturer.MOZILLA, Browser::THUNDERBIRD, 170, "Thunderbird 7", new const std::vector<std::string>&  { "Thunderbird/7" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,THUNDERBIRD6);// (  	Manufacturer.MOZILLA, Browser::THUNDERBIRD, 160, "Thunderbird 6", new const std::vector<std::string>&  { "Thunderbird/6" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,THUNDERBIRD3);// (  	Manufacturer.MOZILLA, Browser::THUNDERBIRD, 130, "Thunderbird 3", new const std::vector<std::string>&  { "Thunderbird/3" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.GECKO, null ),  // using Gecko Engine
	ZCENUM_K(Browser,THUNDERBIRD2);// (  	Manufacturer.MOZILLA, Browser::THUNDERBIRD, 120, "Thunderbird 2", new const std::vector<std::string>&  { "Thunderbird/2" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.GECKO, null ),  // using Gecko Engine

	ZCENUM_K(Browser,VIVALDI);// (Manufacturer.OTHER, null, 108338, "Vivaldi", new const std::vector<std::string>& { "Vivaldi" }, new const std::vector<std::string>& {}, BrowserType.WEB_BROWSER, RenderingEngine.BLINK, new PatternBasedVersionFetcher("Vivaldi/(([\\d]+).([\\d]+).([\\d]+).([\\d]+))")),

	ZCENUM_K(Browser,SEAMONKEY);// (Manufacturer.OTHER, null, 15, "SeaMonkey", new const std::vector<std::string>& { "SeaMonkey" }, null, BrowserType.WEB_BROWSER, RenderingEngine.GECKO, new PatternBasedVersionFetcher("SeaMonkey\\/(([0-9]+)\\.?([\\w]+)?(\\.[\\w]+)?)")), // using Gecko Engine

	ZCENUM_K(Browser,BOT);// (Manufacturer.OTHER, null, 12, "Robot/Spider", new const std::vector<std::string>& { "Googlebot", "Mediapartners-Google", "Web Preview", "bot", "Applebot" , "spider", "crawler", "Feedfetcher", "Slurp", "Twiceler", "Nutch", "BecomeBot",
	//	"bingbot", "BingPreview", "Google Web Preview", "WordPress.com mShots", "Seznam", "facebookexternalhit" , "YandexMarket", "Teoma", "ThumbSniper", "Phantom",
	//	"Go-http-client", "Java/", "python-requests", "YandexBot", "AdsBot-Google", "AhrefsBot" }, null, BrowserType.ROBOT, RenderingEngine.OTHER, null),
	ZCENUM_K(Browser,BOT_MOBILE);// (Manufacturer.OTHER, Browser::BOT, 20, "Mobile Robot/Spider", new const std::vector<std::string>& { "Googlebot-Mobile" }, null, BrowserType.ROBOT, RenderingEngine.OTHER, null),

	ZCENUM_K(Browser,MOZILLA);// (Manufacturer.MOZILLA, null, 1, "Mozilla", new const std::vector<std::string>& { "Mozilla", "Moozilla" }, new const std::vector<std::string>& { "ggpht.com" }, BrowserType.WEB_BROWSER, RenderingEngine.OTHER, null), // rest of the mozilla browsers

	ZCENUM_K(Browser,CFNETWORK);// (Manufacturer.OTHER, null, 6, "CFNetwork", new const std::vector<std::string>& { "CFNetwork" }, null, BrowserType.UNKNOWN, RenderingEngine.OTHER, new PatternBasedVersionFetcher("CFNetwork/(([\\d]+)(?:\\.([\\d]))?(?:\\.([\\d]+))?)")), // Mac OS X cocoa library

	ZCENUM_K(Browser,EUDORA);// (Manufacturer.OTHER, null, 7, "Eudora", new const std::vector<std::string>& { "Eudora", "EUDORA" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.OTHER, null),  // email client by Qualcomm

	ZCENUM_K(Browser,POCOMAIL);// (Manufacturer.OTHER, null, 8, "PocoMail", new const std::vector<std::string>& { "PocoMail" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.OTHER, null),

	ZCENUM_K(Browser,THEBAT);// (Manufacturer.OTHER, null, 9, "The Bat!", new const std::vector<std::string>& { "The Bat" }, null, BrowserType.EMAIL_CLIENT, RenderingEngine.OTHER, null), // Email Client

	ZCENUM_K(Browser,NETFRONT);// (Manufacturer.OTHER, null, 10, "NetFront", new const std::vector<std::string>& { "NetFront" }, null, BrowserType.MOBILE_BROWSER, RenderingEngine.OTHER, null), // mobile device browser

	ZCENUM_K(Browser,EVOLUTION);//(		Manufacturer.OTHER, null, 11, "Evolution", new const std::vector<std::string>& {"CamelHttpStream"}, null, BrowserType.EMAIL_CLIENT, RenderingEngine.OTHER, null), // http://www.go-evolution.org/Camel.Stream

	ZCENUM_K(Browser,LYNX);// (Manufacturer.OTHER, null, 13, "Lynx", new const std::vector<std::string>& { "Lynx" }, null, BrowserType.TEXT_BROWSER, RenderingEngine.OTHER, new PatternBasedVersionFetcher("Lynx\\/(([0-9]+)\\.([\\d]+)\\.?([\\w-+]+)?\\.?([\\w-+]+)?)")),

	ZCENUM_K(Browser,DOWNLOAD);// (Manufacturer.OTHER, null, 16, "Downloading Tool", new const std::vector<std::string>& { "cURL","wget", "ggpht.com", "Apache-HttpClient" }, null, BrowserType.TOOL, RenderingEngine.OTHER, null),

	ZCENUM_K(Browser,UNKNOWN);// (Manufacturer.OTHER, null, 14, "Unknown", new std::string[0], null, BrowserType.UNKNOWN, RenderingEngine.OTHER, null),

private:
	/*
	 * An id for each browser version which is unique per m_manufacturer.
	 */
	short m_id;
	std::string m_name;
	std::vector<std::string> m_aliases;
	std::vector<std::string> m_excludeList; // don't match when these values are in the agent-string
	BrowserType::ptr m_browserType;
	Manufacturer::ptr m_manufacturer;
	RenderingEngine::ptr m_renderingEngine;
	Browser::ptr m_parent;
	std::vector<Browser::ptr> m_children;
	VersionFetcher::ptr m_versionFetcher;
	Version version;
	inline static std::vector<Browser::ptr> topLevelBrowsers;
private:
	Browser(int index, const char* key, const Manufacturer::ptr & manufacturer, const Browser::ptr & parent, int versionId,
		const std::string & name, const std::vector<std::string>&aliases,
		const std::vector<std::string>&exclude, const BrowserType::ptr & browserType,
		const RenderingEngine::ptr & renderingEngine, const VersionFetcher::ptr & versionFetcher)
		:ZcEnumBase(index, key)
		, m_id((manufacturer->getId() << 8) + (uint8_t)versionId)
		, m_name(name)
		, m_parent(parent)
		, m_children()
		, m_aliases(Utils::toLowerCase(aliases))
		, m_excludeList(Utils::toLowerCase(exclude))
		, m_browserType(browserType)
		, m_manufacturer(manufacturer)
		, m_renderingEngine(renderingEngine)
		, m_versionFetcher(versionFetcher)
	{
		if (!this->m_parent)
			addTopLevelBrowser(this);
		else
			this->m_parent->m_children.push_back(this);
	}

	// create collection of top level browsers during initialization
	static void addTopLevelBrowser(const Browser::ptr & browser) {
		topLevelBrowsers.push_back(browser);
	}
public:
	short getId() {
		return this->m_id;
	}

	std::string getName() {
		return m_name;
	}

	/**
	 * Detects the detailed version information of the browser. Depends on the userAgent to be available.
	 * Returns null if it can not detect the version information.
	 * @param userAgentString User-agent string as provided in the request.
	 * @return Version
	 */
	Version getVersion(const std::string & userAgentString) {
		if (m_versionFetcher == nullptr) {
			return getGroup() ? getGroup()->getVersion(userAgentString) : Version{};
		}
		return m_versionFetcher->version(userAgentString);
	}

	/**
	 * @return the m_browserType
	 */
	BrowserType::ptr getBrowserType() {
		return m_browserType;
	}

	/**
	 * @return the m_manufacturer
	 */
	Manufacturer::ptr getManufacturer() {
		return m_manufacturer;
	}

	/**
	 * @return the rendering engine
	 */
	RenderingEngine::ptr getRenderingEngine() {
		return m_renderingEngine;
	}

	/**
	 * @return top level browser family
	 */
	Browser::ptr getGroup() {
		if (this->m_parent) {
			return m_parent->getGroup();
		}
		return this;
	}

	/*
	 * Checks if the given user-agent string matches to the browser.
	 * Only checks for one specific browser.
	 */
	bool  isInUserAgentString(const std::string & agentString)
	{
		if (agentString.empty())
			return false;

		std::string agentStringLowerCase = Utils::toLowerCase(agentString);
		return isInUserAgentLowercaseString(agentStringLowerCase);
	}
private:
	bool  isInUserAgentLowercaseString(const std::string & agentStringLowerCase) {
		return Utils::contains(agentStringLowerCase, m_aliases);
	}

	Browser::ptr checkUserAgentLowercase(const std::string & agentLowercaseString) {
		if (this->isInUserAgentLowercaseString(agentLowercaseString)) {
			if (!m_children.empty()) {
				for (auto& childBrowser : this->m_children) {
					Browser::ptr match = childBrowser->checkUserAgentLowercase(agentLowercaseString);
					if (match) {
						return match;
					}
				}
			}

			// if m_children didn't match we continue checking the current to prevent false positives
			if (!Utils::contains(agentLowercaseString, m_excludeList)) {
				return this;
			}
		}
		return nullptr;
	}
public:
	/**
	 * Iterates over all Browsers to compare the browser signature with
	 * the user agent string. If no match can be found Browser::UNKNOWN will
	 * be returned.
	 * Starts with the top level browsers and only if one of those matches
	 * checks m_children browsers.
	 * Steps out of loop as soon as there is a match.
	 * @param agentString User-agent sting as provided in the request.
	 * @return Browser enum
	 */
	static Browser::ptr parseUserAgentString(const std::string & agentString)
	{
		return parseUserAgentString(agentString, topLevelBrowsers);
	}

	static Browser::ptr parseUserAgentLowercaseString(const std::string & agentString)
	{
		if (agentString.empty()) {
			return &Browser::UNKNOWN;
		}
		return parseUserAgentLowercaseString(agentString, topLevelBrowsers);
	}

	/**
	 * Iterates over the given Browsers (incl. m_children) to compare the browser
	 * signature with the user agent string.
	 * If no match can be found Browser::UNKNOWN will be returned.
	 * Steps out of loop as soon as there is a match.
	 * Be aware that if the order of the provided Browsers is incorrect or if the set is too limited it can lead to false matches!
	 * @param agentString User-agent sting as provided in the request.
	 * @param browsers List of browsers.
	 * @return Browser enum
	 */
	static Browser::ptr  parseUserAgentString(const std::string & agentString, const std::vector<Browser::ptr>&browsers)
	{
		if (!agentString.empty()) {
			std::string agentLowercaseString = Utils::toLowerCase(agentString);
			return parseUserAgentLowercaseString(agentLowercaseString, browsers);
		}
		return &Browser::UNKNOWN;
	}
private:
	static Browser::ptr parseUserAgentLowercaseString(const std::string & agentLowercaseString, const std::vector<Browser::ptr>&browsers) {
		for (auto& browser : browsers) {
			Browser::ptr match = browser->checkUserAgentLowercase(agentLowercaseString);
			if (match) {
				return match; // either current operatingSystem or a child object
			}
		}
		return &Browser::UNKNOWN;
	}
public:
	/**
	 * Returns the enum constant of this type with the specified m_id.
	 * Throws IllegalArgumentException if the value does not exist.
	 * @param m_id Id of the browser
	 * @return Browser enum
	 */
	static Browser::ptr valueOf(short id) {
		for (auto browser : Browser::values())
		{
			if (browser->getId() == id)
				return browser;
		}
		return nullptr;
	}
	std::string toString()const override {
		return m_name;
	}
};


