#pragma once
#include <stdint.h>
#include "prototype.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "imgui.h"
#include "imgui_impl_allegro5.h"
#include "prototype.h"

class Graph
{
public:
    Graph()
    {
        Death[0] = PROBABILIDAD_MUERTE_BABY;
        Death[1] = PROBABILIDAD_MUERTE_GROWN;
        Death[2] = PROBABILIDAD_MUERTE_OLD;
        velp = PORCENTAJE_INICIAL_VEL;
        smellRadius = SMELLRADIUS_INICIAL;
        foodCount = FOOD_COUNT_INICIAL;
        dir = DIR_INICIAL;
        display_principal = NULL;
        queue = NULL;
        close_display = false;
        show_demo_window = false;
        show_another_window = false;
        clear_color = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);  //creamos un vector de cuatro dimensiones para el color del fondo a utilizar.
        running = true;
    }
    int grafica(void);
private:
    int inicializa(void);
    ALLEGRO_DISPLAY* display_principal;
    //crea el evento
    ALLEGRO_EVENT_QUEUE* queue;
    bool close_display;
    //con estos se controla el abrir o cerrar una ventana y el checkbox si esta o no marcado
    bool show_demo_window;
    float Death[3];
    float velp;
    float smellRadius;
    int foodCount;
    float dir;

    bool show_another_window;
    ImVec4 clear_color;  //creamos un vector de cuatro dimensiones para el color del fondo a utilizar.
    bool running;
    ALLEGRO_EVENT ev;
    void VentanaPrincipal(void);
    void Pregunta(char* texto_ingresado);
    void clean(void);
};

