#pragma once

#include <vector>
#include <typeinfo>
#include "../../Memory/GameData.h"
#include "Modules/Module.h"
#include "Modules/Killaura.h"
#include "Modules/ESP.h"
#include "Modules/Aimbot.h"
#include "Modules/TriggerBot.h"
#include "Modules/Jetpack.h"
#include "Modules/ChestESP.h"
#include "Modules/RainbowSky.h"
#include "Modules/NoKnockBack.h"

class ModuleManager {
private:
	GameData* gameData;
	std::vector<IModule*> moduleList;
public:
	ModuleManager(GameData* gameData);
	void initModules();
	void onTick(C_GameMode* gameMode);
	void onKeyUpdate(int key, bool isDown);
	void onPreRender();
	void onPostRender();
	std::vector<IModule*>* getModuleList();
	

	/*
	 *	Use as follows: 
	 *		IModule* mod = moduleMgr.getModule<NoKnockBack>(); 
	 *	Check for nullptr directly after that call, as Hooks::init is called before ModuleManager::initModules !	
	 */
	template<typename TRet>
	IModule* getModule() { 
		for (std::vector<IModule*>::iterator it = this->moduleList.begin(); it != this->moduleList.end(); ++it) {
			IModule* mod = *it;
			if (typeid(*mod) == typeid(TRet) || typeid(mod) == typeid(TRet))
				return mod;
		}
		return nullptr;
	};
};

extern ModuleManager* moduleMgr;