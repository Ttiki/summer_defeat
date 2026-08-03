#pragma once
#include "Leadwerks.h"
#include "../BaseComponent.h"

using namespace Leadwerks;

class FlamingoSpawner : public BaseComponent//Component
{
public: 
	WString ws_spawnModel = "Flamingo";//"Spawn model" MODEL
	float f_spawnInterval;//"Spawn interval" 
	
	virtual void Start();
    virtual void Update();
    virtual std::shared_ptr<Component> Copy();
    virtual std::any CallMethod(shared_ptr<Component> sender, const WString& name, const std::vector<std::any>& arguments);

	virtual sol::function SpawnFlamingo();

	std::vector<shared_ptr<Model>> spawnedFlamingos;
protected:
	shared_ptr<World> world;
	shared_ptr<Timer> timer;
};