// Orbit.hpp

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Orbit.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <nlohmann/json.hpp>

#include "Profile.hpp"

namespace UbiorbitapiR2Loader
{
	using nlohmann::json;

	struct Orbit
	{
		Profile profile;
		std::string saves;
	};
}