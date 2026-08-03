#pragma once
#include "Leadwerks.h"
#include "../BaseComponent.h"

using namespace Leadwerks;

class test : public BaseComponent//Component
{
public: 
    int integervalue = 0;//"Integer value"
    float floatvalue = 0.0f;//"Float value"
    WString stringvalue = "";//"String value"
    bool booleanvalue = false;//"Boolean value"
    int optionvalue = 0;//"Option value" ["Option 1", "Option 2", "Option 3"]
    std::shared_ptr<Entity> entityvalue;//"Entity value"
    WString pathvalue;//"Path value" SOUND
    Vec2 vec2value = Vec2(0,0);//"Vec2 value"
    Vec3 vec3value = Vec3(0,0,0);//"Vec3 value"
    Vec4 vec4value = Vec4(0,0,0,0);//"Vec4 value"
    Vec3 rgbvalue = Vec3(1,1,1);//"RGB value" COLOR
    Vec4 rgbavalue = Vec4(1,1,1,1);//"RGBA value" COLOR

    virtual void Start();
    virtual void Update();
    virtual void Collide(std::shared_ptr<Entity> collidedentity, const Vec3& position, const Vec3& normal, const float speed);
    virtual bool ProcessEvent(const Event& e);
	virtual bool Load(table& properties, std::shared_ptr<Stream> binstream, std::shared_ptr<Scene> scene, const LoadFlags flags, std::shared_ptr<Object> extra);
    virtual bool Save(table& properties, std::shared_ptr<Stream> binstream, std::shared_ptr<Scene> scene, const SaveFlags flags, std::shared_ptr<Object> extra);
    virtual std::shared_ptr<Component> Copy();
    virtual std::any CallMethod(shared_ptr<Component> sender, const WString& name, const std::vector<std::any>& arguments);
};