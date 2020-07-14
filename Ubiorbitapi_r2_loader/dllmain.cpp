// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#include "Consts.hpp"

#include "OrbitConfigSingleton.hpp"
#include "OrbitMetaDataStorageSingleton.hpp"

#ifdef _DEBUG
	#include <plog/Init.h>
#endif

using namespace UbiorbitapiR2Loader;

BOOL APIENTRY DllMain(HMODULE hModule,
                      // ReSharper disable CppParameterMayBeConst
                      DWORD ulReasonForCall,
                      // ReSharper restore CppParameterMayBeConst
                      LPVOID lpReserved
)
{
	switch (ulReasonForCall)
	{
	case DLL_PROCESS_ATTACH:
		{
#ifdef _DEBUG
			plog::init(plog::debug, Consts::LogName);
#endif

			const auto currentPath = filesystem::current_path();
			const auto configPath = currentPath / path(Consts::ConfigName);

			if (!exists(configPath))
			{
				throw exception("Configuration file not found!");
			}

			OrbitConfigSingleton::GetInstance().configHolder.Open(configPath);

			const auto metaDataStoragePath = path(OrbitConfigSingleton::GetInstance().configHolder.config.orbit.saves) /
				path(Consts::SavesMetaDataStorageName);

			OrbitMetaDataStorageSingleton::GetInstance().orbitMetaDataStorageHolder.Open(metaDataStoragePath);
			break;
		}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	default: ;
	}
	return TRUE;
}
