#include <iostream>
#include "Walnut/Application.h"
#include "Walnut/Image.h"
#include "Helpers.h"

class ExampleLayer : public Walnut::Layer
{
public:
    virtual void OnUIRender() override
    {
        Helpers::showFullWindows();
    }
 
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Walnut Task Manager";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}