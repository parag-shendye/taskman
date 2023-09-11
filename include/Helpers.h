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
    bool openTaskPopup = false;
    static void showFullWindows()
    {
        static bool use_work_area = true;
        static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
        const ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(use_work_area ? viewport->WorkPos : viewport->Pos);
        ImGui::SetNextWindowSize(use_work_area ? viewport->WorkSize : viewport->Size);
        bool running = true;
        bool p_open = true;
        if (ImGui::Begin("Main", &running, flags))
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
                    ImGui::NewLine();
                    if (ImGui::BeginMenuBar())
                    {
                        if (ImGui::BeginMenu("File"))
                        {
                            if (ImGui::MenuItem("Close"))
                            {
                                p_open = false;
                            }
                            ImGui::EndMenu();
                        }
                        ImGui::EndMenuBar();
                    }
                    static int selected = 0;
                    {
                        ImGui::BeginChild("left pane", ImVec2(150, 0), true);
                        for (int i = 0; i < 100; i++)
                        {
                            // FIXME: Good candidate to use ImGuiSelectableFlags_SelectOnNav
                            char label[128];
                            sprintf(label, "Task %d", i);
                            if (ImGui::Selectable(label, selected == i))
                            {
                                selected = i;
                                openTaskPopup = true;
                            }
                        }
                        ImGui::EndChild();
                    }
                    if (openTaskPopup)
                    {
                        ImGui::OpenPopup("Task Description Popup");
                        openTaskPopup = false;
                    }
                    if (ImGui::BeginPopup("Task Description Popup"))
                    {
                        // TODO: here make the query
                        std::string description = "kdfksdfkdsmfmsdkmf_" + std::to_string(selected);
                        ImGui::Text("Task Description:");
                        ImGui::TextWrapped("%s", description.c_str());
                        if (ImGui::Button("OK"))
                        {
                            ImGui::CloseCurrentPopup();
                        }
                        ImGui::EndPopup();
                    }
                    ImGui::SameLine();
                    ShowCrudWindow(&p_open, modal);
                    // ImGui::ShowDemoWindow(&p_open);
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
