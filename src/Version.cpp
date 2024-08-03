#include "Version.h"
#include "Utils.h"

#include <iostream>

bool Version::operator==(const Version& other)const {
		if (m_majorVersion.empty()) {
			if (!other.m_majorVersion.empty())
				return false;
		}
		else if (m_majorVersion != other.m_majorVersion)
			return false;
		if (m_minorVersion.empty()) {
			if (!other.m_minorVersion.empty())
				return false;
		}
		else if (m_minorVersion != other.m_minorVersion)
			return false;
		if (m_version.empty()) {
			if (!other.m_version.empty())
				return false;
		}
		else if (m_version != other.m_version)
			return false;
		return true;
	}

int Version::compare(const Version& other)const
{
	if (other.isNull()) {
		return 1;
	}

	auto versionParts = Utils::split(m_version, '\\.');
	auto otherVersionParts = Utils::split(other.m_version, '\\.');

	for (int i = 0; i < std::min(versionParts.size(), otherVersionParts.size()); i++) {
		if (versionParts[i].size() == otherVersionParts[i].size()) {
			int comparisonResult = versionParts[i].compare(otherVersionParts[i]);
			if (comparisonResult == 0) {
				continue;
			}
			else {
				return comparisonResult;
			}
		}
		else {
			return versionParts[i].length() > otherVersionParts[i].length() ? 1 : -1;
		}
	}

	if (versionParts.size() > otherVersionParts.size()) {
		return 1;
	}
	else if (versionParts.size() < otherVersionParts.size()) {
		return -1;
	}
	else {
		return 0;
	}
}

std::ostream& operator<<(std::ostream& os, const Version& version)
{
	os << version.m_version;
	return os;
}

