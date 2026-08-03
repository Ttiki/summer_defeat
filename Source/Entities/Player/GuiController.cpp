#pragma once
#include "Leadwerks.h"
#include "GuiController.h"
#include "../Logic/GameManager.h"

using namespace Leadwerks;

void GuiController::Start()
{
    //Listen(EVENT_KEYDOWN, NULL);// makes this component listen for keydown events from all windows
    
	sp_font = LoadFont("Fonts/Arial.ttf");
    Print(sp_camera->GetUuid());
	sp_interface = CreateInterface(sp_camera, sp_font, ActiveWindow()->GetSize());
    sp_root_panel = CreatePanel(0,0,ActiveWindow()->GetSize().x/2, ActiveWindow()->GetSize().y/2, sp_interface->root, PANEL_GROUP );
    sp_label_score = CreateLabel(L"", 8, 8, 32, sp_root_panel->GetSize().y, sp_root_panel);
	sp_label_bestScore = CreateLabel(L"", sp_label_score->GetSize().x + 16, 8, 32, sp_root_panel->GetSize().y, sp_root_panel);
	sp_label_total_score = CreateLabel(L"", sp_label_bestScore->GetSize().x + 16, 8, 32, sp_root_panel->GetSize().y, sp_root_panel);
	sp_label_global_total_score = CreateLabel(L"", sp_label_total_score->GetSize().x + 16, 8, 32, sp_root_panel->GetSize().y, sp_root_panel);
}

void GuiController::Update()
{
    
}

void GuiController::UpdateGui()//in
{
    sp_label_score->SetText(sp_e_gameManager->GetComponent<GameManager>()->GetScore()[0]);
    sp_label_bestScore->SetText(sp_e_gameManager->GetComponent<GameManager>()->GetScore()[1]);
    sp_label_total_score->SetText(sp_e_gameManager->GetComponent<GameManager>()->GetScore()[2]);
    sp_label_global_total_score->SetText(sp_e_gameManager->GetComponent<GameManager>()->GetScore()[3]);
}


void GuiController::Collide(shared_ptr<Entity> collidedentity, const Vec3& position, const Vec3& normal, const float speed)
{
    
}

bool GuiController::ProcessEvent(const Event& e)
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

bool GuiController::Load(table& properties, shared_ptr<Stream> binstream, shared_ptr<Scene> scene, const LoadFlags flags, std::shared_ptr<Object> extra)
{
    if (properties["sp_e_gameManager"].is_string())
    {
        sp_e_gameManager = scene->GetEntity(std::string(properties["sp_e_gameManager"]));
    }
    return BaseComponent::Load(properties, binstream, scene, flags, extra);
}

bool GuiController::Save(table& properties, shared_ptr<Stream> binstream, shared_ptr<Scene> scene, const SaveFlags flags, std::shared_ptr<Object> extra)
{
    if (sp_e_gameManager) properties["sp_e_gameManager"] = std::string(sp_e_gameManager->GetUuid());
    return BaseComponent::Save(properties, binstream, scene, flags, extra);
}

//This method will work with simple components
shared_ptr<Component> GuiController::Copy()
{
    return std::make_shared<GuiController>(*this);
}

std::any GuiController::CallMethod(shared_ptr<Component> sender, const WString& name, const std::vector<std::any>& arguments)
{
    /*if (name == "MyMethod")
    {
        MyMethod();
        return false;
    }*/
    return BaseComponent::CallMethod(sender, name, arguments);
}