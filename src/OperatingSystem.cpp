#include "OperatingSystem.h"

/**
 * Windows Mobile / Windows CE. Exact version unknown.
 */
ZCENUM_V(OperatingSystem, WINDOWS, &Manufacturer::MICROSOFT, {}, 1, "Windows", { "Windows" }, { "Palm", "ggpht.com" }, & DeviceType::COMPUTER, {});// catch the rest of older Windows systems {95, NT,...)
ZCENUM_V(OperatingSystem, WINDOWS_10, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 24, "Windows 10", { "Windows NT 6.4", "Windows NT 10" }, {}, & DeviceType::COMPUTER, {});// before Win, yes, Windows 10 is called 6.4 LOL
ZCENUM_V(OperatingSystem, WINDOWS_81, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 23, "Windows 8.1", { "Windows NT 6.3" }, {}, & DeviceType::COMPUTER, {});// before Win, yes, Windows 8.1 is called 6.3 LOL
ZCENUM_V(OperatingSystem, WINDOWS_8, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 22, "Windows 8", { "Windows NT 6.2" }, { "Xbox","Xbox One" }, & DeviceType::COMPUTER, {});// before Win, yes, Windows 8 is called 6.2 LOL
ZCENUM_V(OperatingSystem, WINDOWS_7, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 21, "Windows 7", { "Windows NT 6.1" }, { "Xbox","Xbox One" }, & DeviceType::COMPUTER, {});// before Win, yes, Windows 7 is called 6.1 LOL
ZCENUM_V(OperatingSystem, WINDOWS_VISTA, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 20, "Windows Vista", { "Windows NT 6" }, { "Xbox","Xbox One" }, & DeviceType::COMPUTER, {});// before Win
ZCENUM_V(OperatingSystem, WINDOWS_2000, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 15, "Windows 2000", { "Windows NT 5.0" }, {}, & DeviceType::COMPUTER, {});// before Win
ZCENUM_V(OperatingSystem, WINDOWS_XP, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 10, "Windows XP", { "Windows NT 5" }, { "ggpht.com" }, & DeviceType::COMPUTER, {});// before Win, 5.1 and 5.2 are basically XP systems
ZCENUM_V(OperatingSystem, WINDOWS_10_MOBILE, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 54, "Windows 10 Mobile", { "Windows Phone 10" }, {}, & DeviceType::MOBILE, {});
ZCENUM_V(OperatingSystem, WINDOWS_PHONE8_1, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 53, "Windows Phone 8.1", { "Windows Phone 8.1" }, {}, & DeviceType::MOBILE, {});// before Win
ZCENUM_V(OperatingSystem, WINDOWS_PHONE8, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 52, "Windows Phone 8", { "Windows Phone 8" }, {}, & DeviceType::MOBILE, {});// before Win
ZCENUM_V(OperatingSystem, WINDOWS_MOBILE7, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 51, "Windows Phone 7", { "Windows Phone OS 7" }, {}, & DeviceType::MOBILE, {});// should be Windows Phone 7 but to keep it compatible we'll leave the name as is.
ZCENUM_V(OperatingSystem, WINDOWS_MOBILE, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 50, "Windows Mobile", { "Windows CE" }, {}, & DeviceType::MOBILE, {});// before Win
ZCENUM_V(OperatingSystem, WINDOWS_98, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 5, "Windows 98", { "Windows 98","Win98" }, { "Palm" }, & DeviceType::COMPUTER, {});// before Win 
ZCENUM_V(OperatingSystem, XBOX_OS, &Manufacturer::MICROSOFT, &OperatingSystem::WINDOWS, 62, "Xbox OS", { "xbox" }, {}, & DeviceType::GAME_CONSOLE, {});

// for Google user-agent, see https://developer.chrome.com/multidevice/user-agent
ZCENUM_V(OperatingSystem, ANDROID, &Manufacturer::GOOGLE, {}, 0, "Android", { "Android" }, { "Ubuntu" }, & DeviceType::MOBILE, {});
ZCENUM_V(OperatingSystem, ANDROID8, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 8, "Android 8.x", { "Android 8", "Android-8" }, { "glass" }, & DeviceType::MOBILE, {});
ZCENUM_V(OperatingSystem, ANDROID8_TABLET, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID8, 80, "Android 8.x Tablet", { "Android 8", "Android-8" }, { "mobile", "glass" }, & DeviceType::TABLET, {});
ZCENUM_V(OperatingSystem, ANDROID7, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 7, "Android 7.x", { "Android 7", "Android-7" }, { "glass" }, & DeviceType::MOBILE, {});
ZCENUM_V(OperatingSystem, ANDROID7_TABLET, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID7, 70, "Android 7.x Tablet", { "Android 7", "Android-7" }, { "mobile", "glass" }, & DeviceType::TABLET, {});
ZCENUM_V(OperatingSystem, ANDROID6, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 6, "Android 6.x", { "Android 6", "Android-6" }, { "glass" }, & DeviceType::MOBILE, {});
ZCENUM_V(OperatingSystem, ANDROID6_TABLET, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID6, 60, "Android 6.x Tablet", { "Android 6", "Android-6" }, { "mobile", "glass" }, & DeviceType::TABLET, {});
ZCENUM_V(OperatingSystem, ANDROID5, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 5, "Android 5.x", { "Android 5", "Android-5" }, { "glass" }, & DeviceType::MOBILE, {});
ZCENUM_V(OperatingSystem, ANDROID5_TABLET, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID5, 50, "Android 5.x Tablet", { "Android 5", "Android-5" }, { "mobile", "glass" }, & DeviceType::TABLET, {});
ZCENUM_V(OperatingSystem, ANDROID4, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 4, "Android 4.x", { "Android 4", "Android-4" }, { "glass", "ubuntu" }, & DeviceType::MOBILE, {});
ZCENUM_V(OperatingSystem, ANDROID4_TABLET, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID4, 40, "Android 4.x Tablet", { "Android 4", "Android-4" }, { "mobile", "glass", "ubuntu" }, & DeviceType::TABLET, {});
ZCENUM_V(OperatingSystem, ANDROID4_WEARABLE, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 400, "Android 4.x", { "Android 4" }, { "ubuntu" }, & DeviceType::WEARABLE, {});
ZCENUM_V(OperatingSystem, ANDROID3_TABLET, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 30, "Android 3.x Tablet", { "Android 3" }, {}, & DeviceType::TABLET, {});// as long as there are not Android 3.x phones this should be enough
ZCENUM_V(OperatingSystem, ANDROID2, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 2, "Android 2.x", { "Android 2" }, {}, & DeviceType::MOBILE, {});
ZCENUM_V(OperatingSystem, ANDROID2_TABLET, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID2, 20, "Android 2.x Tablet", { "Kindle Fire", "GT-P1000","SCH-I800" }, {}, & DeviceType::TABLET, {});
ZCENUM_V(OperatingSystem, ANDROID1, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 1, "Android 1.x", { "Android 1" }, {}, & DeviceType::MOBILE, {});
/**
 * Generic Android mobile device without OS version number information
 */
ZCENUM_V(OperatingSystem, ANDROID_MOBILE, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 11, "Android Mobile", { "Mobile" }, { "ubuntu" }, & DeviceType::MOBILE, {});
/**
 * Generic Android tablet device without OS version number information
 */
ZCENUM_V(OperatingSystem, ANDROID_TABLET, &Manufacturer::GOOGLE, &OperatingSystem::ANDROID, 12, "Android Tablet", { "Tablet" }, {}, & DeviceType::TABLET, {});

/**
 * 	Chrome OS by Google, mostly used on Chromebooks and Chromeboxes
 */
ZCENUM_V(OperatingSystem, CHROME_OS, &Manufacturer::GOOGLE, {}, 1000, "Chrome OS", { "CrOS" }, {}, & DeviceType::COMPUTER, {});
/**
 * PalmOS, exact version unkown
 */
ZCENUM_V(OperatingSystem, WEBOS, &Manufacturer::HP, {}, 11, "WebOS", { "webOS" }, {}, & DeviceType::MOBILE, {});
ZCENUM_V(OperatingSystem, PALM, &Manufacturer::HP, {}, 10, "PalmOS", { "Palm" }, {}, & DeviceType::MOBILE, {});
ZCENUM_V(OperatingSystem, MEEGO, &Manufacturer::NOKIA, {}, 3, "MeeGo", { "MeeGo" }, {}, & DeviceType::MOBILE, {});

/**
 * iOS4, with the release of the iPhone 4, Apple renamed the OS to iOS.
 */
ZCENUM_V(OperatingSystem, IOS, &Manufacturer::APPLE, {}, 2, "iOS", { "iPhone", "like Mac OS X" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS11_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 92, "iOS 11 (iPhone)", { "iPhone OS 11" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS10_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 91, "iOS 10 (iPhone)", { "iPhone OS 10" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS9_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 90, "iOS 9 (iPhone)", { "iPhone OS 9" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS8_4_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 49, "iOS 8.4 (iPhone)", { "iPhone OS 8_4" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS8_3_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 48, "iOS 8.3 (iPhone)", { "iPhone OS 8_3" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS8_2_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 47, "iOS 8.2 (iPhone)", { "iPhone OS 8_2" }, {}, & DeviceType::MOBILE, {});// version that added Apple Watch support
ZCENUM_V(OperatingSystem, iOS8_1_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 46, "iOS 8.1 (iPhone)", { "iPhone OS 8_1" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS8_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 45, "iOS 8 (iPhone)", { "iPhone OS 8" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS7_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 44, "iOS 7 (iPhone)", { "iPhone OS 7" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS6_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 43, "iOS 6 (iPhone)", { "iPhone OS 6" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS5_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 42, "iOS 5 (iPhone)", { "iPhone OS 5" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, iOS4_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 41, "iOS 4 (iPhone)", { "iPhone OS 4" }, {}, & DeviceType::MOBILE, {});// before MAC_OS_X_IPHONE for all older versions
ZCENUM_V(OperatingSystem, MAC_OS_X_IPAD, &Manufacturer::APPLE, &OperatingSystem::IOS, 50, "Mac OS X (iPad)", { "iPad" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, iOS11_IPAD, &Manufacturer::APPLE, &OperatingSystem::MAC_OS_X_IPAD, 60, "iOS 11 (iPad)", { "OS 11" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, iOS10_IPAD, &Manufacturer::APPLE, &OperatingSystem::MAC_OS_X_IPAD, 59, "iOS 10 (iPad)", { "OS 10" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, iOS9_IPAD, &Manufacturer::APPLE, &OperatingSystem::MAC_OS_X_IPAD, 58, "iOS 9 (iPad)", { "OS 9" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, iOS8_4_IPAD, &Manufacturer::APPLE, &OperatingSystem::MAC_OS_X_IPAD, 57, "iOS 8.4 (iPad)", { "OS 8_4" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, iOS8_3_IPAD, &Manufacturer::APPLE, &OperatingSystem::MAC_OS_X_IPAD, 56, "iOS 8.3 (iPad)", { "OS 8_3" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, iOS8_2_IPAD, &Manufacturer::APPLE, &OperatingSystem::MAC_OS_X_IPAD, 55, "iOS 8.2 (iPad)", { "OS 8_2" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, iOS8_1_IPAD, &Manufacturer::APPLE, &OperatingSystem::MAC_OS_X_IPAD, 54, "iOS 8.1 (iPad)", { "OS 8_1" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, iOS8_IPAD, &Manufacturer::APPLE, &OperatingSystem::MAC_OS_X_IPAD, 53, "iOS 8 (iPad)", { "OS 8_0" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, iOS7_IPAD, &Manufacturer::APPLE, &OperatingSystem::MAC_OS_X_IPAD, 52, "iOS 7 (iPad)", { "OS 7" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, iOS6_IPAD, &Manufacturer::APPLE, &OperatingSystem::MAC_OS_X_IPAD, 51, "iOS 6 (iPad)", { "OS 6" }, {}, & DeviceType::TABLET, {});// before Mac OS X
ZCENUM_V(OperatingSystem, MAC_OS_X_IPHONE, &Manufacturer::APPLE, &OperatingSystem::IOS, 40, "Mac OS X (iPhone)", { "iPhone" }, {}, & DeviceType::MOBILE, {});// before Mac OS X
ZCENUM_V(OperatingSystem, MAC_OS_X_IPOD, &Manufacturer::APPLE, &OperatingSystem::IOS, 30, "Mac OS X (iPod)", { "iPod" }, {}, & DeviceType::MOBILE, {});// before Mac OS X

ZCENUM_V(OperatingSystem, MAC_OS_X, &Manufacturer::APPLE, {}, 10, "Mac OS X", { "Mac OS X" , "CFNetwork" }, {}, & DeviceType::COMPUTER, {});// before Mac	

/**
 * Older Mac OS systems before Mac OS X
 */
ZCENUM_V(OperatingSystem, MAC_OS, &Manufacturer::APPLE, {}, 1, "Mac OS", { "Mac" }, {}, & DeviceType::COMPUTER, {});// older Mac OS systems

/**
 * Linux based Maemo software platform by Nokia. Used in the N900 phone. http://maemo.nokia.com/
 */
ZCENUM_V(OperatingSystem, MAEMO, &Manufacturer::NOKIA, {}, 2, "Maemo", { "Maemo" }, {}, & DeviceType::MOBILE, {});

/**
 * Bada is a mobile operating system being developed by Samsung Electronics.
 */
ZCENUM_V(OperatingSystem, BADA, &Manufacturer::SAMSUNG, {}, 2, "Bada", { "Bada" }, {}, & DeviceType::MOBILE, {});

/**
 *  Google TV uses Android 2.x or 3.x but doesn't identify itself as Android.
 */
ZCENUM_V(OperatingSystem, GOOGLE_TV,&Manufacturer::GOOGLE, {}, 100, "Android (Google TV)", { "GoogleTV" }, {},&DeviceType::DMR, {} );

/**
 * Tizen is a Linux Foundation project. Mostly used by various Samsung devices.
 * @see <a href="https://wiki.tizen.org/Tizen_Browser">Tizen Browser user-agent format</a>
 * @see <a href="http://developer.samsung.com/technical-doc/view.do?v=T000000203">Samsung Internet User-Agent std::string Format</a>
 * Not specified how devices like car display or a fridge would identify themselves.
 */
ZCENUM_V(OperatingSystem, TIZEN,&Manufacturer::LINUX_FOUNDATION, {}, 101, "Tizen", { "Tizen" }, {},&DeviceType::UNKNOWN, {} );
ZCENUM_V(OperatingSystem, TIZEN3,&Manufacturer::LINUX_FOUNDATION, &OperatingSystem::TIZEN, 30, "Tizen 3", { "Tizen 3." }, {},&DeviceType::UNKNOWN, {} );
ZCENUM_V(OperatingSystem, TIZEN3_MOBILE,&Manufacturer::LINUX_FOUNDATION, &OperatingSystem::TIZEN3, 31, "Tizen 3 (Mobile)", { "mobile" }, {},&DeviceType::MOBILE, {} );
ZCENUM_V(OperatingSystem, TIZEN3_TV,&Manufacturer::LINUX_FOUNDATION, &OperatingSystem::TIZEN3, 32, "Tizen 3 (SmartTV)", { "Smart-TV", " TV " }, {},&DeviceType::DMR, {} );
ZCENUM_V(OperatingSystem, TIZEN2,&Manufacturer::LINUX_FOUNDATION, &OperatingSystem::TIZEN, 20, "Tizen 2", { "Tizen 2." }, {},&DeviceType::UNKNOWN, {} );
ZCENUM_V(OperatingSystem, TIZEN2_MOBILE,&Manufacturer::LINUX_FOUNDATION, &OperatingSystem::TIZEN2, 21, "Tizen 2 (Mobile)", { "mobile" }, {},&DeviceType::MOBILE, {} );
ZCENUM_V(OperatingSystem, TIZEN2_TV,&Manufacturer::LINUX_FOUNDATION, &OperatingSystem::TIZEN2, 22, "Tizen 2 (SmartTV)", { "Smart-TV"," TV " }, {},&DeviceType::DMR, {} );
ZCENUM_V(OperatingSystem, TIZEN_MOBILE,&Manufacturer::LINUX_FOUNDATION, &OperatingSystem::TIZEN, 10, "Tizen (mobile)", { "mobile" }, {},&DeviceType::MOBILE, {} );

/**
 * Various Linux based operating systems.
 */
ZCENUM_V(OperatingSystem, KINDLE,&Manufacturer::AMAZON, {}, 1, "Linux (Kindle)", { "Kindle" }, {},&DeviceType::TABLET, {} );
ZCENUM_V(OperatingSystem, KINDLE3,&Manufacturer::AMAZON, &OperatingSystem::KINDLE, 30, "Linux (Kindle 3)", { "Kindle/3" }, {},&DeviceType::TABLET, {} );
ZCENUM_V(OperatingSystem, KINDLE2,&Manufacturer::AMAZON, &OperatingSystem::KINDLE, 20, "Linux (Kindle 2)", { "Kindle/2" }, {},&DeviceType::TABLET, {} );
ZCENUM_V(OperatingSystem, LINUX,&Manufacturer::OTHER, {}, 2, "Linux", { "Linux", "CamelHttpStream" }, {},&DeviceType::COMPUTER, {});// CamelHttpStream is being used by Evolution, an email client for Linux
ZCENUM_V(OperatingSystem, UBUNTU,&Manufacturer::CONONICAL, &OperatingSystem::LINUX, 1, "Ubuntu", { "ubuntu" }, {},&DeviceType::COMPUTER, {} );
ZCENUM_V(OperatingSystem, UBUNTU_TOUCH_MOBILE,&Manufacturer::CONONICAL, &OperatingSystem::UBUNTU, 200, "Ubuntu Touch (mobile)", { "mobile" }, {},&DeviceType::MOBILE, {} );
ZCENUM_V(OperatingSystem, LINUX_SMART_TV,&Manufacturer::OTHER, &OperatingSystem::LINUX, 21, "Linux (SmartTV)", { "SmartTv" }, {},&DeviceType::DMR, {} );

/**
 * Other Symbian OS versions
 */
ZCENUM_V(OperatingSystem, SYMBIAN,&Manufacturer::SYMBIAN, {}, 1, "Symbian OS", { "Symbian", "Series60" }, {},&DeviceType::MOBILE, {} );
/**
 * Symbian OS 9.x versions. Being used by Nokia (N71, N73, N81, N82, N91, N92, N95, ...)
 */
ZCENUM_V(OperatingSystem, SYMBIAN9,&Manufacturer::SYMBIAN, &OperatingSystem::SYMBIAN, 20, "Symbian OS 9.x", { "SymbianOS/9", "Series60/3" }, {},&DeviceType::MOBILE, {} );
/**
 * Symbian OS 8.x versions. Being used by Nokia (6630, 6680, 6681, 6682, N70, N72, N90).
 */
ZCENUM_V(OperatingSystem, SYMBIAN8,&Manufacturer::SYMBIAN, &OperatingSystem::SYMBIAN, 15, "Symbian OS 8.x", { "SymbianOS/8", "Series60/2.6", "Series60/2.8" }, {},&DeviceType::MOBILE, {} );
/**
 * Symbian OS 7.x versions. Being used by Nokia (3230, 6260, 6600, 6620, 6670, 7610);
 * Panasonic (X700, X800); Samsung (SGH-D720, SGH-D730) and Lenovo (P930).
 */
ZCENUM_V(OperatingSystem, SYMBIAN7,&Manufacturer::SYMBIAN, &OperatingSystem::SYMBIAN, 10, "Symbian OS 7.x", { "SymbianOS/7" }, {},&DeviceType::MOBILE, {} );
/**
 * Symbian OS 6.x versions.
 */
ZCENUM_V(OperatingSystem, SYMBIAN6,&Manufacturer::SYMBIAN, &OperatingSystem::SYMBIAN, 5, "Symbian OS 6.x", { "SymbianOS/6" }, {},&DeviceType::MOBILE, {} );
/**
 * Nokia's Series 40 operating system. Series 60 (S60) uses the Symbian OS.
 */
ZCENUM_V(OperatingSystem, SERIES40,&Manufacturer::NOKIA, {}, 1, "Series 40", { "Nokia6300" }, {},&DeviceType::MOBILE, {} );
/**
 * Proprietary operating system used for many Sony Ericsson phones.
 */
ZCENUM_V(OperatingSystem, SONY_ERICSSON,&Manufacturer::SONY_ERICSSON, {}, 1, "Sony Ericsson", { "SonyEricsson" }, {},&DeviceType::MOBILE, {});// after symbian, some SE phones use symbian
ZCENUM_V(OperatingSystem, SUN_OS,&Manufacturer::SUN, {}, 1, "SunOS", { "SunOS" }, {},&DeviceType::COMPUTER, {} );
ZCENUM_V(OperatingSystem, PSP,&Manufacturer::SONY, {}, 1, "Sony Playstation", { "Playstation" }, {},&DeviceType::GAME_CONSOLE, {} );
/**
 * Nintendo Wii game console.
 */
ZCENUM_V(OperatingSystem, WII,&Manufacturer::NINTENDO, {}, 1, "Nintendo Wii", { "Wii" }, {},&DeviceType::GAME_CONSOLE, {} );
/**
 * BlackBerryOS. The BlackBerryOS exists in different version. How relevant those versions are, is not clear.
 */
ZCENUM_V(OperatingSystem, BLACKBERRY,&Manufacturer::BLACKBERRY, {}, 1, "BlackBerryOS", { "BlackBerry" }, {},&DeviceType::MOBILE, {} );
ZCENUM_V(OperatingSystem, BLACKBERRY7,&Manufacturer::BLACKBERRY, &OperatingSystem::BLACKBERRY, 7, "BlackBerry 7", { "Version/7" }, {},&DeviceType::MOBILE, {} );
ZCENUM_V(OperatingSystem, BLACKBERRY6,&Manufacturer::BLACKBERRY, &OperatingSystem::BLACKBERRY, 6, "BlackBerry 6", { "Version/6" }, {},&DeviceType::MOBILE, {} );

ZCENUM_V(OperatingSystem, BLACKBERRY_TABLET,&Manufacturer::BLACKBERRY, {}, 100, "BlackBerry Tablet OS", { "RIM Tablet OS" }, {},&DeviceType::TABLET, {} );

ZCENUM_V(OperatingSystem, ROKU,&Manufacturer::ROKU, {}, 1, "Roku OS", { "Roku" }, {},&DeviceType::DMR, {} );

/**
 * Proxy server that hides the original user-agent.
 * ggpht.com = Gmail proxy server
 */
ZCENUM_V(OperatingSystem, PROXY,&Manufacturer::OTHER, {}, 10, "Proxy", { "ggpht.com" }, {},&DeviceType::UNKNOWN, {} );

ZCENUM_V(OperatingSystem, UNKNOWN_MOBILE,&Manufacturer::OTHER, {}, 3, "Unknown mobile", { "Mobile" }, {},&DeviceType::MOBILE, {} );
ZCENUM_V(OperatingSystem, UNKNOWN_TABLET,&Manufacturer::OTHER, {}, 4, "Unknown tablet", { "Tablet" }, {},&DeviceType::TABLET, {} );
ZCENUM_V(OperatingSystem, UNKNOWN,&Manufacturer::OTHER, {}, 1, "Unknown", {}, {},&DeviceType::UNKNOWN, {} );
