#define GL_SILENCE_DEPRECATION
#include "mainwindow.h"
#include <imgui/styles/imgui_itamago.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif
bool CMainWindow::bSubscriptionCheck()
{
    time_t currentTime = time(0);
    CDatabase db;
    time_t reg = db.makeQuery<time_t>("SELECT UNIX_TIMESTAMP(subscripted) FROM users WHERE name = 'asd'", 0); // login
    spdlog::info("reg info: {}", reg);

    time_t expreg = db.makeQuery<time_t>("SELECT UNIX_TIMESTAMP(subtime) FROM users WHERE name = 'asd'", 0); // login
    bool bExpired = (currentTime > reg+expreg ? true : false);
    spdlog::info("ok");
    return bExpired;
}



void CMainWindow::applyCustomStyleSheet()
{

    
    // Setup Dear ImGui style
    ImGui::StyleColorsItamago(true, 0.95f);
    //ImGui::StyleColorsLight();
    //this->setWindowIcon(QIcon(":/data/img/mainIcon.png"));
    

    
    
}
CMainWindow::CMainWindow()
{
    if (!glfwInit())
        spdlog::info("Failed to initialize GLFW");


    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    main = glfwCreateWindow(800, 600, "Custom bar", nullptr, nullptr);

    if (main == nullptr)
        spdlog::info("windows nullptr");

    glfwMakeContextCurrent(main);
    glfwSwapInterval(1); // Enable vsync

    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); 
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;   
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;     
    


    applyCustomStyleSheet();

    
    ImGui_ImplGlfw_InitForOpenGL(main, true);

    ImGui_ImplOpenGL3_Init(glsl_version);
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    

    while (!glfwWindowShouldClose(main))
    {
        glfwPollEvents();

        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");                

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        ImGui::End();
        

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(main, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        glfwSwapBuffers(main);
    }


    pJoinWindow = new CJoinWindow();
    
    applyCustomStyleSheet();
    
    if(!EnsureRegistryKey(regKeyPath))
    {
        this->hide();

        pJoinWindow->show();
    }
    else if(bSubscriptionCheck())
    {
        // podpiska istekla
        this->hide();
        
        pJoinWindow->show();
    }
    else
    {
        this->show();
    }
}

void CMainWindow::show()
{
    

}

CMainWindow::~CMainWindow()
{
     // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(main);
    glfwTerminate();

    delete this;
}
