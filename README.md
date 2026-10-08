📖 Agenda de Contactos (Implementación Multi-Lenguaje)

Un sistema de consola para la gestión eficiente de contactos y el registro del historial de llamadas.

Para demostrar versatilidad y dominio de los fundamentos de la Programación Orientada a Objetos (POO), este repositorio contiene dos implementaciones completas e independientes del mismo sistema, desarrolladas en C++ y Java.

🚀 Funcionalidades Comunes

Ambas versiones comparten la misma lógica de negocio y ofrecen un menú interactivo con las siguientes opciones:

Gestión de Contactos (CRUD):

➕ Agregar: Crea un nuevo contacto (Nombre, Teléfono, Correo).

📋 Listar: Muestra todos los contactos registrados.

🔍 Buscar: Búsqueda flexible (case-insensitive) por nombre parcial o completo.

✏️ Editar: Permite actualizar el teléfono o correo de un contacto.

🗑️ Eliminar: Borra un contacto del sistema.

📞 Historial de Llamadas:

Permite registrar llamadas (hasta 3 registros por contacto) almacenando la duración en minutos.

Calcula automáticamente el tiempo total hablado con un contacto específico.

📂 Estructura del Repositorio

El proyecto está dividido en dos directorios principales, uno para cada ecosistema:

📁 Agenda-MultiLenguaje/
├── 📁 Agenda-CPP/             # Implementación en C++
│   └── Agenda.cpp             # Código fuente principal
├── 📁 Agenda-Java/            # Implementación en Java (Proyecto Maven)
│   ├── pom.xml                # Configuración de dependencias Maven
│   └── 📁 src/main/java/...   # Clases Java (Agenda.java, Contacto.java)
└── README.md                  # Este documento


🛠️ Tecnologías Aplicadas

Versión C++

Lenguaje: C++11 o superior.

Características: Uso de la biblioteca estándar (STL) incluyendo <vector>, <string>, <algorithm>. Gestión de memoria dinámica y manipulación directa de flujos de entrada/salida.

Versión Java

Lenguaje: Java (JDK 8+).

Gestor de dependencias: Maven (pom.xml).

Características: Arquitectura modular separando las entidades (Contacto.java) de la lógica principal (Agenda.java). Uso de Java Collections Framework (ArrayList).

💻 Instrucciones de Uso

▶️ Opción 1: Ejecutar la versión en C++

Necesitas un compilador de C++ (como GCC/g++).

Navega a la carpeta de C++:

cd Agenda-CPP


Compila el archivo:

g++ -o agenda Agenda.cpp


Ejecuta el programa:

Windows: agenda.exe

Linux/Mac: ./agenda

▶️ Opción 2: Ejecutar la versión en Java

Puedes utilizar un IDE (como IntelliJ IDEA, Eclipse, NetBeans) o compilarlo mediante consola si tienes el JDK instalado.

Navega a la carpeta del código fuente de Java:

cd Agenda-Java/src/main/java/com/mycompany/agenda


Compila las clases:

javac Agenda.java Contacto.java


Ejecuta la clase principal (volviendo a la raíz de src/main/java):

cd ../../../..
java com.mycompany.agenda.Agenda


(Nota: Si usas Maven, simplemente puedes ejecutar mvn clean install y luego mvn exec:java -Dexec.mainClass="com.mycompany.agenda.Agenda" desde la raíz de la carpeta Java).
