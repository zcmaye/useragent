#pragma once

#include "Browser.h"
#include "OperatingSystem.h"

#include <string>
#include <memory>

/**
 * Container class for user-agent information with operating system and browser details. 
 * Can decode user-agent strings.
 * <br><br>
 * Resources:<br>
 * <a href="http://www.useragentstring.com">User Agent String.Com</a><br>
 * <a href="http://www.myuseragentstring.com/">My User Agent String</a><br>
 * <a href="http://www.user-agents.org">List of User-Agents</a><br>
 * <a href="http://user-agent-string.info">user-agent-string.info</a><br>
 * <a href="http://www.zytrax.com/tech/web/browser_ids.htm">Browser ID (User-Agent) Strings</a><br>
 * <a href="http://www.zytrax.com/tech/web/mobile_ids.html">Mobile Browser ID (User-Agent) Strings</a><br>
 * <a href="http://www.joergkrusesweb.de/internet/browser/user-agent.html">Browser-Kennungen</a><br>
 * <a href="http://deviceatlas.com/devices">Device Atlas - Mobile Device Intelligence</a><br>
 * <a href="http://mobileopera.com/reference/ua">Mobile Opera user-agent strings</a><br>
 * <a href="http://en.wikipedia.org/wiki/S60_platform">S60 platform</a><br>
 * <a href="http://msdn.microsoft.com/en-us/library/ms537503.aspx">Understanding User-Agent Strings</a><br>
 * <a href="http://developer.sonyericsson.com/site/global/docstools/browsing/p_browsing.jsp">Sony Ericsson Web Docs & Tools</a><br>
 * <a href="http://developer.apple.com/internet/safari/faq.html#anchor2">What is the Safari user-agent string</a><br>
 * <a href="http://www.pgts.com.au/pgtsj/pgtsj0208c.html">List of User Agent Strings</a><br>
 * <a href="http://blogs.msdn.com/iemobile/archive/2006/08/03/Detecting_IE_Mobile.aspx">Detecting Internet Explorer Mobile's User-Agent on the server</a>
 */

/**
 * @author	zcmaye 
 *
 */
class UserAgent
{
	using ptr = std::shared_ptr<UserAgent>;
private:
	OperatingSystem::ptr m_operatingSystem;
	Browser::ptr m_browser;
	int m_id;
	std::string m_userAgentString;
public:	
	
	/**
	 * This constructor is created for APIs that require default constructor 
	 * and should never be used directly.
	 * @deprecated Use {@link #UserAgent(OperatingSystem, Browser)} 
	 */
	UserAgent(const OperatingSystem::ptr& operatingSystem,const  Browser::ptr& browser)
		: m_operatingSystem(operatingSystem)
		, m_browser(browser)
		, m_id((operatingSystem->getId() << 16) + browser->getId())
	{
	}
	
    UserAgent(const std::string& userAgentString)
		:m_userAgentString(userAgentString)
	{ 
		std::string userAgentLowercaseString = Utils::toLowerCase(userAgentString);
		m_browser = Browser::parseUserAgentLowercaseString(userAgentLowercaseString);

		// BOTs don't have an interesting OS for us
		if (m_browser != &Browser::BOT)
			m_operatingSystem = OperatingSystem::parseUserAgentLowercaseString(userAgentLowercaseString);

        m_id = ((m_operatingSystem->getId() << 16) + m_browser->getId());
    }

	
	/**
	 * @param userAgentString  User-agent string as provided in the request.
	 * @return UserAgent
	 */
	static UserAgent::ptr parse(const std::string& userAgentString) {		
		return std::make_shared<UserAgent>(userAgentString);
	}

	/**
	 * Detects the detailed version information of the browser. Depends on the userAgent to be available. 
	 * Use it only after using UserAgent(String) or UserAgent.parseUserAgent(String). 
	 * Returns null if it can not detect the version information.
	 * @return Version
	 */
	Version getBrowserVersion() {
		return m_browser->getVersion(m_userAgentString);
	}
	
	/**
	 * @return the system
	 */
	const OperatingSystem::ptr& getOperatingSystem()const {
		return m_operatingSystem;
	}

	/**
	 * @return the browser
	 */
	Browser::ptr getBrowser()const {
		return m_browser;
	}

	/**
	 * Returns an unique integer value of the operating system and browser combination
	 * @return the id
	 */
	int getId()const {
		return m_id;
	}

	/**
	 * Combined string representation of both enums
	 * Windows 10-Chrome 12
	 */
	std::string toString() {
		return m_operatingSystem->toString() + std::string("-") + m_browser->toString();
	}
	
	/**
	 * Returns UserAgent based on specified unique id
	 * @param id Id value of the user agent.
	 * @return UserAgent
	 */
	/*static UserAgent valueOf(int id)
	{
		OperatingSystem::ptr operatingSystem = OperatingSystem::valueOf((short) (id >> 16));
		auto browser = Browser::valueOf( (short) (id & 0x0FFFF));
		return UserAgent(operatingSystem,browser);
	}*/
	
	/**
	 * Returns UserAgent based on combined string representation
	 * @param name Name of the user agent.
	 * @return UserAgent
	 */
	/*static UserAgent valueOf(const std::string& name)
	{
		if (name.empty())
            throw new  std::runtime_error("Name is null");
		
		auto elements =Utils::split(name,'-');
		
		if (elements.size() == 2)
		{
			auto operatingSystem = OperatingSystem::valueOf(std::stoi(elements[0]));
			auto browser = Browser::valueOf(std::stoi(elements[1]));
			return UserAgent(operatingSystem,browser);
		}
		
		throw new std::runtime_error( "Invalid string for userAgent " + name);
	}*/

	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	int hashCode()const {

	//	int prime = 31;
	//	int result = 1;
	//	result = prime * result + ((browser == null) ? 0 : browser.hashCode());
	//	result = prime * result + id;
	//	result = prime * result
	//			+ ((operatingSystem == null) ? 0 : operatingSystem.hashCode());
	//	return result;
		return 0;
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	bool equals(const UserAgent& other) {
		if (!m_browser) {
			if (!other.m_browser)
				return false;
		} else if (m_browser != other.m_browser)
			return false;
		if (m_id != other.m_id)
			return false;
		if (m_operatingSystem == nullptr) {
			if (other.m_operatingSystem != nullptr)
				return false;
		} else if (m_operatingSystem != other.m_operatingSystem)
			return false;
		return true;
	}	
	
};
