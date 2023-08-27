#include <iostream>
#include "Walnut/Application.h"
#include "Walnut/Image.h"
#include "Helpers.h"

class ExampleLayer : public Walnut::Layer
{
public:
    virtual void OnUIRender() override
    {
        // ImGui::Begin("Hello");
        // ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
        // if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
        // {
        //     if (ImGui::BeginTabItem("Avocado"))
        //     {
        //         ImGui::Text("This is the Avocado tab!\nblah blah blah blah blah");
        //         ImGui::EndTabItem();
        //     }
        //     if (ImGui::BeginTabItem("Broccoli"))
        //     {
        //         ImGui::Text("This is the Broccoli tab!\nblah blah blah blah blah");
        //         ImGui::EndTabItem();
        //     }
        //     if (ImGui::BeginTabItem("Cucumber"))
        //     {
        //         ImGui::Text("This is the Cucumber tab!\nblah blah blah blah blah");
        //         ImGui::EndTabItem();
        //     }
        //     ImGui::EndTabBar();
        // }
        // if (ImGui::Button("click"))
        // {
        //     std::cout << "This was clicked" << std::endl;
        // }

        // ImGui::End();
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