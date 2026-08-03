#pragma once
#include "Leadwerks.h"
#include "test.h"

using namespace Leadwerks;

void test::Start()
{
    //Listen(EVENT_KEYDOWN, NULL);// makes this component listen for keydown events from all windows
}

void test::Update()
{
    
}

void test::Collide(shared_ptr<Entity> collidedentity, const Vec3& position, const Vec3& normal, const float speed)
{
    
}

bool test::ProcessEvent(const Event& e)
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

bool test::Load(table& properties, shared_ptr<Stream> binstream, shared_ptr<Scene> scene, const LoadFlags flags, std::shared_ptr<Object> extra)
{
    if (properties["integervalue"].is_number()) integervalue = properties["integervalue"];
    if (properties["floatvalue"].is_number()) floatvalue = properties["floatvalue"];
    if (properties["booleanvalue"].is_boolean()) booleanvalue = properties["booleanvalue"];
    if (properties["entityvalue"].is_string())
    {
        entityvalue = scene->GetEntity(std::string(properties["entityvalue"]));
    }
    return BaseComponent::Load(properties, binstream, scene, flags, extra);
}

bool test::Save(table& properties, shared_ptr<Stream> binstream, shared_ptr<Scene> scene, const SaveFlags flags, std::shared_ptr<Object> extra)
{
    properties["integervalue"] = integervalue;
    properties["floatvalue"] = floatvalue;
    properties["booleanvalue"] = booleanvalue;
    if (entityvalue) properties["entityvalue"] = std::string(entityvalue->GetUuid());
    return BaseComponent::Save(properties, binstream, scene, flags, extra);
}

//This method will work with simple components
shared_ptr<Component> test::Copy()
{
    return std::make_shared<test>(*this);
}

std::any test::CallMethod(shared_ptr<Component> sender, const WString& name, const std::vector<std::any>& arguments)
{
    /*if (name == "MyMethod")
    {
        MyMethod();
        return false;
    }*/
    return BaseComponent::CallMethod(sender, name, arguments);
}