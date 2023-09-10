#include <iostream>
#include <string>
#include <Walnut/Application.h>
#include <Task.h>

namespace Helpers
{
    CreateTaskModal modal;
    void showCreateForm(bool *poe);
    static void ShowCrudWindow(bool *p_open, CreateTaskModal &modal);
    static void ShowExampleAppLog(bool *p_open);
    static void showFullWindows()
    {
        static bool use_work_area = true;
        static bool open_create = false;
        static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
        const ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(use_work_area ? viewport->WorkPos : viewport->Pos);
        ImGui::SetNextWindowSize(use_work_area ? viewport->WorkSize : viewport->Size);
        bool running = true;
        bool p_open = true;
        if (ImGui::Begin("Example: Fullscreen window", &running, flags))
        {
            if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None))
            {
                if (ImGui::BeginTabItem("Task Overview"))
                {
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("Dependencies"))
                {
                    ImGui::Text("ID: 0123456789");
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("Task Management"))
                {
                    ImGui::Text("Here you can Add, remove, modify your tasks");
                    // if (ImGui::Button("CREATE", ImVec2(200, 70)))
                    // {
                    //     Helpers::showCreateForm(&p_open);
                    // }
                    ImGui::NewLine();
                    ShowCrudWindow(&p_open, modal);
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
        }
        ImGui::End();
    }
    static void ShowCrudWindow(bool *open, CreateTaskModal &modal)
    {
        if (*open)
        {
            if (ImGui::Button("Create"))
            {
                modal.isOpen = true;
            }
            if (modal.isOpen)
            {
                ImGui::OpenPopup(("Create Task"));
            }
            if (ImGui::BeginPopupModal("Create Task"))
            {
                ImGui::InputText("Heading", modal.headingText, 1024);
                ImGui::SameLine();
                ImGui::RadioButton("Urgent", &modal.importanceSelection, 0);
                ImGui::SameLine();
                ImGui::RadioButton("Important", &modal.importanceSelection, 1);
                ImGui::SameLine();
                ImGui::RadioButton("Free time", &modal.importanceSelection, 2);
                ImGui::InputTextMultiline("Description", modal.descriptionText, 1024);

                if (ImGui::Button("OK"))
                {
                    // Close the modal when OK is pressed
                    std::cout << modal.headingText << std::endl;
                    std::cout << modal.descriptionText << std::endl;
                    ImGui::CloseCurrentPopup();
                    modal.isOpen = false;
                }

                ImGui::EndPopup();
            }
        }
    }
} // namespace Helpers
