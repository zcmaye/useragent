# useragent
C++ HTTP header User-Agent parse

## Example:

```cpp
#include "UserAgent.h"
#include <iostream>

int main(int argc, char* argv[])
{
	const char* useragents[] = {
		"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/127.0.0.0 Safari/537.36 Edg/127.0.0.0",
		"Opera/9.80 (Macintosh; Intel Mac OS X 10.6.8; U; en) Presto/2.8.131 Version/11.11",
		"Mozilla/5.0 (iPhone; U; CPU iPhone OS 4_3_3 like Mac OS X; en-us) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.2 Mobile/8J2 Safari/6533.18.5",
		"Mozilla/5.0 (Linux; U; Android 3.0; en-us; Xoom Build/HRI39) AppleWebKit/534.13 (KHTML, like Gecko) Version/4.0 Safari/534.13"

	};
	for (auto& userAgentStr : useragents)
	{
		auto ua = UserAgent::parse(userAgentStr);
		std::cout << "===================\t\t" << ua->toString() << "  " << ua->getBrowserVersion() << "\t\t======================" << std::endl;
		

		auto browser = ua->getBrowser();
		std::cout << "-----Browser-----" << std::endl;
		std::cout << " BrowserVer: " << browser->getVersion(userAgentStr) << std::endl;
		std::cout <<" BrowerType: "<< browser->getBrowserType()->getName() << std::endl;
		std::cout <<" Manufacturer: "<< browser->getManufacturer()->getName() << std::endl;
		std::cout <<" RenderingEngine: "<< browser->getRenderingEngine()->getName() << std::endl;

		auto os = ua->getOperatingSystem();
		std::cout << "\n-----Os-----" << std::endl;
		std::cout <<" DeviceType: " << os->getDeviceType()->getName() << std::endl;
		std::cout <<" OsName: " << os->getName() << std::endl;
		std::cout <<" Manufaturer: " << os->getManufacturer()->getName() << std::endl;

	}
	return 0;
}
```

## output:

```cpp
===================             Windows 10-Chrome 12  Chrome/127.0.0.0          ======================
-----Browser-----
 BrowserVer: Chrome/127.0.0.0
 BrowerType: Browser
 Manufacturer: Google Inc.
 RenderingEngine: WebKit

-----Os-----
 DeviceType: Computer
 OsName: Windows 10
 Manufaturer: Microsoft Corporation
===================             Mac OS X-Opera 11  Version/11.11                ======================
-----Browser-----
 BrowserVer: Version/11.11
 BrowerType: Browser
 Manufacturer: Opera Software ASA
 RenderingEngine: Presto

-----Os-----
 DeviceType: Computer
 OsName: Mac OS X
 Manufaturer: Apple Inc.
===================             iOS 4 (iPhone)-Mobile Safari  Version/5.0.2             ======================
-----Browser-----
 BrowserVer: Version/5.0.2
 BrowerType: Browser (mobile)
 Manufacturer: Apple Inc.
 RenderingEngine: WebKit

-----Os-----
 DeviceType: Mobile
 OsName: iOS 4 (iPhone)
 Manufaturer: Apple Inc.
===================             Android 3.x Tablet-Safari 5  Version/4.0                ======================
-----Browser-----
 BrowserVer: Version/4.0
 BrowerType: Browser
 Manufacturer: Apple Inc.
 RenderingEngine: WebKit

-----Os-----
 DeviceType: Tablet
 OsName: Android 3.x Tablet
 Manufaturer: Google Inc.
```

