#pragma once
#include "Leadwerks.h"
#include "FlamingoSpawner.h"

using namespace Leadwerks;

void FlamingoSpawner::Start()
{
    //Listen(EVENT_KEYDOWN, NULL);// makes this component listen for keydown events from all windows
	world = this->GetEntity()->GetWorld();
	auto freq = Random(100000, 100000 * Random(1,5));
	timer = CreateTimer(freq);
	Print("FlamingoSpawner started with spawn interval: " + std::to_string(freq));
	SpawnFlamingo();
}

void FlamingoSpawner::Update()
{
	//ListenEvent(EVENT_TIMERTICK, timer, SpawnFlamingo());
}

sol::function FlamingoSpawner::SpawnFlamingo()
{
	float random = Random(-3.5f, 3.5f);
	auto mdl = LoadModel(world, "Models/Miscelaneous/flamingo.mdl");
	mdl->SetPosition(random, this->GetEntity()->GetPosition().y, this->GetEntity()->GetPosition().z);
	mdl->SetMass(5.0f);
	mdl->SetGravity(-2.0f);
	mdl->SetCollisionType(COLLISION_PLAYER);
	mdl->SetHidden(false);
	spawnedFlamingos.push_back(mdl);
	timer.reset();
	return sol::function();
}

//This method will work with simple components
shared_ptr<Component> FlamingoSpawner::Copy()
{
    return std::make_shared<FlamingoSpawner>(*this);
}

std::any FlamingoSpawner::CallMethod(shared_ptr<Component> sender, const WString& name, const std::vector<std::any>& arguments)
{
    /*if (name == "MyMethod")
    {
        MyMethod();
        return false;
    }*/
    return BaseComponent::CallMethod(sender, name, arguments);
}