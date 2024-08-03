#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iosfwd>

#define ZCENUM_K(className,name)\
	static className name

#define ZCENUM_V(className,name,...)\
	className className::name{className::lastIndex(),#name,##__VA_ARGS__}

#define ZCENUM_V2(className,name,...)\
	className name{className::lastIndex(),#name,##__VA_ARGS__}

#define ZCENUM_CLASS(className)\
	class className: public ZcEnumBase<className>

#define ZCENUM_INIT(className)\
	public:\
	static const char* name(){return #className; }
	//className(int index,const char* key):ZcEnumBase(index,key){}\
	//className():className(className::lastIndex(),"null"){}


template<typename T>
class ZcEnumBase
{
public:
	using ptr = T*;
private:	
	inline static std::vector<T*> _values;
	int _index;
	const char* _key;
public:
	ZcEnumBase(const int& index_, const char*& key_)
		:_index(index_)
		,_key(key_)
	{ 
		_values.push_back(static_cast<T*>(this));
	}
	size_t hashCode()const { return doHash(); };
	/**
	 * 获取枚举键字符串.
	 */
	const char* getKey()const { return _key; }

	virtual std::string toString()const { return _key; }

	/**
	 * 获取枚举索引.
	 */
	int getIndex()const { return _index; }

	/**
	 * 获取枚举数量.
	 */
	static size_t count(){ return _values.size(); }

	/**
	 * 获取所有枚举.
	 */
	static const std::vector<T*>& values(){ return _values; };

	/**
	 * 根据索引获取枚举.
	 */
	static T* value(int index)
	{
		auto it = std::find_if(_values.begin(), _values.end(), [=](T* p)
			{
				return p->getIndex() == index;
			});
		if (it != _values.end())
			return *it;
		return nullptr; 
	};

	/**
	 * 自动计算枚举索引.
	 */
	static int lastIndex() {
		static int idx= 0;
		return idx++;
	}
protected:
	/**
	 * 计算hash值.
	 */
	virtual size_t doHash()const { return std::hash<std::string>()(getKey()); }

	//template<typename U>
	//inline friend std::ostream& operator<<(std::ostream& os, const U& e)
	//{
	//	os << U::name() << "(" << e.getKey() << " " <<std::hex<< e.hashCode() << ")";
	//	return os;
	//}
};
