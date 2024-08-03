#include "VersionFetcher.h"


/**
 * Extracts version from provided UserAgent string using pattern.
 * @author alexr
 */
PatternBasedVersionFetcher::PatternBasedVersionFetcher(const std::string& pattern)
	:m_pattern(pattern)
{
}

PatternBasedVersionFetcher::PatternBasedVersionFetcher(const std::regex& pattern)
	:m_pattern(pattern)
{
}


Version PatternBasedVersionFetcher::version(const std::string& userAgentString){
	std::smatch match;
	bool ok = std::regex_search(userAgentString, match, m_pattern);
	if (!ok) {
		return {};
	}
	return createVersion(match);
}
Version PatternBasedVersionFetcher::createVersion(const std::smatch& matcher) {
	std::string fullVersionString = matcher[0];
	std::string majorVersion = matcher[1];
	std::string minorVersion = "0";
	if (matcher.size() > 2) // usually but not always there is a minor version
		minorVersion = matcher[2];
	return Version(fullVersionString, majorVersion, minorVersion);
}

/**
 * Implementation of {@link VersionFetcher} that holds a list of other {@link VersionFetcher}
 * and calls them sequentially until any of them manages to find version.
 * @author alexr
 */
SequentialVersionFetcher::SequentialVersionFetcher(const std::initializer_list<VersionFetcher::ptr>& list) {
	for (auto& f : list) {
		fetchers.push_back(f);
	}
}

Version SequentialVersionFetcher::version(const std::string& str){
	for (VersionFetcher::ptr& fetcher : fetchers) {
		Version version = fetcher->version(str);
		if (!version.isNull()) {
			return version;
		}
	}
	return {};
}

/**
 * Sometimes version of something is not written clearly in User-Agent string.
 * However it is possible to extract version of other component that can be
 * mapped to needed version. Concrete example is discovery of version of Safari
 * browser by version of Webkit.
 * @author alexr
 */
VersionFetcherFromMap::VersionFetcherFromMap(const std::regex& pattern, const std::map<std::string, Version>& versions)
	:PatternBasedVersionFetcher(pattern)
	, m_versions(versions)
{
}

Version VersionFetcherFromMap::createVersion(const std::smatch& matcher) {
	return m_versions[matcher[0]];
}

