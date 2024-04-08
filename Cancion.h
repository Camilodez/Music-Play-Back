#ifndef CANCION_H
#define CANCION_H

#include <string>

class Cancion {
private:
    int ID; // Llave primaria, autogenerada que aumenta de 1 en 1
    std::string titulo; // Título de la canción
    std::string artista; // Nombre del artista
    std::string album; // Nombre del álbum
    std::string genero; // Género musical
    int cantidadEscuchada; // Contador de veces que ha sido escuchada la canción

public:
    // Constructor
   Cancion(int id, const std::string& titulo, const std::string& artista,
            const std::string& album, const std::string& genero, int cantidadEscuchada)
        : ID(id), titulo(titulo), artista(artista), album(album),
          genero(genero), cantidadEscuchada(cantidadEscuchada) {}
    
    // Posiblemente también quieras un constructor por defecto
    Cancion() : ID(0), titulo(""), artista(""), album(""), genero(""), cantidadEscuchada(0) {}



        friend std::ostream& operator<<(std::ostream& os, const Cancion& cancion) {
        os << cancion.titulo << " - " << cancion.artista;  // Modifica según la estructura de Cancion
        return os;
    }


        bool operator<(const Cancion& other) const {
        return this->titulo < other.titulo; // Comparar por título, por ejemplo
    }

    bool operator>(const Cancion& other) const {
        return this->titulo > other.titulo; // Comparar por título
    }

    bool operator==(const Cancion& other) const {
        return this->ID == other.ID; // Comparar por ID, por ejemplo
    }

    // Getters y setters para cada campo
    int getID() const { return ID; }
    void setID(int id) { ID = id; }

    std::string getTitulo() const { return titulo; }
    void setTitulo(const std::string& titulo) { this->titulo = titulo; }

    std::string getArtista() const { return artista; }
    void setArtista(const std::string& artista) { this->artista = artista; }

    std::string getAlbum() const { return album; }
    void setAlbum(const std::string& album) { this->album = album; }

    std::string getGenero() const { return genero; }
    void setGenero(const std::string& genero) { this->genero = genero; }

    int getCantidadEscuchada() const { return cantidadEscuchada; }
    void setCantidadEscuchada(int cantidadEscuchada) { this->cantidadEscuchada = cantidadEscuchada; }
};

#endif // CANCION_H
