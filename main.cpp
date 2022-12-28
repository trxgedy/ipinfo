#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

auto main( ) -> int __stdcall
{
	std::string keys[ ] { "country", "city", "regionName", "lat", "lon", "org" };
	std::string ip_api { "http://ip-api.com/json/" };
	std::string target_ip;

	std::cout << "IP: ";
	std::cin >> target_ip; std::cout << "\n";

	auto r = cpr::Get( cpr::Url { ip_api + target_ip } );

	auto j = nlohmann::json::parse( r.text );
	
	for(auto k : keys )
		std::cout << k << ": " << j[k] << std::endl;

	system( "pause > nul" );
	return EXIT_SUCCESS;
}
