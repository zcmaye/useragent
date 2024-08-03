#pragma once

#include <string>
#include <iosfwd>
//#include "macro.hpp"

class Version
{
private:
	std::string m_version;
	std::string m_majorVersion;
	std::string m_minorVersion;
public:
	Version() = default;

	Version(const std::string& version, const std::string& majorVersion, const std::string& minorVersion)
		:m_version(version)
		,m_majorVersion(majorVersion)
		,m_minorVersion(minorVersion)
	{

	}

	const std::string&  getVersion()const{
		return m_version;
	}

	const std::string&  getMajorVersion()const{
		return m_majorVersion;
	}

	const std::string&  getMinorVersion()const{
		return m_minorVersion;
	}

	const std::string& toString()const {
		return m_version;
	}

	size_t hashCode()const {
		std::string str = m_version + m_majorVersion + m_minorVersion;
		return std::hash<std::string>()(str);
	}

	bool isNull()const {
		return m_version.empty() && m_majorVersion.empty() && m_minorVersion.empty();
	}

	bool operator==(const Version& other)const;

	int compare(const Version& other)const;

	friend std::ostream& operator<<(std::ostream& os, const Version& version);
};

