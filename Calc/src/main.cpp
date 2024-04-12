
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include <stdio.h>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#include <GLFW/glfw3.h>
#include<iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include<string.h>


#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Main code
int main(int, char**)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;
    
    auto Main_Window = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | 
                        ImGuiWindowFlags_NoBringToFrontOnFocus |
                         ImGuiWindowFlags_NoCollapse|
                        ImGuiWindowFlags_NoResize;

    // Create window glfw(renderer)
    
    GLFWwindow* window = glfwCreateWindow( 1280, 720, "Calculator", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // vsync

    // ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     //  Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      //  Gamepad Controls

    //  ImGui style
    ImGui::StyleColorsDark();


    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();


    ImFont* headfont = io.Fonts->AddFontFromFileTTF("Ubuntu-L.ttf", 72.0f);
    ImFont* fontnav = io.Fonts->AddFontFromFileTTF("Ubuntu-L.ttf", 24.0f);
    ImVec4 lime = ImVec4(0.06f, 1.0f, 0.09f, 10.0f);
    ImVec4 dgreen = ImVec4(0.3f, 1.0f, 0.4f, 0.8f);
    ImVec4 Sgrey = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
    ImVec4 Sblack = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    ImGuiStyle& style1 = ImGui::GetStyle();
    style1.Colors[ImGuiCol_WindowBg]= ImVec4(1.0f, 1.0f, 1.0, 1.0f);
    style1.Colors[ImGuiCol_Text] = dgreen;
    style1.Colors[ImGuiCol_TextSelectedBg] = lime;
    style1.Colors[ImGuiCol_BorderShadow] = lime;
    style1.Colors[ImGuiCol_Button] = Sgrey;
    style1.Colors[ImGuiCol_Border] = Sblack; 
    style1.Colors[ImGuiCol_ButtonHovered] = lime;
    style1.CellPadding = ImVec2(1.0f,1.0f);
    style1.FrameBorderSize = 1;



    // Our state
    ImVec4 clear_color = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
    // Main loop

    //var
    float num = 0, l =1;
    while (!glfwWindowShouldClose(window))
    {

        glfwPollEvents();
        //  ImGui frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();   
        int w,h;
        glfwGetWindowSize(window, &w, &h);
        ImVec2 size(w,h);
        ImGui::SetNextWindowPos(ImVec2(0,0));
        ImGui::SetNextWindowSize(size);
        ImGui::Begin("Calc", nullptr, Main_Window);
        
        //input box
        ImGui::SetCursorPos(ImVec2(0, 0));
        ImGui::SetNextItemWidth(w);
        ImGui::InputFloat("#maindisplay", &num);
        
        //buttons
        ImGui::SetCursorPos(ImVec2(0, (h/10)+80));
        ImGui::Button("7", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
            num= num*l + 7;
            l=10;
        }
        
        ImGui::SetCursorPos(ImVec2(w/4, (h/10)+80));
        ImGui::Button("8", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
            num = num*l + 8;
            l=10;
        }


        ImGui::SetCursorPos(ImVec2(w/2, (h/10)+80));
        ImGui::Button("9", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
        
            num = num*l + 9;
            l=10;
        }

        ImGui::SetCursorPos(ImVec2(0, (h/10)+208));
        ImGui::Button("4", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
        
            num = num*l + 4;
            l=10;
        }

        ImGui::SetCursorPos(ImVec2(w/4, (h/10)+208));
        ImGui::Button("5", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
        
            num = num*l + 5;
            l=10;
        }

        ImGui::SetCursorPos(ImVec2(w/2, (h/10)+208));
        ImGui::Button("6", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
        
            num = num*l + 6;
            l=10;
        }

        ImGui::SetCursorPos(ImVec2(0, (h/10)+336));
        ImGui::Button("1", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
        
            num = num*l + 1;
            l=10;
        }

        ImGui::SetCursorPos(ImVec2(w/4, (h/10)+336));
        ImGui::Button("2", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
        
            num = num*l + 2;
            l=10;
        }

        ImGui::SetCursorPos(ImVec2(w/2, (h/10)+336));
        ImGui::Button("3", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
        
            num = num*l + 3;
            l=10;
        }

        ImGui::SetCursorPos(ImVec2(w/4, (h/10)+464));
        ImGui::Button("0", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
          num = num*10;
        }

        ImGui::SetCursorPos(ImVec2(0, (h/10)+464));
        ImGui::Button("CE", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
          num = 0;
        }

        ImGui::SetCursorPos(ImVec2(w/2, (h/10)+464));
        ImGui::Button(".", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
          l = 1/10;
        }

        ImGui::SetCursorPos(ImVec2(3*w/4, (h/10)+80));
        ImGui::Button("*", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
          
        }

        ImGui::SetCursorPos(ImVec2(3*w/4, (h/10)+208));
        ImGui::Button("/", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
          num = num/10;
        }

        ImGui::SetCursorPos(ImVec2(3*w/4, (h/10)+336));
        ImGui::Button("+", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
          num = num/10;
        }

        ImGui::SetCursorPos(ImVec2(3*w/4, (h/10)+464));
        ImGui::Button("-", ImVec2(w/4, 128));
        if (ImGui::IsItemClicked())
        {
          num = num/10;
        }


        ImGui::End();
        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        //glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
        //glUseProgram(0);
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        //glUseProgram(last_program);

        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
