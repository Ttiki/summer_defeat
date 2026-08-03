#pragma once
#include "Leadwerks.h"
#include "GameManager.h"

using namespace Leadwerks;

void GameManager::Start()
{
    //Listen(EVENT_KEYDOWN, NULL);// makes this component listen for keydown events from all windows
}

void GameManager::Update()
{
    
}

void GameManager::GameOver()
{
	Print("Game Over!");
	i_currentTotalPoint += i_score;
	LoadScene(this->GetEntity()->GetWorld(), "Maps/mainmenu.map");

}

void GameManager::AddScore(int points)//inout
{
    i_score += points;
	if (i_score > i_bestScore) i_bestScore = i_score;
	Print("Current Score: " + std::to_string(i_score) + ", Best Score: " + std::to_string(i_bestScore));
	FireOutputs("AddScore");
}

bool GameManager::Load(table& properties, shared_ptr<Stream> binstream, shared_ptr<Scene> scene, const LoadFlags flags, std::shared_ptr<Object> extra)
{
    if (properties["i_score"].is_number()) i_score = properties["i_score"];
    if (properties["i_currentTotalPoint"].is_number()) i_currentTotalPoint = properties["i_currentTotalPoint"];
    if (properties["i_totalPoint"].is_number()) i_totalPoint = properties["i_totalPoint"];
	if (properties["i_bestScore"].is_number()) i_bestScore = properties["i_bestScore"];
    return BaseComponent::Load(properties, binstream, scene, flags, extra);
}

bool GameManager::Save(table& properties, shared_ptr<Stream> binstream, shared_ptr<Scene> scene, const SaveFlags flags, std::shared_ptr<Object> extra)
{
    properties["i_score"] = i_score;
    properties["i_currentTotalPoint"] = i_currentTotalPoint;
    properties["i_totalPoint"] = i_totalPoint;
    properties["i_bestScore"] = i_bestScore;
    return BaseComponent::Save(properties, binstream, scene, flags, extra);
}

//This method will work with simple components
shared_ptr<Component> GameManager::Copy()
{
    return std::make_shared<GameManager>(*this);
}

std::any GameManager::CallMethod(shared_ptr<Component> sender, const WString& name, const std::vector<std::any>& arguments)
{
    /*if (name == "MyMethod")
    {
        MyMethod();
        return false;
    }*/
    return BaseComponent::CallMethod(sender, name, arguments);
}

std::vector<int> GameManager::GetScore()
{
	return { i_score, i_bestScore, i_currentTotalPoint, i_totalPoint};
}