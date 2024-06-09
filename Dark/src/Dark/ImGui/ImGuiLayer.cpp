#include "dkpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

#include "Dark/Application.h"

// Temp
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Dark {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{

	}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		io.BackendFlags |= ImGuiBackendFlags_HasGamepad;

		// Temp use
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
	    io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
	    io.KeyMap[ImGuiKey_B] = GLFW_KEY_B;
	    io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
	    io.KeyMap[ImGuiKey_D] = GLFW_KEY_D;
	    io.KeyMap[ImGuiKey_E] = GLFW_KEY_E;
	    io.KeyMap[ImGuiKey_F] = GLFW_KEY_F;
	    io.KeyMap[ImGuiKey_G] = GLFW_KEY_G;
	    io.KeyMap[ImGuiKey_H] = GLFW_KEY_H;
	    io.KeyMap[ImGuiKey_I] = GLFW_KEY_I;
	    io.KeyMap[ImGuiKey_J] = GLFW_KEY_J;
	    io.KeyMap[ImGuiKey_K] = GLFW_KEY_K;
	    io.KeyMap[ImGuiKey_L] = GLFW_KEY_L;
	    io.KeyMap[ImGuiKey_M] = GLFW_KEY_M;
	    io.KeyMap[ImGuiKey_N] = GLFW_KEY_N;
	    io.KeyMap[ImGuiKey_O] = GLFW_KEY_O;

		ImGui_ImplOpenGL3_Init("#version 410");

	}
	void ImGuiLayer::OnDetach()
	{
        
	}
	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(DK_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(DK_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(DK_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<MouseMovedEvent>(DK_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<KeyPressedEvent>(DK_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(DK_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(DK_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizedEvent>(DK_BIND_EVENT_FN(ImGuiLayer::OnWindowResizedEvent));
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();

		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}

	bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

		return false;
	}

	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		return false;
	}

	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		io.AddInputCharacter((unsigned short)keycode);

		return false;
	}

	bool ImGuiLayer::OnWindowResizedEvent(WindowResizedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}

}
