/**************Presentaci�n***********
Nombre: Barba Ram�rez Kevin Josu� y Mart�nez Mu�oz Alejandra Estefan�a
Fecha: jueves 18-mayo-2023
Programa: ProyectoFinal.cpp
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIERÍA EN COMPUTACI�N / 2DO SEMESTRE
Profesor: Cruz Franco Carlos Javier
Descripci�n: Programa que almacena datos espec�ficos sobre alumnos (nombre, materias, maestros, carrera y calificaciones) para mostrar un promedio de calificaciones,
adem�s que permite modificar/borrar cualquiera de los datos
***************************************/
#include <iostream> //Se incluye la librer�a principal
#include <string>  //Librer�a para poder usar datos del tipo string
#include <vector> //Estructura de vector utilizada para ordenar los datos y permitir guardar m�s de una cosa en cada estructura
using namespace std; //Marca el uso del cout sin la funcion del std

//Declara la estructura de los alumnos
struct Alumno{
	string nombre;
	string carrera;
	//Los siguientes 3 datos se declaran con vector para poder almacenar m�s de un dato diferente en �l
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
	//Declara la variable para la seleccion del men�
	char sel;
	//Inicia un ciclo hasta que se quiera cerrar el programa
	do{
		//Muestra el men�
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
		
		//Inicia un switch seg�n la selecci�n del usuario
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
			//Indicaciones para cuando no se cumple ning�n caso anterior
			default:
				cout << "Noup, definitivamente esa no es una opcion, intenta otra vez" << endl;
				cout << "----------------------------------" << endl;
			break;
			}
	//Le da la condici�n de finalizar al while
	}while(sel!='5');
	
}

//Apartado de voids
void agregar() { //Para la opci�n agregar alumno
    Alumno alumno;
    //Pide los datos del alumno
    cin.ignore();
    cout << "Ingrese el nombre del alumno: ";
    getline(cin, alumno.nombre);
    cout << "Ingrese la carrera del alumno: ";
    getline(cin, alumno.carrera);
    cout << "Ingrese el numero de materias: ";
    int cuantas;
    cin >> cuantas;
    cin.ignore();
    //Hace un for para preguntar por materias diferentes seg�n el n�mero de materias que dijo el usuario
    for(int i = 0; i < cuantas; i++) {
        cout << "Ingrese el nombre de la materia " << i+1 << ": ";
        string materia;
        getline(cin, materia);
        alumno.materias.push_back(materia); //Indica que ha aumentado una materia
        cout << "Ingrese el nombre del maestro de la materia " << i+1 << ": ";
        string maestro;
        getline(cin, maestro);
        alumno.maestros.push_back(maestro); //Indica que ha aumentado un maestro
        cout << "Ingrese la calificacion de la materia " << i+1 << ": ";
        float calificacion;
        cin >> calificacion;
        alumno.calificaciones.push_back(calificacion); //Indica que se ha registrado una nueva calificaci�n
        cin.ignore();
    }
    alumnos.push_back(alumno); //Indica que ya hay un alumno m�s guardado
    cout << "Alumno registrado exitosamente" << endl;
    cout << "----------------------------------" << endl;
system("pause"); //Lo pusimos para que el men� no se muestre de golpe al terminar el proceso
}

void editar() { //Para editar a los alumnos
    if (alumnos.empty()) { //Si a�n no se han agregado
        cout << "No hay alumnos registrados" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    cout << "Alumnos registrados:" << endl; 
    for (int i = 1; i < alumnos.size(); i++) { //Se hace un for para mostrar la lista de alumnos ya registrados
        cout << i << ". " << alumnos[i].nombre << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Seleccione un alumno: ";
    int seleccion;
    cin >> seleccion;
    if (seleccion < 0 || seleccion >= alumnos.size()) { //Valida que el n�mero de alumno realmente existe
        cout << "Seleccion invalida" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    Alumno& alumno = alumnos[seleccion]; //Establece cu�l va a ser el alumno que se va a modificar
    cout << "----------------------------------" << endl;
    cout << "Datos del alumno seleccionado:" << endl;
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Carrera: " << alumno.carrera << endl;
    cout << "Materias: " << endl;
    for (int i = 0; i < alumno.materias.size(); i++) { //Seg�n e� n�mero de materias que se registraron, muestra los datos guardados
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
    switch (opcion) { //Seg�n la opci�n que seleccione
        case 1: //Editar nombre
            cout << "Ingrese el nuevo nombre: ";
            getline(cin, alumno.nombre);
            cout << "----------------------------------" << endl;
        break;
        case 2: //Editar carrera
            cout << "Ingrese la nueva carrera: ";
            getline(cin, alumno.carrera);
            cout << "----------------------------------" << endl;
        break;
        case 3: //Editar materia
            if (alumno.materias.empty()) { //Si no existe ninguna materia guardada
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
            if (cual < 1 || cual > alumno.materias.size()) { //Valida que el numero de materia realmente existe
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
            switch (que) { //Seg�n la opci�n que seleccione
		        case 1: //Editar nombre de materia
		            cout << "Ingrese el nuevo nombre de la materia: ";
		            cin.ignore();
		            getline(cin, alumno.materias[cual-1]);
		            cout << "----------------------------------" << endl;
		        break;
		        case 2: //Editar nombre de maestro de imparte la materia
		            cout << "Ingrese el nuevo maestro de la materia: ";
		            cin.ignore();
		            getline(cin, alumno.maestros[cual-1]);
		            cout << "----------------------------------" << endl;
		        break;
		        case 3: //Editar la calificaci�n de la materia
		            cout << "Ingrese la nueva calificacion de la materia: ";
		            cin >> alumno.calificaciones[cual-1];
		            cout << "----------------------------------" << endl;
		        break;
		        default: //Si selecciona una opci�n que no existe
		            cout << "Opcion invalida (?" << endl;
		            cout << "----------------------------------" << endl;
		        break;
		    }
		break;
		default: //Si selecciona una opci�n que no existe
		    cout << "Opcion invalida (?" << endl;
		    cout << "----------------------------------" << endl;
		break;
	}
	cout << "Alumno modificado correctamente :)" << endl;
	cout << "----------------------------------" << endl;
system("pause"); //Lo pusimos para que el men� no se muestre de golpe al terminar el proceso
}

void vaciar(){ //Para eliminar los alumnos ya registrados
    if (alumnos.empty()) { //Si a�n no se guardan alumnos
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
    if (seleccion < 0 || seleccion >= alumnos.size()) { //Valida que el numero del alumno realmente existe
        cout << "Seleccion invalida" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    // Eliminar al alumno seleccionado
    alumnos.erase(alumnos.begin() + seleccion);
    cout << "Alumno eliminado exitosamente" << endl;
    cout << "----------------------------------" << endl;
system("pause"); //Lo pusimos para que el men� no se muestre de golpe al terminar el proceso
}

void ver(){ //Para ver la lista de alumnos guardados
	if (alumnos.empty()) { //Si �un no hay alumnos registrados y el txt est� vac�o
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
    if (seleccion < 0 || seleccion >= alumnos.size()) { //Valida que el alumno seleccionado realmente existe
        cout << "Seleccion invalida." << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    Alumno alumno = alumnos[seleccion]; //Muestra todos los datos del alumno seleccionado
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
    // Mostrar el promedio al usuario con el mensaje que corresponde
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
system("pause"); //Lo pusimos para que el men� no se muestre de golpe al terminar el proceso
}
