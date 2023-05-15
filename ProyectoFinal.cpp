/**************Presentación***********
Nombre: Barba Ramírez Kevin Josué y Martínez Muñoz Alejandra Estefanía
Fecha: domingo 14-mayo-2023
Programa: ProyectoFinal.cpp
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
Profesor: Cruz Franco Carlos Javier
Descripción: Programa que almacena datos específicos sobre alumnos (nombre, materias, maestros, carrera y calificaciones) para mostrar un promedio de calificaciones,
además que permite modificar/borrar cualquiera de los datos
***************************************/
#include <iostream> //Se incluye la librería principal
#include <string>  //Librería para poder usar datos del tipo string
#include <vector> ////Estructura de vector utilizada para ordenar los datos y permitir guardar más de una cosa en cada estructura
using namespace std; // Marca el uso del cout sin la funcion del std

//Declara la estructura de los alumnos
struct Alumno{
	string nombre;
	string carrera;
	vector<string> materias;
	vector<string> maestros;
	vector<float> calificaciones;
};

//Declara las funciones void
void agregar();
void editar();
void vaciar();
void ver();

// Variables para almacenar los datos de los alumnos que se quieran registrar
    vector<Alumno> alumnos;
    
int main(){
	//Le pone un color bonito al programa :)
	system ("color 06");
	//Llama a la estructura
	struct Alumno;
	//Muestra la bienvenida al usuario
	cout << "------------BIENVENIDO------------" << endl;
	//Declara la variable para la seleccion del menú
	char sel;
	//Inicia un ciclo hasta que se quiera cerrar el programa
	do{
		//Muestra el menú
		cout << "----------------------------------" << endl;
		cout << "|Que quieres hacer?              |" << endl;
		cout << "|1.Agregar alumno                |" << endl;
		cout << "|2.Editar alumno                 |" << endl;
		cout << "|3.Vaciar alumno                 |" << endl;
		cout << "|4.Ver alumno (datos y promedio) |" << endl;
		cout << "|5.Salir                         |" << endl;
		cout << "----------------------------------" << endl;
		cout << "Seleccion: ";
		cin >> sel;
		//Inicia un switch según la selección del usuario
		switch(sel){
			//Indicaciones de como agregar un alumno
			case '1':
				agregar();
			break;
			//Indicaciones de como editar un alumno
			case '2':
				editar();
			break;
			//Indicaciones de como vaciar un alumno
			case '3':
				vaciar();
			break;
			//Indicaciones de como ver los datos y promedio de un alumno
			case '4':
				ver();
			break;
			//Indicaciones para finalizar el programa
			case '5':
				cout << "----------------------------------------------------" << endl;
				cout << "Eso era todo, muchas gracias por usar el programa :)" << endl;
				cout << "----------------------------------------------------" << endl;
			break;
			//Indicaciones para cuando no se cumple ningún caso anterior
			default:
				cout << "Noup, definitivamente esa no es una opcion, intenta otra vez" << endl;
				cout << "----------------------------------" << endl;
			break;
			}
	}while(sel!='5');
}

void agregar() {
    Alumno alumno;
    cin.ignore();
    cout << "Ingrese el nombre del alumno: ";
    getline(cin, alumno.nombre);
    cout << "Ingrese la carrera del alumno: ";
    getline(cin, alumno.carrera);
    cout << "Ingrese el numero de materias: ";
    int cuantas;
    cin >> cuantas;
    cin.ignore();
    for(int i = 0; i < cuantas; i++) {
        cout << "Ingrese el nombre de la materia " << i+1 << ": ";
        string materia;
        getline(cin, materia);
        alumno.materias.push_back(materia);
        cout << "Ingrese el nombre del maestro de la materia " << i+1 << ": ";
        string maestro;
        getline(cin, maestro);
        alumno.maestros.push_back(maestro);
        cout << "Ingrese la calificacion de la materia " << i+1 << ": ";
        float calificacion;
        cin >> calificacion;
        alumno.calificaciones.push_back(calificacion);
        cin.ignore();
    }
    alumnos.push_back(alumno);
    cout << "Alumno registrado exitosamente" << endl;
    cout << "----------------------------------" << endl;
system("pause");
}

void editar() {
    if (alumnos.empty()) {
        cout << "No hay alumnos registrados" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    cout << "Alumnos registrados:" << endl;
    for (int i = 0; i < alumnos.size(); i++) {
        cout << i << ". " << alumnos[i].nombre << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Seleccione un alumno: ";
    int seleccion;
    cin >> seleccion;
    if (seleccion < 0 || seleccion >= alumnos.size()) {
        cout << "Seleccion invalida" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    Alumno& alumno = alumnos[seleccion];
    cout << "----------------------------------" << endl;
    cout << "Datos del alumno seleccionado:" << endl;
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Carrera: " << alumno.carrera << endl;
    cout << "Materias: " << endl;
    for (int i = 0; i < alumno.materias.size(); i++) {
        cout << "- " << alumno.materias[i] << endl;
        cout << "  Maestro: " << alumno.maestros[i] << endl;
        cout << "  Calificacion: " << alumno.calificaciones[i] << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Que dato quieres editar?" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Carrera" << endl;
    cout << "3. Materias" << endl;
    int opcion;
    cin >> opcion;
    cin.ignore();
    cout << "----------------------------------" << endl;
    switch (opcion) {
        case 1:
            cout << "Ingrese el nuevo nombre: ";
            getline(cin, alumno.nombre);
            cout << "----------------------------------" << endl;
        break;
        case 2:
            cout << "Ingrese la nueva carrera: ";
            getline(cin, alumno.carrera);
            cout << "----------------------------------" << endl;
        break;
        case 3:
            if (alumno.materias.empty()) {
                cout << "El alumno no tiene materias registradas" << endl;
                cout << "----------------------------------" << endl;
                return;
            }
            cout << "Materias:" << endl;
            for (int i = 0; i < alumno.materias.size(); i++) {
                cout << i+1 << ". " << alumno.materias[i] << endl;
            }
            cout << "Seleccione una materia: ";
            int cual;
            cin >> cual;
            if (cual < 1 || cual > alumno.materias.size()) {
                cout << "Seleccion invalida" << endl;
                cout << "----------------------------------" << endl;
                return;
            }
            cout << "----------------------------------" << endl;
            cout << "Que dato de la materia " << alumno.materias[cual-1] << " quieres editar?" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Maestro" << endl;
            cout << "3. Calificacion" << endl;
            int que;
            cin >> que;
            cout << "----------------------------------" << endl;
            switch (que) {
		        case 1:
		            cout << "Ingrese el nuevo nombre de la materia: ";
		            cin.ignore();
		            getline(cin, alumno.materias[cual-1]);
		            cout << "----------------------------------" << endl;
		        break;
		        case 2:
		            cout << "Ingrese el nuevo maestro de la materia: ";
		            cin.ignore();
		            getline(cin, alumno.maestros[cual-1]);
		            cout << "----------------------------------" << endl;
		        break;
		        case 3:
		            cout << "Ingrese la nueva calificacion de la materia: ";
		            cin >> alumno.calificaciones[cual-1];
		            cout << "----------------------------------" << endl;
		        break;
		        default:
		            cout << "Opcion invalida (?" << endl;
		            cout << "----------------------------------" << endl;
		        break;
		    }
		break;
		default:
		    cout << "Opcion invalida (?" << endl;
		    cout << "----------------------------------" << endl;
		break;
	}
	cout << "Alumno modificado correctamente :)" << endl;
	cout << "----------------------------------" << endl;
system("pause");
}

void vaciar(){
    if (alumnos.empty()) {
        cout << "No hay alumnos registrados" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    cout << "Alumnos registrados:" << endl;
    for (int i = 0; i < alumnos.size(); i++) {
        cout << i << ". " << alumnos[i].nombre << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Seleccione un alumno para eliminar: ";
    int seleccion;
    cin >> seleccion;
    if (seleccion < 0 || seleccion >= alumnos.size()) {
        cout << "Seleccion invalida" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    // Eliminar al alumno seleccionado
    alumnos.erase(alumnos.begin() + seleccion);
    cout << "Alumno eliminado exitosamente" << endl;
    cout << "----------------------------------" << endl;
system("pause");
}

void ver(){
	if (alumnos.empty()) {
        cout << "No hay alumnos registrados" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    cout << "Alumnos registrados:" << endl;
    for (int i = 0; i < alumnos.size(); i++) {
        cout << i << ". " << alumnos[i].nombre << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Seleccione un alumno: ";
    int seleccion;
    cin >> seleccion;
    if (seleccion < 0 || seleccion >= alumnos.size()) {
        cout << "Seleccion invalida." << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    Alumno alumno = alumnos[seleccion];
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Carrera: " << alumno.carrera << endl;
    cout << "Materias:" << endl;
    for (int i = 0; i < alumno.materias.size(); i++) {
        cout << "- " << alumno.materias[i] << endl;
        cout << "  Maestro: " << alumno.maestros[i] << endl;
        cout << "  Calificacion: " << alumno.calificaciones[i] << endl;
    }
    // Obtener las calificaciones del alumno seleccionado y calcular el promedio
    float sum = 0.0, prom;
    vector<float> calificaciones = alumnos[seleccion].calificaciones;
    for(int i = 0; i < calificaciones.size(); i++) {
        sum += calificaciones[i];
    }
    prom = sum / calificaciones.size();
    // Mostrar el promedio al usuario
    cout << "El promedio del alumno " << alumnos[seleccion].nombre << " es: " << prom << endl;
    if(prom <= 59){
    	cout << "Reprobado :(" << endl;
    	cout << "----------------------------------" << endl;
	}else if(prom > 60 && prom < 79){
		cout << "Regular O.o" << endl;
		cout << "----------------------------------" << endl;
	}else if(prom > 80 && prom < 89){
		cout << "Muy bien :)" << endl;
		cout << "----------------------------------" << endl;
	}else if(prom > 90){
		cout << "Excelente! :D" << endl;
		cout << "----------------------------------" << endl;
	}
system("pause");
}
