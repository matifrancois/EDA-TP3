#include "Graph.h"

int Graph::get_info(void)
{
    // Setup Allegro
    if (inicializa())
    {
        printf("Error de inicializacion \n");
        return -1;
    }

    // Intenta crear display de 640 x480 , de fallar devuelve NULL
    display_entrada = al_create_display(TAMANIO_PANTALLA_X_ENTRADA, TAMANIO_PANTALLA_Y_ENTRADA);
    if (!display_entrada)
    {
        fprintf(stderr, " failed to create display !\n");
        return -1;
    }
    al_set_window_title(display_entrada, "Inputs de datos");
    al_set_new_display_flags(ALLEGRO_RESIZABLE);

    //cola de eventos
    queue = al_create_event_queue();
    // Controla que la cola de eventos se haya generado
    if (!queue)
    {
        fprintf(stderr, " failed to create event_queue !\n");
        al_destroy_display(display_entrada);
        return -1;
    }

    //le indico al queue que eventos importan
    al_register_event_source(queue, al_get_display_event_source(display_entrada));
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


    ImGui_ImplAllegro5_Init(display_entrada);

    while (running_inicio)
    {
        while (al_get_next_event(queue, &ev))
        {
            ImGui_ImplAllegro5_ProcessEvent(&ev);
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            { 
                running_inicio = false;
                cerrar = true;
            }
            if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
            {
                ImGui_ImplAllegro5_InvalidateDeviceObjects();
                al_acknowledge_resize(display_entrada);
                ImGui_ImplAllegro5_CreateDeviceObjects();
            }
        }
        // Start the Dear ImGui frame
        ImGui_ImplAllegro5_NewFrame();
        ImGui::NewFrame();
        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);



        //Esta funcion se encarga de generar la parte de los botones de la gui
        if(Ventanainicio()==0)
            running_inicio = false;



        // Rendering
        ImGui::Render();

        ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
        al_flip_display();
    }
    clean(display_entrada);
    return 0;
}



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
    al_set_window_title(display_principal, "Simulacion Blobeana"); 
    al_set_new_display_flags(ALLEGRO_RESIZABLE);

    //creo los bitmap
    background = al_load_bitmap("background.jpg");
    if (!background) {
        fprintf(stderr, " failed to create display !\n");
        return -1;
    }
    babyBlob = al_load_bitmap("babyblob.png");
    if (!babyBlob) {
        fprintf(stderr, " failed to create display !\n");
        return -1;
    }
    goodOldBlob = al_load_bitmap("goodoldblob.png");
    if (!goodOldBlob) {
        fprintf(stderr, " failed to create display !\n");
        return -1;
    }
    grownBlob = al_load_bitmap("grownblob.png");
    if (!grownBlob) {
        fprintf(stderr, " failed to create display !\n");
        return -1;
    }
    food = al_load_bitmap("food.png");
    if (!food) {
        fprintf(stderr, " failed to create display !\n");
        return -1;
    }


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
        al_clear_to_color(al_map_rgba_f(clear_color.x, clear_color.y, clear_color.z, clear_color.w));   //no hago al_clear asi puedo dibujar 
        
        Graph::printBlobs();     //funcion que dibuja blobs,back y comida

        ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
        al_flip_display();
    }

    // Clean se encarga de limpiar osea de borrar todos los objetos creados por allegro.
    clean(display_principal);
    return 0;
}

void Graph::printBlobs(void) {

    if (background)
    {
        al_draw_scaled_bitmap(background, 0.0f, 0.0f, al_get_bitmap_width(background), al_get_bitmap_height(background), BACKG_X, BACKG_Y, TAMANIO_PANTALLA_X, TAMANIO_PANTALLA_Y - BACKG_Y, 0);
    }




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
    if (!al_init_image_addon()) {
       
        fprintf(stderr, " failed to initialize the imageaddon !\n");
        return -1;
    }
    return 0;
}


void Graph::VentanaPrincipal(void)
{
    ImGuiWindowFlags window_flag = 0;
    window_flag |= ImGuiWindowFlags_NoResize;
    window_flag |= ImGuiWindowFlags_NoCollapse;
    ImGui::Begin("Parametros",NULL, window_flag);                          // Create a window called "Hello, world!" and append into it
    ImGui::Text("Inserte Vel Porcentual ");               
    ImGui::SliderFloat("%", &velp, 0.0f, 100.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
    Pregunta("Que porcentaje de la velocidad maxima utilizara en ese momento");
    ImGui::Text("SmellRadius");
    ImGui::InputFloat("", &smellRadius, 0.01f, 1.0f, "%.3f");
    Pregunta("SmellRadius refiere a el radio en el cual el blob buscara su alimento, fuera de ese radio de deteccion no lo huele");
    ImGui::Text("RandomJiggleLimit");
    ImGui::SliderFloat("°", &dir, 0.0f, 360.0f);
    Pregunta("Al chocar 2 o mas blobs del mismo grupo etario la direccion del blob resultante es la suma de las direcciones mas un valor aleatorio entre 0 y este valor introducido");
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

void Graph::clean(ALLEGRO_DISPLAY* ventana_a_borrar)
{
    ImGui_ImplAllegro5_Shutdown();
    ImGui::DestroyContext();
    al_destroy_event_queue(queue);
    al_destroy_display(ventana_a_borrar);
    al_shutdown_image_addon();
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


int Graph::Ventanainicio(void)
{
    int todo_ok = 1;
    ImGuiWindowFlags window_flag = 0;
    window_flag |= ImGuiWindowFlags_NoResize;
    window_flag |= ImGuiWindowFlags_NoCollapse;
    ImGui::Begin("Ingrese los Parametros iniciales", NULL, window_flag);                          // Create a window called "Hello, world!" and append into it
    ImGui::Text("Inserte Modo ");
    const char* items[] = { "1", "2" };
    static const char* item_current = items[0];            // Here our selection is a single pointer stored outside the object.
    if (ImGui::BeginCombo("<-", item_current, 0)) // the first parameter have to be there, the second parameter is the label previewed before opening the combo.
    {
        for (int n = 0; n < IM_ARRAYSIZE(items); n++)
        {
            bool is_selected = (item_current == items[n]);
            if (ImGui::Selectable(items[n], is_selected))
                item_current = items[n];
            if (is_selected)
                ImGui::SetItemDefaultFocus();   // Set the initial focus when opening the combo (scrolling + for keyboard navigation support in the upcoming navigation branch)
        }
        ImGui::EndCombo();
    }
    Pregunta("En el Modo 1 los blobs comparten la misma velocidad. \nEn el modo 2, cada blob tiene una velocidad máxima distinta aleatoria entre 0 y el valor maximo. \nTodas comparten la velocidad porcentual");
    modo = std::stoi(item_current);
    ImGui::Text("Inserte Velocidad Maxima");
    ImGui::DragFloat("pixeles/segundo", &Vel_max, 0.05, 0, 1000000);
    Pregunta("Luego podra modificar la velocidad deseada para los Blobs desde los ajustes en la simulacion");
    ImGui::Text("Cantidad Inicial de Blobs");
    ImGui::DragInt("BabyBlobs", &cant_inicial_blobs, 0.03, 0, 1000000);
    Pregunta("La simulacion inicia con la cantidad deseada de babyBlobs configurada con este parametro");
    ImGui::Text("Cantidad de Comida Inicial");
    ImGui::DragInt("Comidas", &foodCount, 0.03, 0, 1000000);
    Pregunta("Este parametro refiere a la cantidad de comida que existira en todo momento en la simulacion, tranquilo, a este parametro podes modificarlo mas tarde");
    ImGui::Text("");
    if (ImGui::Button("Ok a simular"))                           // Buttons return true when clicked (most widgets return true when edited/activated)
        todo_ok = 0;
    ImGui::End();
    return todo_ok;

    //ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
    //ImGui::Checkbox("Another Window", &show_another_window);
    //
    //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

}