#pragma once

#include <regex>
#include <string>
#include <vector>

struct Utils
{
	using StringList = std::vector<std::string>;

	static StringList split(const std::string& str,char delimiter)
	{
		StringList strs;
		size_t pos = 0,idx = 0;
		while(idx != std::string::npos) {
			idx = str.find(delimiter, pos);
			strs.emplace_back(str.substr(pos, idx - pos));
			pos = idx + 1;
		}
		return strs;
	}

	static char toUpper(char c)
	{
		if (c >= 'a' && c <= 'z')
			return c - 32;
		return c;
	}
	static char toLower(char c)
	{
		if (c >= 'A' && c <= 'Z')
			return c + 32;
		return c;
	}

	/**
	 * 正则匹配.
	 */
	static bool matches(const std::string& str, const std::regex& regex)
	{
		return 	std::regex_match(str, regex);
	}

	static std::string toLowerCase(const std::string& str) {
		std::string s;
		std::transform(str.begin(), str.end(),std::back_inserter(s), [](char c)
			{
				return toLower(c);
			});
		return s;
	}

	static std::string toUpperCase(const std::string& str) {
		std::string s;
		std::transform(str.begin(), str.end(),std::back_inserter(s), [](char c)
			{
				return toUpper(c);
			});
		return s;
	}

	static StringList toLowerCase(const StringList& strlist) {
		StringList s;
		std::transform(strlist.begin(), strlist.end(),std::back_inserter(s), [](const std::string& str)
			{
				return toLowerCase(str);
			});
		return s;
	}

	static StringList toUpperCase(const StringList& strlist) {
		StringList s;
		std::transform(strlist.begin(), strlist.end(),std::back_inserter(s), [](const std::string& str)
			{
				return toUpperCase(str);
			});
		return s;
	}

	static bool contains(const std::string& str, const StringList& slist)
	{
		for (auto& s : slist)
		{
			if (str.find(s) != std::string::npos)
			{
				return true;
			}
		}
		return false;
	}


};
