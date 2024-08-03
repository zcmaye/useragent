#pragma once
#include "BaseEnum.hpp"
/**
 * Enum constants classifying the different types of rendering engines which are being used by browsers.
 * @author harald
 *
 */
ZCENUM_CLASS(RenderingEngine)
{
	ZCENUM_INIT(RenderingEngine);
	/**
	 * EdgeHTML is a proprietary layout engine developed for the Microsoft Edge web browser, developed by Microsoft.
	 */
	ZCENUM_K(RenderingEngine, EDGE_HTML);
	/**
	 * Trident is the the Microsoft layout engine, mainly used by Internet Explorer.
	 */
	ZCENUM_K(RenderingEngine, TRIDENT);// ("Trident"),
	/**
	 * HTML parsing and rendering engine of Microsoft Office Word, used by some other products of the Office suite instead of Trident.
	 */
	ZCENUM_K(RenderingEngine, WORD);// ("Microsoft Office Word"),
	/**
	 * Open source and cross platform layout engine, used by Firefox and many other browsers.
	 */
	ZCENUM_K(RenderingEngine, GECKO);// ("Gecko"),
	/**
	 * Layout engine based on KHTML, used by Safari, Chrome and some other browsers.
	 */
	ZCENUM_K(RenderingEngine, WEBKIT);// ("WebKit"),
	/**
	 * Proprietary layout engine by Opera Software ASA
	 */
	ZCENUM_K(RenderingEngine, PRESTO);// ("Presto"),
	/**
	 * Original layout engine of the Mozilla browser and related products. Predecessor of Gecko.
	 */
	ZCENUM_K(RenderingEngine, MOZILLA);// ("Mozilla"),
	/**
	 * Layout engine of the KDE project
	 */
	ZCENUM_K(RenderingEngine, KHTML);// ("KHTML"),
	/**
	 * Other or unknown layout engine.
	 */
	ZCENUM_K(RenderingEngine, BLINK);// ("Blink"),
	/**
	 * Layout engine developed as part ofthe Chromium project. Fored from WebKit.
	 */
	ZCENUM_K(RenderingEngine, OTHER);// ("Other");

	std::string m_name;

	RenderingEngine(int _index,const char* _name,const std::string& name)
		:ZcEnumBase(_index, _name)
		,m_name(name)
	{
	}

	const std::string& getName() {
		return m_name;
	}
};

