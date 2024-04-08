//g++ -std=c++11 main.cpp -o test; ./test


#include <iostream>
#include <string>
#include <limits>

#include "arbolAVL.h"
#include "nodoAVL.h"
#include <string>
#include <sstream>

#include <fstream>

void mostrarMenu() {
    std::cout << "\nMenú Principal\n";
    std::cout << "1. Agregar Canción\n";
    std::cout << "2. Eliminar Canción\n";
    std::cout << "3. Buscar por Título\n";
    std::cout << "4. Buscar por Artista\n";
    std::cout << "5. Buscar por Álbum\n";
    std::cout << "6. Buscar por Género\n";
     std::cout << "7. Inicializar Arbol\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opción: ";
}



int main(int argc, char *argv[]) {

     ArbolAVL<Cancion> PorArtista;
     ArbolAVL<Cancion> PorTitulo;
     ArbolAVL<Cancion> PorAlbum;
     ArbolAVL<Cancion> PorGenero;

       std::ifstream file("BD.csv");
        std::string linea;

    int opcion;
    std::string titulo, artista, album, genero;
    int id, cantidadEscuchada;

    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora el resto de la línea

        switch (opcion) {
            case 1: {
                
                break;
            }
            case 2:
                std::cout << "Eliminar Canción. Ingrese el ID: ";
                std::cin >> id;
             
                break;
            case 3:
                std::cout << "Buscar por Título. Ingrese el título: ";
                getline(std::cin, titulo);
                // arbolPorTitulo.buscar(titulo);
                break;
            case 4:
                std::cout << "Buscar por Artista. Ingrese el artista: ";
                getline(std::cin, artista);
                // arbolPorArtista.buscar(artista);
                break;
            case 5:
                std::cout << "Buscar por Álbum. Ingrese el álbum: ";
                getline(std::cin, album);
                // arbolPorAlbum.buscar(album);
                break;
            case 6:
                std::cout << "Buscar por Género. Ingrese el género: ";
                getline(std::cin, genero);
                // arbolPorGenero.buscar(genero);
                break;
            case 7:
              
                  while (std::getline(file, linea)) {
                std::stringstream ss(linea);
                int id, cantidadEscuchada;
                std::string titulo, artista, album, genero;

                // Usa std::getline para leer cada campo separado por comas
                std::getline(ss, linea, ','); // Leer ID
                id = std::stoi(linea); // Convertir ID a entero
                std::getline(ss, titulo, ',');
                std::getline(ss, artista, ',');
                std::getline(ss, album, ',');
                std::getline(ss, genero, ',');
                std::getline(ss, linea); // Leer Cantidad Escuchada
                cantidadEscuchada = std::stoi(linea); // Convertir Cantidad Escuchada a entero

                Cancion cancion(id, titulo, artista, album, genero, cantidadEscuchada);

                // Insertar la canción en los árboles AVL
                PorTitulo.insertar(cancion);
                PorArtista.insertar(cancion);
                PorAlbum.insertar(cancion);
                PorGenero.insertar(cancion);
    }

    file.close();
             

                
                break;
            case 0:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no válida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}
