#include "biopch.h"
#include "imgui.h"
#include "ImGuiLayer.h"
#include "GLFW/glfw3.h"
#include "Platform_Impl/imgui_impl_opengl3.h"

namespace Bioba {

    ImGuiLayer::ImGuiLayer(int width,int height)
        :Layer(LayerType::Overlay,"GUI") , m_Time(0) , m_Width(width) , m_Height(height)
    {

    }

    ImGuiLayer::~ImGuiLayer()
    {
        OnDetach();
    }




    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO& io = ImGui::GetIO();

        //Setup IO dimesnions
        io.DisplaySize = ImVec2((float)m_Width, (float)m_Height);

        // Setup time step
        double current_time = glfwGetTime();
        io.DeltaTime = m_Time > 0.0 ? (float)(current_time - m_Time) : (float)(1.0f / 60.0f);
        m_Time = current_time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();
        
        bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnAttach()
	{
        ImGui::CreateContext();
        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors; // Back-end Platform supports honoring GetMouseCursor() value to change the OS cursor shape.
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos; // Back-end Platform supports io.WantSetMousePos requests to reposition the OS mouse position (only used if ImGuiConfigFlags_NavEnableSetMousePos is set).
        // Keyboard mapping.ImGui will use those indices to peek into the io.KeysDown[] array.
        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        ImGui_ImplOpenGL3_Init("#version 410");
	}

    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        //ImGui::DestroyContext();
    }

}