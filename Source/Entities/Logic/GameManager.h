#pragma once
#include "Leadwerks.h"
#include "../BaseComponent.h"

using namespace Leadwerks;

class GameManager : public BaseComponent//Component
{
public: 
    virtual void Start();
    virtual void Update();
   
    void GameOver();//in
	virtual void AddScore(int points = 10);//inout

	virtual bool Load(table& properties, std::shared_ptr<Stream> binstream, std::shared_ptr<Scene> scene, const LoadFlags flags, std::shared_ptr<Object> extra);
    virtual bool Save(table& properties, std::shared_ptr<Stream> binstream, std::shared_ptr<Scene> scene, const SaveFlags flags, std::shared_ptr<Object> extra);
    virtual std::shared_ptr<Component> Copy();
    virtual std::any CallMethod(shared_ptr<Component> sender, const WString& name, const std::vector<std::any>& arguments);

	virtual std::vector<int> GetScore();

protected:
    int i_bestScore;
    int i_totalPoint;
    int i_currentTotalPoint;
    int i_score;

};