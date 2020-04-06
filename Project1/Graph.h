#pragma once
#include <stdint.h>
#include "prototype.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "imgui.h"
#include "imgui_impl_allegro5.h"
#include "prototype.h"
#include <string>

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
        running_inicio = true;
        cerrar = false;
    }
    int grafica(void);
    void printBlobs(void);
    int get_info(void);
    bool cerrar;
private:
    int inicializa(void);
    ALLEGRO_DISPLAY* display_principal;
    ALLEGRO_DISPLAY* display_entrada;

    ALLEGRO_BITMAP* background;
    ALLEGRO_BITMAP* babyBlob;
    ALLEGRO_BITMAP* food;
    ALLEGRO_BITMAP* grownBlob;
    ALLEGRO_BITMAP* goodOldBlob;
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
    int modo;
    float Vel_max;
    int cant_inicial_blobs;

    bool show_another_window;
    ImVec4 clear_color;  //creamos un vector de cuatro dimensiones para el color del fondo a utilizar.
    bool running;
    bool running_inicio;
    ALLEGRO_EVENT ev;
    void VentanaPrincipal(void);
    void Pregunta(char* texto_ingresado);
    void clean(ALLEGRO_DISPLAY* ventana_a_borrar);
    int Ventanainicio(void);
};

