#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// ---------- Clase Contacto ----------

class Contacto {
private:
    string nombre;
    string telefono;
    string email;
    vector<int> llamadas; // AHORA LAS LLAMADAS PERTENECEN A LA CLASE

public:
    Contacto(const string& nombre, const string& telefono, const string& email)
        : nombre(nombre), telefono(telefono), email(email) {}

    const string& getNombre() const { return nombre; } // Retornando referencia constante

    const string& getTelefono() const { return telefono; }
    void setTelefono(const string& telefono) { this->telefono = telefono; }

    const string& getEmail() const { return email; }
    void setEmail(const string& email) { this->email = email; }

    string toString() const {
        return nombre + " | Tel: " + telefono + " | Email: " + email;
    }

    // Métodos para manejar llamadas internamente
    vector<int>& getLlamadas() { return llamadas; }
    
    void agregarLlamada(int minutos) {
        llamadas.push_back(minutos);
    }
};

// ---------- Datos globales ----------

const int MAX_LLAMADAS = 3;

// Un solo vector de objetos, eliminada la lista paralela de llamadas.
vector<Contacto> agenda;

// ---------- Utilidades ----------

void mostrarMenu() {
    cout << "\n===== AGENDA DE CONTACTOS =====" << endl;
    cout << "1. Agregar contacto" << endl;
    cout << "2. Listar contactos" << endl;
    cout << "3. Buscar contacto" << endl;
    cout << "4. Editar contacto" << endl;
    cout << "5. Eliminar contacto" << endl;
    cout << "6. Gestionar llamadas" << endl;
    cout << "7. Salir" << endl;
}

string leerTexto(const string& mensaje) {
    cout << mensaje;
    string texto;
    getline(cin, texto);
    return texto;
}

int leerEntero(const string& mensaje) {
    string linea = leerTexto(mensaje);
    try {
        size_t posicion;
        int valor = stoi(linea, &posicion);
        if (posicion != linea.size()) {
            return -1; // hay caracteres extra después del número
        }
        return valor;
    } catch (...) {
        return -1;
    }
}

string aMinusculas(string texto) {
    transform(texto.begin(), texto.end(), texto.begin(),
              [](unsigned char c) { return tolower(c); });
    return texto;
}

// Devuelve el índice del contacto con ese nombre exacto, o -1 si no existe.
int buscarIndicePorNombre(const string& nombre) {
    for (size_t i = 0; i < agenda.size(); i++) {
        if (agenda[i].getNombre() == nombre) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

// ---------- Opciones del menú ----------

void agregarContacto() {
    string nombre = leerTexto("Nombre: ");
    string telefono = leerTexto("Telefono: ");
    string email = leerTexto("Correo: ");

    agenda.push_back(Contacto(nombre, telefono, email));
    cout << "Contacto agregado." << endl;
}

void listarContactos() {
    if (agenda.empty()) {
        cout << "La agenda esta vacia." << endl;
        return;
    }
    int numero = 1;
    for (const Contacto& c : agenda) {
        cout << numero << ". " << c.toString() << endl;
        numero++;
    }
}

void buscarContacto() {
    string texto = aMinusculas(leerTexto("Texto a buscar: "));
    bool encontrado = false;

    for (const Contacto& c : agenda) {
        if (aMinusculas(c.getNombre()).find(texto) != string::npos) {
            cout << "- " << c.toString() << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron coincidencias." << endl;
    }
}

void editarContacto() {
    string nombre = leerTexto("Nombre exacto del contacto a editar: ");
    int indice = buscarIndicePorNombre(nombre);

    if (indice == -1) {
        cout << "Contacto no encontrado." << endl;
        return;
    }

    Contacto& c = agenda[indice];
    cout << "1. Editar telefono" << endl;
    cout << "2. Editar correo" << endl;
    int opcion = leerEntero("Elige una opcion: ");

    if (opcion == 1) {
        c.setTelefono(leerTexto("Nuevo telefono: "));
        cout << "Telefono actualizado." << endl;
    } else if (opcion == 2) {
        c.setEmail(leerTexto("Nuevo correo: "));
        cout << "Correo actualizado." << endl;
    } else {
        cout << "Opcion no valida." << endl;
    }
}

void eliminarContacto() {
    string nombre = leerTexto("Nombre exacto del contacto a eliminar: ");
    int indice = buscarIndicePorNombre(nombre);

    if (indice == -1) {
        cout << "Contacto no encontrado." << endl;
        return;
    }

    agenda.erase(agenda.begin() + indice);
    cout << "Contacto eliminado." << endl;
}

void registrarLlamada(int indice) {
    Contacto& c = agenda[indice]; // Accedemos al contacto directamente

    if (static_cast<int>(c.getLlamadas().size()) >= MAX_LLAMADAS) {
        cout << "Este contacto ya tiene " << MAX_LLAMADAS << " llamadas registradas." << endl;
        return;
    }

    int minutos = leerEntero("Duracion de la llamada (minutos): ");
    if (minutos <= 0) {
        cout << "Los minutos deben ser un numero entero positivo." << endl;
        return;
    }

    c.agregarLlamada(minutos); // Añadimos la llamada internamente en el objeto
    cout << "Llamada registrada (" << c.getLlamadas().size() << "/" << MAX_LLAMADAS << ")." << endl;
}

void calcularTotalMinutos(int indice) {
    int total = 0;
    // Iteramos utilizando los métodos del propio objeto
    for (int minutos : agenda[indice].getLlamadas()) {
        total += minutos;
    }
    cout << "Total de minutos de " << agenda[indice].getNombre() << ": " << total << endl;
}

void gestionarLlamadas() {
    if (agenda.empty()) {
        cout << "No hay contactos en la agenda." << endl;
        return;
    }

    cout << "1. Registrar llamada" << endl;
    cout << "2. Calcular total de minutos" << endl;
    int opcion = leerEntero("Elige una opcion: ");

    if (opcion != 1 && opcion != 2) {
        cout << "Opcion no valida." << endl;
        return;
    }

    string nombre = leerTexto("Nombre exacto del contacto: ");
    int indice = buscarIndicePorNombre(nombre);

    if (indice == -1) {
        cout << "Contacto no encontrado." << endl;
        return;
    }

    if (opcion == 1) {
        registrarLlamada(indice);
    } else {
        calcularTotalMinutos(indice);
    }
}

// ---------- Programa principal ----------

int main() {
    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("Elige una opcion: ");
        switch (opcion) {
            case 1: agregarContacto(); break;
            case 2: listarContactos(); break;
            case 3: buscarContacto(); break;
            case 4: editarContacto(); break;
            case 5: eliminarContacto(); break;
            case 6: gestionarLlamadas(); break;
            case 7: cout << "Hasta pronto!" << endl; break;
            default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 7);

    return 0;
}