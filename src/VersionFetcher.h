#pragma once

#include "Version.h"

#include <memory>
#include <map>
#include <regex>

/**
 * Interaface that gets string and returns extrancted version 
 * @author alexr
 */
class VersionFetcher {
public:
	using ptr = std::shared_ptr<VersionFetcher>;
public:
	virtual Version version(const std::string& str) = 0;
};

/**
 * Extracts version from provided UserAgent string using pattern.  
 * @author alexr
 */
class PatternBasedVersionFetcher : public VersionFetcher {
private:
	std::regex m_pattern;	//regex string
public:
	PatternBasedVersionFetcher(const std::string & pattern);

	PatternBasedVersionFetcher(const std::regex& pattern);

	Version version(const std::string& userAgentString)override;
protected:
	Version createVersion(const std::smatch& matcher);
};

/**
 * Implementation of {@link VersionFetcher} that holds a list of other {@link VersionFetcher}
 * and calls them sequentially until any of them manages to find version.  
 * @author alexr
 */
class SequentialVersionFetcher : public VersionFetcher {
private:
	std::vector<VersionFetcher::ptr> fetchers;
public:
	SequentialVersionFetcher(const std::initializer_list<VersionFetcher::ptr>& list);

	Version version(const std::string& str)override;
};


/**
 * Sometimes version of something is not written clearly in User-Agent string. 
 * However it is possible to extract version of other component that can be
 * mapped to needed version. Concrete example is discovery of version of Safari
 * browser by version of Webkit.  
 * @author alexr
 */
class VersionFetcherFromMap : public PatternBasedVersionFetcher
{
private:
	std::map<std::string, Version> m_versions;
public:
	VersionFetcherFromMap(const std::regex& pattern, const std::map<std::string, Version>& versions);
protected:
	Version createVersion(const std::smatch& matcher);
};



