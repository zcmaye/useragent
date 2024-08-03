#pragma once

#include "BaseEnum.hpp"

/**
 * Enum constants classifying the different types of browsers which are common in user-agent strings
 * @author harald
 *
 */
//struct BrowserType 
ZCENUM_CLASS(BrowserType)
{
	ZCENUM_INIT(BrowserType);
	friend class Browser;
private:
	/**
	 * Standard web-browser
	 */
	ZCENUM_K(BrowserType,WEB_BROWSER);// ("Browser"),
	/**
	 * Special web-browser for mobile devices
	 */
	ZCENUM_K(BrowserType,MOBILE_BROWSER);// ("Browser (mobile)"),
	/**
	 * Text only browser like the good old Lynx
	 */
	ZCENUM_K(BrowserType,TEXT_BROWSER);// ("Browser (text only)"),
	/**
	 * Email client like Thunderbird
	 */
	ZCENUM_K(BrowserType,EMAIL_CLIENT);// ("Email Client"),
	/**
	 * Search robot, spider, crawler,...
	 */
	ZCENUM_K(BrowserType,ROBOT);// ("Robot"),
	/**
	 * Downloading tools
	 */
	ZCENUM_K(BrowserType,TOOL);// ("Downloading tool"),
	/**
	 * Application
	 */
	ZCENUM_K(BrowserType,APP);// ("Application"),
	ZCENUM_K(BrowserType,UNKNOWN);// ("unknown");
private:
	std::string m_name;

	BrowserType(int index,const char* key,const std::string& name)
		:ZcEnumBase(index,key)
		,m_name(name)
	{

	}
public:
	const std::string& getName() {
		return m_name;
	}
};

