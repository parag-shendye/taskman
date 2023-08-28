#include <Walnut/Application.h>

namespace Helpers
{
    static void showFullWindows()
    {
        static bool use_work_area = true;
        static bool open_create = false;
        static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
        const ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(use_work_area ? viewport->WorkPos : viewport->Pos);
        ImGui::SetNextWindowSize(use_work_area ? viewport->WorkSize : viewport->Size);
        bool running = true;
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
                    if (ImGui::Button("CREATE", ImVec2(200, 70)))
                    {

                        open_create=!open_create;
                        if (open_create)
                        {
                            static char text[1024 * 16];
                            ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), flags);
                        }
                    }
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
        }
        ImGui::End();
    }
} // namespace Helpers
