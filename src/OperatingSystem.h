#pragma once

#include "BaseEnum.hpp"
#include "Utils.h"
#include "DeviceType.h"
#include "Manufacturer.h"

#include <string>
#include <vector>
#include <regex>

/**
 * Enum constants for most common operating systems.
 * @author harald 
 */
//class OperatingSystem 
ZCENUM_CLASS(OperatingSystem)
{
	ZCENUM_INIT(OperatingSystem);
	friend  class UserAgent;
private:
	// the order is important since the agent string is being compared with the m_aliases
	/**
	 * Windows Mobile / Windows CE. Exact version unknown.
	 */
	ZCENUM_K(OperatingSystem, WINDOWS);//(Manufacturer.MICROSOFT, null, 1, "Windows", new const std::string&[]{ "Windows" }, new const std::string&[]{ "Palm", "ggpht.com" }, DeviceType.COMPUTER, null), // catch the rest of older Windows systems );//(95, NT,...)
	ZCENUM_K(OperatingSystem, WINDOWS_10);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 24, "Windows 10", new const std::string&[]{ "Windows NT 6.4", "Windows NT 10" }, null, DeviceType.COMPUTER, null), // before Win, yes, Windows 10 is called 6.4 LOL
	ZCENUM_K(OperatingSystem, WINDOWS_81);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 23, "Windows 8.1", new const std::string&[]{ "Windows NT 6.3" }, null, DeviceType.COMPUTER, null), // before Win, yes, Windows 8.1 is called 6.3 LOL
	ZCENUM_K(OperatingSystem, WINDOWS_8);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 22, "Windows 8", new const std::string&[]{ "Windows NT 6.2" }, new const std::string&[]{ "Xbox","Xbox One" }, DeviceType.COMPUTER, null), // before Win, yes, Windows 8 is called 6.2 LOL
	ZCENUM_K(OperatingSystem, WINDOWS_7);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 21, "Windows 7", new const std::string&[]{ "Windows NT 6.1" }, new const std::string&[]{ "Xbox","Xbox One" }, DeviceType.COMPUTER, null), // before Win, yes, Windows 7 is called 6.1 LOL
	ZCENUM_K(OperatingSystem, WINDOWS_VISTA);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 20, "Windows Vista", new const std::string&[]{ "Windows NT 6" }, new const std::string&[]{ "Xbox","Xbox One" }, DeviceType.COMPUTER, null), // before Win
	ZCENUM_K(OperatingSystem, WINDOWS_2000);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 15, "Windows 2000", new const std::string&[]{ "Windows NT 5.0" }, null, DeviceType.COMPUTER, null), // before Win
	ZCENUM_K(OperatingSystem, WINDOWS_XP);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 10, "Windows XP", new const std::string&[]{ "Windows NT 5" }, new const std::string&[]{ "ggpht.com" }, DeviceType.COMPUTER, null), // before Win, 5.1 and 5.2 are basically XP systems
	ZCENUM_K(OperatingSystem, WINDOWS_10_MOBILE);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 54, "Windows 10 Mobile", new const std::string&[]{ "Windows Phone 10" }, null, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, WINDOWS_PHONE8_1);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 53, "Windows Phone 8.1", new const std::string&[]{ "Windows Phone 8.1" }, null, DeviceType.MOBILE, null), // before Win
	ZCENUM_K(OperatingSystem, WINDOWS_PHONE8);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 52, "Windows Phone 8", new const std::string&[]{ "Windows Phone 8" }, null, DeviceType.MOBILE, null), // before Win
	ZCENUM_K(OperatingSystem, WINDOWS_MOBILE7);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 51, "Windows Phone 7", new const std::string&[]{ "Windows Phone OS 7" }, null, DeviceType.MOBILE, null), // should be Windows Phone 7 but to keep it compatible we'll leave the m_name as is.
	ZCENUM_K(OperatingSystem, WINDOWS_MOBILE);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 50, "Windows Mobile", new const std::string&[]{ "Windows CE" }, null, DeviceType.MOBILE, null), // before Win
	ZCENUM_K(OperatingSystem, WINDOWS_98);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 5, "Windows 98", new const std::string&[]{ "Windows 98","Win98" }, new const std::string&[]{ "Palm" }, DeviceType.COMPUTER, null), // before Win 
	ZCENUM_K(OperatingSystem, XBOX_OS);//(Manufacturer.MICROSOFT, OperatingSystem.WINDOWS, 62, "Xbox OS", new const std::string&[]{ "xbox" }, new const std::string&[]{}, DeviceType.GAME_CONSOLE, null),

	// for Google user-agent, see https://developer.chrome.com/multidevice/user-agent
	ZCENUM_K(OperatingSystem, ANDROID);//(Manufacturer.GOOGLE, null, 0, "Android", new const std::string&[]{ "Android" }, new const std::string&[]{ "Ubuntu" }, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, ANDROID8);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID, 8, "Android 8.x", new const std::string&[]{ "Android 8", "Android-8" }, new const std::string&[]{ "glass" }, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, ANDROID8_TABLET);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID8, 80, "Android 8.x Tablet", new const std::string&[]{ "Android 8", "Android-8" }, new const std::string&[]{ "mobile", "glass" }, DeviceType.TABLET, null),
	ZCENUM_K(OperatingSystem, ANDROID7);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID, 7, "Android 7.x", new const std::string&[]{ "Android 7", "Android-7" }, new const std::string&[]{ "glass" }, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, ANDROID7_TABLET);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID7, 70, "Android 7.x Tablet", new const std::string&[]{ "Android 7", "Android-7" }, new const std::string&[]{ "mobile", "glass" }, DeviceType.TABLET, null),
	ZCENUM_K(OperatingSystem, ANDROID6);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID, 6, "Android 6.x", new const std::string&[]{ "Android 6", "Android-6" }, new const std::string&[]{ "glass" }, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, ANDROID6_TABLET);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID6, 60, "Android 6.x Tablet", new const std::string&[]{ "Android 6", "Android-6" }, new const std::string&[]{ "mobile", "glass" }, DeviceType.TABLET, null),
	ZCENUM_K(OperatingSystem, ANDROID5);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID, 5, "Android 5.x", new const std::string&[]{ "Android 5", "Android-5" }, new const std::string&[]{ "glass" }, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, ANDROID5_TABLET);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID5, 50, "Android 5.x Tablet", new const std::string&[]{ "Android 5", "Android-5" }, new const std::string&[]{ "mobile", "glass" }, DeviceType.TABLET, null),
	ZCENUM_K(OperatingSystem, ANDROID4);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID, 4, "Android 4.x", new const std::string&[]{ "Android 4", "Android-4" }, new const std::string&[]{ "glass", "ubuntu" }, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, ANDROID4_TABLET);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID4, 40, "Android 4.x Tablet", new const std::string&[]{ "Android 4", "Android-4" }, new const std::string&[]{ "mobile", "glass", "ubuntu" }, DeviceType.TABLET, null),
	ZCENUM_K(OperatingSystem, ANDROID4_WEARABLE);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID, 400, "Android 4.x", new const std::string&[]{ "Android 4" }, new const std::string&[]{ "ubuntu" }, DeviceType.WEARABLE, null),
	ZCENUM_K(OperatingSystem, ANDROID3_TABLET);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID, 30, "Android 3.x Tablet", new const std::string&[]{ "Android 3" }, null, DeviceType.TABLET, null), // as long as there are not Android 3.x phones this should be enough
	ZCENUM_K(OperatingSystem, ANDROID2);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID, 2, "Android 2.x", new const std::string&[]{ "Android 2" }, null, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, ANDROID2_TABLET);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID2, 20, "Android 2.x Tablet", new const std::string&[]{ "Kindle Fire", "GT-P1000","SCH-I800" }, null, DeviceType.TABLET, null),
	ZCENUM_K(OperatingSystem, ANDROID1);//(Manufacturer.GOOGLE, OperatingSystem.ANDROID, 1, "Android 1.x", new const std::string&[]{ "Android 1" }, null, DeviceType.MOBILE, null),
	/**
	 * Generic Android mobile device without OS version number information
	 */
	ZCENUM_K(OperatingSystem, ANDROID_MOBILE);// (Manufacturer.GOOGLE, OperatingSystem.ANDROID, 11, "Android Mobile", new const std::string&[]{ "Mobile" }, new const std::string&[]{ "ubuntu" }, DeviceType.MOBILE, null),
	/**
	 * Generic Android tablet device without OS version number information
	 */
	ZCENUM_K(OperatingSystem, ANDROID_TABLET);// (Manufacturer.GOOGLE, OperatingSystem.ANDROID, 12, "Android Tablet", new const std::string&[]{ "Tablet" }, null, DeviceType.TABLET, null),

	/**
	 * 	Chrome OS by Google, mostly used on Chromebooks and Chromeboxes
	 */
	ZCENUM_K(OperatingSystem, CHROME_OS);// (Manufacturer.GOOGLE, null, 1000, "Chrome OS", new const std::string&[]{ "CrOS" }, null, DeviceType.COMPUTER, null),
	/**
	 * PalmOS, exact version unkown
	 */
	ZCENUM_K(OperatingSystem, WEBOS);// (Manufacturer.HP, null, 11, "WebOS", new const std::string&[]{ "webOS" }, null, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, PALM);// (Manufacturer.HP, null, 10, "PalmOS", new const std::string&[]{ "Palm" }, null, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, MEEGO);// (Manufacturer.NOKIA, null, 3, "MeeGo", new const std::string&[]{ "MeeGo" }, null, DeviceType.MOBILE, null),

	/**
	 * iOS4, with the release of the iPhone 4, Apple renamed the OS to iOS.
	 */
	ZCENUM_K(OperatingSystem, IOS);// (Manufacturer.APPLE, null, 2, "iOS", new const std::string&[]{ "iPhone", "like Mac OS X" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS11_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 92, "iOS 11 (iPhone)", new const std::string&[]{ "iPhone OS 11" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS10_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 91, "iOS 10 (iPhone)", new const std::string&[]{ "iPhone OS 10" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS9_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 90, "iOS 9 (iPhone)", new const std::string&[]{ "iPhone OS 9" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS8_4_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 49, "iOS 8.4 (iPhone)", new const std::string&[]{ "iPhone OS 8_4" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS8_3_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 48, "iOS 8.3 (iPhone)", new const std::string&[]{ "iPhone OS 8_3" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS8_2_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 47, "iOS 8.2 (iPhone)", new const std::string&[]{ "iPhone OS 8_2" }, null, DeviceType.MOBILE, null), // version that added Apple Watch support
	ZCENUM_K(OperatingSystem, iOS8_1_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 46, "iOS 8.1 (iPhone)", new const std::string&[]{ "iPhone OS 8_1" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS8_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 45, "iOS 8 (iPhone)", new const std::string&[]{ "iPhone OS 8" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS7_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 44, "iOS 7 (iPhone)", new const std::string&[]{ "iPhone OS 7" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS6_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 43, "iOS 6 (iPhone)", new const std::string&[]{ "iPhone OS 6" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS5_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 42, "iOS 5 (iPhone)", new const std::string&[]{ "iPhone OS 5" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, iOS4_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 41, "iOS 4 (iPhone)", new const std::string&[]{ "iPhone OS 4" }, null, DeviceType.MOBILE, null), // before MAC_OS_X_IPHONE for all older versions
	ZCENUM_K(OperatingSystem, MAC_OS_X_IPAD);// (Manufacturer.APPLE, OperatingSystem.IOS, 50, "Mac OS X (iPad)", new const std::string&[]{ "iPad" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, iOS11_IPAD);// (Manufacturer.APPLE, OperatingSystem.MAC_OS_X_IPAD, 60, "iOS 11 (iPad)", new const std::string&[]{ "OS 11" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, iOS10_IPAD);// (Manufacturer.APPLE, OperatingSystem.MAC_OS_X_IPAD, 59, "iOS 10 (iPad)", new const std::string&[]{ "OS 10" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, iOS9_IPAD);// (Manufacturer.APPLE, OperatingSystem.MAC_OS_X_IPAD, 58, "iOS 9 (iPad)", new const std::string&[]{ "OS 9" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, iOS8_4_IPAD);// (Manufacturer.APPLE, OperatingSystem.MAC_OS_X_IPAD, 57, "iOS 8.4 (iPad)", new const std::string&[]{ "OS 8_4" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, iOS8_3_IPAD);// (Manufacturer.APPLE, OperatingSystem.MAC_OS_X_IPAD, 56, "iOS 8.3 (iPad)", new const std::string&[]{ "OS 8_3" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, iOS8_2_IPAD);// (Manufacturer.APPLE, OperatingSystem.MAC_OS_X_IPAD, 55, "iOS 8.2 (iPad)", new const std::string&[]{ "OS 8_2" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, iOS8_1_IPAD);// (Manufacturer.APPLE, OperatingSystem.MAC_OS_X_IPAD, 54, "iOS 8.1 (iPad)", new const std::string&[]{ "OS 8_1" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, iOS8_IPAD);// (Manufacturer.APPLE, OperatingSystem.MAC_OS_X_IPAD, 53, "iOS 8 (iPad)", new const std::string&[]{ "OS 8_0" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, iOS7_IPAD);// (Manufacturer.APPLE, OperatingSystem.MAC_OS_X_IPAD, 52, "iOS 7 (iPad)", new const std::string&[]{ "OS 7" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, iOS6_IPAD);// (Manufacturer.APPLE, OperatingSystem.MAC_OS_X_IPAD, 51, "iOS 6 (iPad)", new const std::string&[]{ "OS 6" }, null, DeviceType.TABLET, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, MAC_OS_X_IPHONE);// (Manufacturer.APPLE, OperatingSystem.IOS, 40, "Mac OS X (iPhone)", new const std::string&[]{ "iPhone" }, null, DeviceType.MOBILE, null), // before Mac OS X
	ZCENUM_K(OperatingSystem, MAC_OS_X_IPOD);// (Manufacturer.APPLE, OperatingSystem.IOS, 30, "Mac OS X (iPod)", new const std::string&[]{ "iPod" }, null, DeviceType.MOBILE, null), // before Mac OS X

	ZCENUM_K(OperatingSystem, MAC_OS_X);// (Manufacturer.APPLE, null, 10, "Mac OS X", new const std::string&[]{ "Mac OS X" , "CFNetwork" }, null, DeviceType.COMPUTER, null), // before Mac	

	/**
	 * Older Mac OS systems before Mac OS X
	 */
	ZCENUM_K(OperatingSystem, MAC_OS);// (Manufacturer.APPLE, null, 1, "Mac OS", new const std::string&[]{ "Mac" }, null, DeviceType.COMPUTER, null), // older Mac OS systems

	/**
	 * Linux based Maemo software platform by Nokia. Used in the N900 phone. http://maemo.nokia.com/
	 */
	ZCENUM_K(OperatingSystem, MAEMO);// (Manufacturer.NOKIA, null, 2, "Maemo", new const std::string&[]{ "Maemo" }, null, DeviceType.MOBILE, null),

	/**
	 * Bada is a mobile operating system being developed by Samsung Electronics.
	 */
	ZCENUM_K(OperatingSystem, BADA);// (Manufacturer.SAMSUNG, null, 2, "Bada", new const std::string&[]{ "Bada" }, null, DeviceType.MOBILE, null),

	/**
	 *  Google TV uses Android 2.x or 3.x but doesn't identify itself as Android.
	 */
	ZCENUM_K(OperatingSystem, GOOGLE_TV);// (Manufacturer.GOOGLE, null, 100, "Android (Google TV)", new const std::string&[]{ "GoogleTV" }, null, DeviceType.DMR, null),

	/**
	 * Tizen is a Linux Foundation project. Mostly used by various Samsung devices.
	 * @see <a href="https://wiki.tizen.org/Tizen_Browser">Tizen Browser user-agent format</a>
	 * @see <a href="http://developer.samsung.com/technical-doc/view.do?v=T000000203">Samsung Internet User-Agent const std::string& Format</a>
	 * Not specified how devices like car display or a fridge would identify themselves.
	 */
	ZCENUM_K(OperatingSystem, TIZEN);// (Manufacturer.LINUX_FOUNDATION, null, 101, "Tizen", new const std::string&[]{ "Tizen" }, null, DeviceType.UNKNOWN, null),
	ZCENUM_K(OperatingSystem, TIZEN3);// (Manufacturer.LINUX_FOUNDATION, OperatingSystem.TIZEN, 30, "Tizen 3", new const std::string&[]{ "Tizen 3." }, null, DeviceType.UNKNOWN, null),
	ZCENUM_K(OperatingSystem, TIZEN3_MOBILE);// (Manufacturer.LINUX_FOUNDATION, OperatingSystem.TIZEN3, 31, "Tizen 3 (Mobile)", new const std::string&[]{ "mobile" }, null, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, TIZEN3_TV);// (Manufacturer.LINUX_FOUNDATION, OperatingSystem.TIZEN3, 32, "Tizen 3 (SmartTV)", new const std::string&[]{ "Smart-TV", " TV " }, null, DeviceType.DMR, null),
	ZCENUM_K(OperatingSystem, TIZEN2);// (Manufacturer.LINUX_FOUNDATION, OperatingSystem.TIZEN, 20, "Tizen 2", new const std::string&[]{ "Tizen 2." }, null, DeviceType.UNKNOWN, null),
	ZCENUM_K(OperatingSystem, TIZEN2_MOBILE);// (Manufacturer.LINUX_FOUNDATION, OperatingSystem.TIZEN2, 21, "Tizen 2 (Mobile)", new const std::string&[]{ "mobile" }, null, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, TIZEN2_TV);// (Manufacturer.LINUX_FOUNDATION, OperatingSystem.TIZEN2, 22, "Tizen 2 (SmartTV)", new const std::string&[]{ "Smart-TV"," TV " }, null, DeviceType.DMR, null),
	ZCENUM_K(OperatingSystem, TIZEN_MOBILE);// (Manufacturer.LINUX_FOUNDATION, OperatingSystem.TIZEN, 10, "Tizen (mobile)", new const std::string&[]{ "mobile" }, null, DeviceType.MOBILE, null),

	/**
	 * Various Linux based operating systems.
	 */
	ZCENUM_K(OperatingSystem, KINDLE);// (Manufacturer.AMAZON, null, 1, "Linux (Kindle)", new const std::string&[]{ "Kindle" }, null, DeviceType.TABLET, null),
	ZCENUM_K(OperatingSystem, KINDLE3);// (Manufacturer.AMAZON, OperatingSystem.KINDLE, 30, "Linux (Kindle 3)", new const std::string&[]{ "Kindle/3" }, null, DeviceType.TABLET, null),
	ZCENUM_K(OperatingSystem, KINDLE2);// (Manufacturer.AMAZON, OperatingSystem.KINDLE, 20, "Linux (Kindle 2)", new const std::string&[]{ "Kindle/2" }, null, DeviceType.TABLET, null),
	ZCENUM_K(OperatingSystem, LINUX);// (Manufacturer.OTHER, null, 2, "Linux", new const std::string&[]{ "Linux", "CamelHttpStream" }, null, DeviceType.COMPUTER, null), // CamelHttpStream is being used by Evolution, an email client for Linux
	ZCENUM_K(OperatingSystem, UBUNTU);// (Manufacturer.CONONICAL, OperatingSystem.LINUX, 1, "Ubuntu", new const std::string&[]{ "ubuntu" }, null, DeviceType.COMPUTER, null),
	ZCENUM_K(OperatingSystem, UBUNTU_TOUCH_MOBILE);// (Manufacturer.CONONICAL, OperatingSystem.UBUNTU, 200, "Ubuntu Touch (mobile)", new const std::string&[]{ "mobile" }, null, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, LINUX_SMART_TV);// (Manufacturer.OTHER, OperatingSystem.LINUX, 21, "Linux (SmartTV)", new const std::string&[]{ "SmartTv" }, null, DeviceType.DMR, null),

	/**
	 * Other Symbian OS versions
	 */
	ZCENUM_K(OperatingSystem, SYMBIAN);// (Manufacturer.SYMBIAN, null, 1, "Symbian OS", new const std::string&[]{ "Symbian", "Series60" }, null, DeviceType.MOBILE, null),
	/**
	 * Symbian OS 9.x versions. Being used by Nokia (N71, N73, N81, N82, N91, N92, N95, ...)
	 */
	ZCENUM_K(OperatingSystem, SYMBIAN9);// (Manufacturer.SYMBIAN, OperatingSystem.SYMBIAN, 20, "Symbian OS 9.x", new const std::string&[]{ "SymbianOS/9", "Series60/3" }, null, DeviceType.MOBILE, null),
	/**
	 * Symbian OS 8.x versions. Being used by Nokia (6630, 6680, 6681, 6682, N70, N72, N90).
	 */
	ZCENUM_K(OperatingSystem, SYMBIAN8);// (Manufacturer.SYMBIAN, OperatingSystem.SYMBIAN, 15, "Symbian OS 8.x", new const std::string&[]{ "SymbianOS/8", "Series60/2.6", "Series60/2.8" }, null, DeviceType.MOBILE, null),
	/**
	 * Symbian OS 7.x versions. Being used by Nokia (3230, 6260, 6600, 6620, 6670, 7610),
	 * Panasonic (X700, X800), Samsung (SGH-D720, SGH-D730) and Lenovo (P930).
	 */
	ZCENUM_K(OperatingSystem, SYMBIAN7);// (Manufacturer.SYMBIAN, OperatingSystem.SYMBIAN, 10, "Symbian OS 7.x", new const std::string&[]{ "SymbianOS/7" }, null, DeviceType.MOBILE, null),
	/**
	 * Symbian OS 6.x versions.
	 */
	ZCENUM_K(OperatingSystem, SYMBIAN6);// (Manufacturer.SYMBIAN, OperatingSystem.SYMBIAN, 5, "Symbian OS 6.x", new const std::string&[]{ "SymbianOS/6" }, null, DeviceType.MOBILE, null),
	/**
	 * Nokia's Series 40 operating system. Series 60 (S60) uses the Symbian OS.
	 */
	ZCENUM_K(OperatingSystem, SERIES40);// (Manufacturer.NOKIA, null, 1, "Series 40", new const std::string&[]{ "Nokia6300" }, null, DeviceType.MOBILE, null),
	/**
	 * Proprietary operating system used for many Sony Ericsson phones.
	 */
	ZCENUM_K(OperatingSystem, SONY_ERICSSON);// (Manufacturer.SONY_ERICSSON, null, 1, "Sony Ericsson", new const std::string&[]{ "SonyEricsson" }, null, DeviceType.MOBILE, null), // after symbian, some SE phones use symbian
	ZCENUM_K(OperatingSystem, SUN_OS);// (Manufacturer.SUN, null, 1, "SunOS", new const std::string&[]{ "SunOS" }, null, DeviceType.COMPUTER, null),
	ZCENUM_K(OperatingSystem, PSP);// (Manufacturer.SONY, null, 1, "Sony Playstation", new const std::string&[]{ "Playstation" }, null, DeviceType.GAME_CONSOLE, null),
	/**
	 * Nintendo Wii game console.
	 */
	ZCENUM_K(OperatingSystem, WII);// (Manufacturer.NINTENDO, null, 1, "Nintendo Wii", new const std::string&[]{ "Wii" }, null, DeviceType.GAME_CONSOLE, null),
	/**
	 * BlackBerryOS. The BlackBerryOS exists in different version. How relevant those versions are, is not clear.
	 */
	ZCENUM_K(OperatingSystem, BLACKBERRY);// (Manufacturer.BLACKBERRY, null, 1, "BlackBerryOS", new const std::string&[]{ "BlackBerry" }, null, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, BLACKBERRY7);// (Manufacturer.BLACKBERRY, OperatingSystem.BLACKBERRY, 7, "BlackBerry 7", new const std::string&[]{ "Version/7" }, null, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, BLACKBERRY6);// (Manufacturer.BLACKBERRY, OperatingSystem.BLACKBERRY, 6, "BlackBerry 6", new const std::string&[]{ "Version/6" }, null, DeviceType.MOBILE, null),

	ZCENUM_K(OperatingSystem, BLACKBERRY_TABLET);// (Manufacturer.BLACKBERRY, null, 100, "BlackBerry Tablet OS", new const std::string&[]{ "RIM Tablet OS" }, null, DeviceType.TABLET, null),

	ZCENUM_K(OperatingSystem, ROKU);// (Manufacturer.ROKU, null, 1, "Roku OS", new const std::string&[]{ "Roku" }, null, DeviceType.DMR, null),

	/**
	 * Proxy server that hides the original user-agent.
	 * ggpht.com = Gmail proxy server
	 */
	ZCENUM_K(OperatingSystem, PROXY);// (Manufacturer.OTHER, null, 10, "Proxy", new const std::string&[]{ "ggpht.com" }, null, DeviceType.UNKNOWN, null),

	ZCENUM_K(OperatingSystem, UNKNOWN_MOBILE);// (Manufacturer.OTHER, null, 3, "Unknown mobile", new const std::string&[]{ "Mobile" }, null, DeviceType.MOBILE, null),
	ZCENUM_K(OperatingSystem, UNKNOWN_TABLET);// (Manufacturer.OTHER, null, 4, "Unknown tablet", new const std::string&[]{ "Tablet" }, null, DeviceType.TABLET, null),
	ZCENUM_K(OperatingSystem, UNKNOWN);// (Manufacturer.OTHER, null, 1, "Unknown", new const std::string&[0], null, DeviceType.UNKNOWN, null);

private:
	short m_id;
	std::string m_name;
	std::vector<std::string> m_aliases;
	std::vector<std::string> m_excludeList; // don't match when these values are in the agent-string
	Manufacturer::ptr m_manufacturer;
	DeviceType::ptr m_deviceType;
	OperatingSystem::ptr m_parent;
	std::vector<OperatingSystem::ptr> m_children;
	std::string m_versionRegEx;
	inline static std::vector<OperatingSystem::ptr> topLevelOperatingSystems;
public:
	OperatingSystem(int index, const char* key, Manufacturer::ptr  manufacturer, OperatingSystem::ptr parent, int versionId, const std::string & name,
		const std::vector<std::string>&aliases,
		const std::vector<std::string>&exclude, DeviceType::ptr  deviceType, const std::string & versionRegexString)
		:ZcEnumBase(index, key)
		, m_manufacturer(manufacturer)
		, m_parent(parent)
		//,m_children(children)
		, m_id((manufacturer->getId() << 8) + (uint8_t)versionId)
		, m_name(name)
		, m_aliases(Utils::toLowerCase(aliases))
		, m_excludeList(Utils::toLowerCase(exclude))
		, m_deviceType(deviceType)
		, m_versionRegEx(versionRegexString)
	{
		if (!m_parent)
			addTopLevelOperatingSystem(this);
		else
			m_parent->m_children.push_back(this);
	}

	// create collection of top level operating systems during initialization
	static void addTopLevelOperatingSystem(const OperatingSystem::ptr & os) {
		topLevelOperatingSystems.push_back(os);
	}

	short getId() const {
		return m_id;
	}

	const std::string& getName() const {
		return m_name;
	}

	DeviceType::ptr getDeviceType()const {
		return m_deviceType;
	}

	/*
	 * Gets the top level grouping operating system
	 */
	OperatingSystem::ptr getGroup()const {
		return m_parent->getGroup();
	}

	/**
	 * Returns the m_manufacturer of the operating system
	 * @return the m_manufacturer
	 */
	Manufacturer::ptr getManufacturer()const {
		return m_manufacturer;
	}

	/**
	 * Checks if the given user-agent string matches to the operating system.
	 * Only checks for one specific operating system.
	 * @param agentString User-agent string as provided in the request.
	 * @return boolean
	 */
	bool isInUserAgentString(const std::string & agentString)
	{
		if (agentString.empty()) {
			return false;
		}
		std::string  str = agentString;
		auto agentLowerCaseString = Utils::toLowerCase(str);
		return isInUserAgentStringLowercase(agentLowerCaseString.data());
	}

	bool isInUserAgentStringLowercase(const std::string & agentLowerCaseString) {
		return Utils::contains(agentLowerCaseString, m_aliases);
	}

	/**
	 * Checks if the given user-agent does not contain one of the tokens which should not match.
	 * In most cases there are no excluding tokens, so the impact should be small.
	 * @param agentLowerCaseString Lower case version of the user-agent string
	 * @return true or false
	 */
	bool containsExcludeTokenLowercase(const std::string & agentLowerCaseString) {
		return Utils::contains(agentLowerCaseString, m_excludeList);
	}

	OperatingSystem::ptr checkUserAgentLowercase(const std::string & agentStringLowercase) {
		if (isInUserAgentStringLowercase(agentStringLowercase)) {
			if (!m_children.empty()) {
				for (OperatingSystem::ptr childOperatingSystem : this->m_children) {
					OperatingSystem::ptr match = childOperatingSystem->checkUserAgentLowercase(agentStringLowercase);
					if (match) {
						return match;
					}
				}
			}
			// if m_children didn't match we continue checking the current to prevent false positives
			if (!this->containsExcludeTokenLowercase(agentStringLowercase)) {
				return this;
			}

		}
		return nullptr;
	}

	/**
	 * Parses user agent string and returns the best match.
	 * Returns OperatingSystem.UNKNOWN if there is no match.
	 * @param agentString User-agent string as provided in the request.
	 * @return OperatingSystem enum
	 */
	static OperatingSystem::ptr parseUserAgentString(const std::string & agentString)
	{
		return parseUserAgentString(agentString, topLevelOperatingSystems);
	}

	static OperatingSystem::ptr parseUserAgentLowercaseString(const std::string & agentString)
	{
		if (agentString.empty()) {
			return &OperatingSystem::UNKNOWN;
		}
		return parseUserAgentLowercaseString(agentString, topLevelOperatingSystems);
	}

	/**
	 * Parses the user agent string and returns the best match for the given operating systems.
	 * Returns OperatingSystem.UNKNOWN if there is no match.
	 * Be aware that if the order of the provided operating systems is incorrect or the set is too limited it can lead to false matches!
	 * @param agentString User-agent string as provided in the request.
	 * @return OperatingSystem enum
	 */
	static OperatingSystem::ptr parseUserAgentString(const std::string & agentString, const std::vector<OperatingSystem::ptr>&operatingSystems)
	{
		if (agentString.empty()) {
			auto agentLowercaseString = Utils::toLowerCase(agentString);
			return parseUserAgentLowercaseString(agentLowercaseString.data(), operatingSystems);
		}
		return &OperatingSystem::UNKNOWN;
	}

public:
	static OperatingSystem::ptr parseUserAgentLowercaseString(const std::string & agentLowercaseString, const std::vector<OperatingSystem::ptr>&operatingSystems) {
		for (auto& operatingSystem : operatingSystems)
		{
			auto match = operatingSystem->checkUserAgentLowercase(agentLowercaseString);
			if (match) {
				return match; // either current operatingSystem or a child object
			}
		}
		return &OperatingSystem::UNKNOWN;
	}
public:
	/**
	 * Returns the enum constant of this type with the specified id.
	 * Throws IllegalArgumentException if the value does not exist.
	 * @param id Id value of the operating system.
	 * @return OperatingSystem enum
	 */
	static OperatingSystem::ptr valueOf(short id) {
		for (auto operatingSystem : OperatingSystem::values())
		{
			if (operatingSystem->getId() == id)
				return operatingSystem;
		}
		return nullptr;
	}

	std::string toString()const
	{
		return m_name;
	}
};
