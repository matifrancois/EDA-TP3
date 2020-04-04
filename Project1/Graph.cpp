#include "Graph.h"
int Graph::grafica(void)
{
    // Setup Allegro
    if (inicializa())
    {
        printf("Error de inicializacion \n");
        return -1;
    }


    // Intenta crear display de 640 x480 , de fallar devuelve NULL
    display_principal = al_create_display(TAMANIO_PANTALLA_X, TAMANIO_PANTALLA_Y);
    if (!display_principal)
    {
        fprintf(stderr, " failed to create display !\n");
        return -1;
    }
    al_set_window_title(display_principal, "Dear ImGui"); 
    al_set_new_display_flags(ALLEGRO_RESIZABLE);

    
    //cola de eventos
    queue = al_create_event_queue();
    // Controla que la cola de eventos se haya generado
    if (!queue)
    {
        fprintf(stderr, " failed to create event_queue !\n");
        al_destroy_display(display_principal);
        return -1;
    }

    //le indico al queue que eventos importan
    al_register_event_source(queue, al_get_display_event_source(display_principal));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer bindings


    ImGui_ImplAllegro5_Init(display_principal);



    // Main loop
    while (running)
    {
        while (al_get_next_event(queue, &ev))
        {
            ImGui_ImplAllegro5_ProcessEvent(&ev);
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                running = false;
            if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
            {
                ImGui_ImplAllegro5_InvalidateDeviceObjects();
                al_acknowledge_resize(display_principal);
                ImGui_ImplAllegro5_CreateDeviceObjects();
            }
        }
        // Start the Dear ImGui frame
        ImGui_ImplAllegro5_NewFrame();
        ImGui::NewFrame();
        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);


        //Esta funcion se encarga de generar la parte de los botones de la gui
        VentanaPrincipal();

        // Rendering
        ImGui::Render();
        al_clear_to_color(al_map_rgba_f(clear_color.x, clear_color.y, clear_color.z, clear_color.w));
        ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
        al_flip_display();
    }

    // Clean se encarga de limpiar osea de borrar todos los objetos creados por allegro.
    clean();
    return 0;
}


int Graph::inicializa(void)
{
    // Primera funcion a llamar antes de empezar a usar allegro .
    if (!al_init())
    {
        fprintf(stderr, " failed to initialize allegro !\n");
        return -1;
    }
    // Empieza todo lo del mouse lo inicializa
    if (!al_install_mouse())
    {
        fprintf(stderr, " failed to initialize the mouse !\n");
        return -1;
    }
    if (!al_install_keyboard())
    {
        fprintf(stderr, " failed to initialize the keyboard !\n");
        return -1;
    }
    if (!al_init_primitives_addon())
    {
        fprintf(stderr, " failed to initialize the primitives !\n");
        return -1;
    }
    return 0;
}


void Graph::VentanaPrincipal(void)
{
    ImGui::Begin("Parametros");                          // Create a window called "Hello, world!" and append into it
    ImGui::Text("Inserte Vel Porcentual ");               
    ImGui::SliderFloat("%", &velp, 0.0f, 100.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
    ImGui::Text("SmellRadius");
    ImGui::InputFloat("", &smellRadius, 0.01f, 1.0f, "%.3f");
    Pregunta("SmellRadius refiere a el radio en el cual el blob buscara su alimento, fuera de ese radio de deteccion no lo huele");
    ImGui::Text("RandomJiggleLimit");
    ImGui::SliderFloat("°", &dir, 0.0f, 360.0f);
    ImGui::Text("Death %");
    ImGui::SliderFloat3("", Death, 0.0f, 1.0f);
    Pregunta("Cada valor corresponde a la probabilidad de muerte de cada grupo etario en el orden: BabyBlob, GrownBlob, GoodOldBlob");
    ImGui::Text("Cantidad de Comida %");
    if (ImGui::Button("Disminuir"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        if(foodCount>0)
            foodCount--;
    ImGui::SameLine();
    if (ImGui::Button("Aumentar"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        foodCount++;
    ImGui::SameLine();
    ImGui::Text("Cantidad = %d", foodCount);
    Pregunta("Cantidad de comida que sera visible en pantalla y podran atrapar los Blobs");

    ImGui::End();

    //ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
    //ImGui::Checkbox("Another Window", &show_another_window);
    //
    //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

}

void Graph::clean(void)
{
    ImGui_ImplAllegro5_Shutdown();
    ImGui::DestroyContext();
    al_destroy_event_queue(queue);
    al_destroy_display(display_principal);
}

void Graph::Pregunta(char* texto_ingresado)
{
    ImGui::SameLine();
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(texto_ingresado);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}
