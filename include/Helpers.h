#include <Walnut/Application.h>

namespace Helpers
{
    void showCreateForm(bool* poe);
    static void ShowExampleAppPropertyEditor(bool* p_open);
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
                    ShowExampleAppPropertyEditor(&p_open);
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
        }
        ImGui::End();
    }
static void ShowPlaceholderObject(const char* prefix, int uid)
{
    // Use object uid as identifier. Most commonly you could also use the object pointer as a base ID.
    ImGui::PushID(uid);

    // Text and Tree nodes are less high than framed widgets, using AlignTextToFramePadding() we add vertical spacing to make the tree lines equal high.
    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);
    ImGui::AlignTextToFramePadding();
    
    bool node_open = ImGui::TreeNode("Object", "%s_%u", prefix, uid);
    // bool node_open = ImGui::Button("Object");
    ImGui::TableSetColumnIndex(1);

    if (node_open)
    {
        char heading [128];
        char text [2048];
        ImGui::TableSetColumnIndex(1);
        ImGui::SameLine();
        ImGui::Text("Task Name: ");
        ImGui::InputText("heading", heading,IM_ARRAYSIZE(heading));
        ImGui::NewLine();
        ImGui::InputTextMultiline("user-input", text,IM_ARRAYSIZE(text),ImVec2(-FLT_MIN, 0.0f));
        ImGui::NewLine();
        ImGui::Button("save", ImVec2(-FLT_MIN, 0.0f));
                // if (i >= 5)
                //     ImGui::InputFloat("##value", &placeholder_members[i], 1.0f);
                // else
                //     ImGui::DragFloat("##value", &placeholder_members[i], 0.01f);
                ImGui::NextColumn();
        // for (int i = 0; i < 8; i++)
        // {
        //     ImGui::PushID(i); // Use field index as identifier.
        //     if (i < 2)
        //     {
        //         ShowPlaceholderObject("Child", 424242);
        //     }
        //     else
        //     {
        //         // Here we use a TreeNode to highlight on hover (we could use e.g. Selectable as well)
        //         ImGui::TableNextRow();
        //         ImGui::TableSetColumnIndex(0);
        //         ImGui::AlignTextToFramePadding();
        //         ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_Bullet;
        //         ImGui::TreeNodeEx("Field", flags, "Field_%d", i);

        //         ImGui::TableSetColumnIndex(1);
        //         ImGui::SetNextItemWidth(-FLT_MIN);
        //         // if (i >= 5)
        //         //     ImGui::InputFloat("##value", &placeholder_members[i], 1.0f);
        //         // else
        //         //     ImGui::DragFloat("##value", &placeholder_members[i], 0.01f);
        //         ImGui::NextColumn();
        //     }
        //     ImGui::PopID();
        // }
        ImGui::TreePop();
    }
    ImGui::PopID();
}
    // Demonstrate create a simple property editor.
static void ShowExampleAppPropertyEditor(bool* p_open)
{
    ImGui::SetNextWindowSize(ImVec2(430, 450), ImGuiCond_FirstUseEver);
    if (!ImGui::Begin("Example: Property editor", p_open))
    {
        ImGui::End();
        return;
    }
    
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
    if (ImGui::BeginTable("split", 2, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_Resizable))
    {
        // Iterate placeholder objects (all the same data)
        const char* objs[] = {"Create", "Remove", "Update", "Delete"};
        for (int obj_i = 0; obj_i < 4; obj_i++)
        {
            ShowPlaceholderObject(objs[obj_i], obj_i);
            //ImGui::Separator();
        }
        ImGui::EndTable();
    }
    ImGui::PopStyleVar();
    ImGui::End();
}
void showCreateForm(bool *p_open)
{
    if (ImGui::Begin("Create Task", p_open))
    {
        ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Close"))
                    *p_open = false;
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
    }
}
} // namespace Helpers
