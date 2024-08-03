#pragma once
#include "BaseEnum.hpp"
/**
 * Enum contact for the type of used device
 * @author harald
 *
 */
//struct DeviceType 
ZCENUM_CLASS(DeviceType)
{
	ZCENUM_INIT(DeviceType);
	friend class OperatingSystem;
private:
	/**
	 * Standard desktop or laptop computer
	 */
	ZCENUM_K(DeviceType,COMPUTER);// { "Computer" };
	/**
	 * Mobile phone or similar small mobile device
	 */
	ZCENUM_K(DeviceType,MOBILE);// ("Mobile"),
	/**
	 * Small tablet type computer.
	 */
	ZCENUM_K(DeviceType,	TABLET);// ("Tablet"),
	/**
	 * Game console like the Wii or Playstation.
	 */
	ZCENUM_K(DeviceType,	GAME_CONSOLE);// ("Game console"),
	/**
	 * Digital media receiver like the Google TV.
	 */
	ZCENUM_K(DeviceType,	DMR);// ("Digital media receiver"),
	/**
	 * Miniature device like a smart watch or interactive glasses
	 */
	ZCENUM_K(DeviceType,	WEARABLE);// ("Wearable computer"),
	/**
	 * Other or unknow type of device.
	 */
	ZCENUM_K(DeviceType,	UNKNOWN);// ("Unknown");

	std::string m_name;
public:
	DeviceType(int index,const char* key,const std::string& name)
		:ZcEnumBase(index,key)
		,m_name(name)
	{
	}

	const std::string& getName()const {
		return m_name;
	}
};
