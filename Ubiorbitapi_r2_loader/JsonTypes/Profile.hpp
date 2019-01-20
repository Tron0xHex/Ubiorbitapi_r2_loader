// Profile.hpp

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Profile.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <nlohmann/json.hpp>

namespace UbiorbitapiR2Loader
{
	using nlohmann::json;

	struct Profile
	{
		std::string accountId;
		std::string userName;
		std::string password;
	};
}