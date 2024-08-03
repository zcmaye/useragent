#pragma once
#include "BaseEnum.hpp"
/**
 * Enum constants representing manufacturers of operating systems and client software. 
 * Manufacturer could be used for specific handling of browser requests.
 * @author harald
 */

//struct Manufacturer 
ZCENUM_CLASS(Manufacturer)
{
	ZCENUM_INIT(Manufacturer);//
	friend class OperatingSystem;
	friend class Browser;
private:
	/**
	 * Unknow or rare manufacturer
	 */
	ZCENUM_K(Manufacturer, OTHER);//
	/**
	 * Microsoft Corporation
	 */
	ZCENUM_K(Manufacturer, MICROSOFT);// (2, "Microsoft Corporation"),
	/**
	 * Apple Inc.
	 */
	ZCENUM_K(Manufacturer, APPLE);// (3, "Apple Inc."),
	/**
	 * Sun Microsystems, Inc.
	 */
	ZCENUM_K(Manufacturer, SUN);// (4, "Sun Microsystems, Inc."),
	/**
	 * Symbian Ltd.
	 */
	ZCENUM_K(Manufacturer, SYMBIAN);// (5, "Symbian Ltd."),
	/**
	 * Nokia Corporation
	 */
	ZCENUM_K(Manufacturer, NOKIA);// (6, "Nokia Corporation"),
	/**
	 * Research In Motion Limited
	 */
	ZCENUM_K(Manufacturer, BLACKBERRY);// (7, "Research In Motion Limited"),
	/**
	 * Hewlett-Packard Company, previously Palm
	 */
	ZCENUM_K(Manufacturer, HP);// (8, "Hewlett Packard"),
	/**
	 * Sony Ericsson Mobile Communications AB
	 */
	ZCENUM_K(Manufacturer, SONY_ERICSSON);// (9, "Sony Ericsson Mobile Communications AB"),
	/**
	 * Samsung Electronics
	 */
	ZCENUM_K(Manufacturer, SAMSUNG);// (20, "Samsung Electronics"),
	/**
	 * Sony Computer Entertainment, Inc.
	 */
	ZCENUM_K(Manufacturer, SONY);// (10, "Sony Computer Entertainment, Inc."),
	/**
	 * Nintendo
	 */
	ZCENUM_K(Manufacturer, NINTENDO);// (11, "Nintendo"),
	/**
	 * Opera Software ASA
	 */
	ZCENUM_K(Manufacturer, OPERA);// (12, "Opera Software ASA"),
	/**
	 * Mozilla Foundation
	 */
	ZCENUM_K(Manufacturer, MOZILLA);// (13, "Mozilla Foundation"),
	/**
	 * Google Inc.
	 */
	ZCENUM_K(Manufacturer, GOOGLE);// (15, "Google Inc."),
	/**
	 * CompuServe Interactive Services, Inc.
	 */
	ZCENUM_K(Manufacturer, COMPUSERVE);// (16, "CompuServe Interactive Services, Inc."),
	/**
	 * Yahoo Inc.
	 */
	ZCENUM_K(Manufacturer, YAHOO);// (17, "Yahoo Inc."),
	/**
	 * AOL LLC.
	 */
	ZCENUM_K(Manufacturer, AOL);// (18, "AOL LLC."),
	/**
	 * Mail.com Media Corporation
	 */
	ZCENUM_K(Manufacturer, MMC);// (19, "Mail.com Media Corporation"),
	/**
	 * Amazon.com, Inc.
	 */
	ZCENUM_K(Manufacturer, AMAZON);// (24, "Amazon.com, Inc."),
	/**
	 * Roku sells home digital media products
	 */
	ZCENUM_K(Manufacturer, ROKU);// (21, "Roku, Inc."),
	/**
	 * Adobe Systems Inc.
	 */
	ZCENUM_K(Manufacturer, ADOBE);//(23, "Adobe Systems Inc."),
	/**
	 * Canonical Ltd.
	 */
	ZCENUM_K(Manufacturer, CONONICAL);//(25,"Canonical Ltd."),
	/**
	 * Linux Foundation, owner of the Tizen Project
	 */
	ZCENUM_K(Manufacturer, LINUX_FOUNDATION);//(26,"Linux Foundation");

private:
	short m_id;
	std::string m_name;
public:
	Manufacturer(int index,const char* key,int id, const std::string& name)
		:ZcEnumBase(index,key)
		,m_id(id), m_name(name)
	{
	}
public:
	/**
	 * @return the id
	 */
	short getId()const {
		return m_id;
	}

	/**
	 * @return the name
	 */
	const std::string& getName()const {
		return m_name;
	}
};
