#pragma once
#include "Leadwerks.h"
#include "MoveBalloon.h"

using namespace Leadwerks;

void MoveBalloon::Start()
{
    //Listen(EVENT_KEYDOWN, NULL);// makes this component listen for keydown events from all windows
    balloon = GetEntity();
    active = ActiveWindow();
}

void MoveBalloon::Update()
{
    if (active->KeyDown(KEY_D)) f_movement += f_moveSpeed;
    if (active->KeyDown(KEY_A)) f_movement -= f_moveSpeed;
    balloon->SetPosition(Clamp(f_movement, -3.5f, 3.5f),0,0);
}

void MoveBalloon::Collide(shared_ptr<Entity> collidedentity, const Vec3& position, const Vec3& normal, const float speed)
{
	if (collidedentity->GetCollisionType() == COLLISION_PLAYER) {
		//Print("Collided with obstacle!");
        collidedentity.reset();
        collidedentity = nullptr;
		FireOutputs("Collide");
        
	}
}

bool MoveBalloon::ProcessEvent(const Event& e)
{
    /*switch (e.id)
    {
    case EVENT_KEYDOWN:
        if (e.data == KEY_SPACE)
        {
            Print("Space key pressed");
        }
        break;
    }*/
    return true;
}

bool MoveBalloon::Load(table& properties, shared_ptr<Stream> binstream, shared_ptr<Scene> scene, const LoadFlags flags, std::shared_ptr<Object> extra)
{
    if (properties["f_moveSpeed"].is_float()) f_moveSpeed = properties["f_moveSpeed"];
    return BaseComponent::Load(properties, binstream, scene, flags, extra);
}

bool MoveBalloon::Save(table& properties, shared_ptr<Stream> binstream, shared_ptr<Scene> scene, const SaveFlags flags, std::shared_ptr<Object> extra)
{
    properties["f_moveSpeed"] = f_moveSpeed;
    return BaseComponent::Save(properties, binstream, scene, flags, extra);
}

//This method will work with simple components
shared_ptr<Component> MoveBalloon::Copy()
{
    return std::make_shared<MoveBalloon>(*this);
}

std::any MoveBalloon::CallMethod(shared_ptr<Component> sender, const WString& name, const std::vector<std::any>& arguments)
{
    /*if (name == "MyMethod")
    {
        MyMethod();
        return false;
    }*/
    return BaseComponent::CallMethod(sender, name, arguments);
}