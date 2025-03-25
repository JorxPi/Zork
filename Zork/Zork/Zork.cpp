// Zork.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Entity.h"
#include "Room.h"
#include "Item.h"
#include "Exit.h"
#include "Creature.h"
#include "Player.h"

int main() {
    Room hall("Hall", "A large, echoing stone hall with torches on the walls.");

    Creature npc("Old Man", "He looks wise and carries a walking stick.", &hall);

    Item box("Wooden Box", "An old wooden box with a rusty latch.");

    Room garden("Garden", "A peaceful garden with trimmed hedges, blooming flowers, and a stone fountain gently trickling water in the center.");

    Exit toGarden("south", &hall, &garden);
    Exit toHall("north", & garden, &hall);
  
    hall.Add(&box);
    hall.Add(&toGarden);
    hall.Add(&npc);
    garden.Add(&toHall);

    Player player("You", "Just an adventurer trying to explore.", &hall);

    hall.Update();

    while (true) {
        player.Update(); 
    }

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
