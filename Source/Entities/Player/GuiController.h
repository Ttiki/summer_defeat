#pragma once
#include "Leadwerks.h"
#include "../BaseComponent.h"

using namespace Leadwerks;

class GuiController : public BaseComponent//Component
{
public: 
	shared_ptr<Entity> sp_e_gameManager;//"Game Manager"
	shared_ptr<Camera> sp_camera;//"Camera"

    virtual void Start();
    virtual void Update();
    virtual void Collide(std::shared_ptr<Entity> collidedentity, const Vec3& position, const Vec3& normal, const float speed);
    virtual bool ProcessEvent(const Event& e);
	virtual bool Load(table& properties, std::shared_ptr<Stream> binstream, std::shared_ptr<Scene> scene, const LoadFlags flags, std::shared_ptr<Object> extra);
    virtual bool Save(table& properties, std::shared_ptr<Stream> binstream, std::shared_ptr<Scene> scene, const SaveFlags flags, std::shared_ptr<Object> extra);
    virtual std::shared_ptr<Component> Copy();
    virtual std::any CallMethod(shared_ptr<Component> sender, const WString& name, const std::vector<std::any>& arguments);

    virtual void UpdateGui();//in

protected:
    shared_ptr<Interface> sp_interface;
    shared_ptr<Font> sp_font;
    shared_ptr<Widget> sp_root_panel;
	shared_ptr<Widget> sp_label_score;
    shared_ptr<Widget> sp_label_bestScore;
    shared_ptr<Widget> sp_label_total_score;
    shared_ptr<Widget> sp_label_global_total_score;
};