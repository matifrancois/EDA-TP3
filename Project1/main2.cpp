#include <stdint.h>
#include "prototype.h"
#include "Graph.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "imgui.h"
#include "imgui_impl_allegro5.h"


int main(void)
{
	Graph grafico;
	if (!grafico.grafica())
		printf("error de inicializacion\n");
	return 0;
}