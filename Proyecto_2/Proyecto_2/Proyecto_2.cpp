#include <iostream>
#include <string>
#include <vector>
#include <ctime>

//Colores para el texto
#include "colors.h"

//Clases a utilizar en el programa
#include "Lista.h"
#include "Jugador.h"
#include "PoolGeneral.h"
#include "Carta.h"
#include "Planta.h"
#include "Hongo.h"
#include "Fungicida.h"
#include "Truco.h"

using namespace std; 

int main()
{
    //PARA DESORDENAR EL POOL GENERAL
    srand(static_cast<unsigned>(time(nullptr))); //Inicializar una semilla aleatoria de numeros para barajar segun el tiempo 
    PoolGeneral poolGeneral; //Inicializacion del objeto de pool general que se usara en el programa

    vector<Jugador*> jugadores; //Vector de jugadores
    
    //Variables temporales que se utilizan en el programa
    Carta* carta;
    Carta* p;
    Planta* planta;
    Lista g1, g2; 
    
    //Variables varias
    int op, cantJ, condicion, num, num2, j;
    int contadorR = 0, contadorAm = 0, contadorAz = 0;
    char c = '0', c1, c2;
    string nombre;

    //MENU PRINCIPAL
    do {
        cout << GREEN << "PLANTAS VS HONGOS!" << endl;
        cout << WHITE << "1. Nueva partida \n2. Cerrar juego \n-> ";
        cin >> op;

        switch (op)
        {
        case 1:
            do
            { //Definir cantidad de jugadores en la partida
                cout << "\nCANTIDAD DE JUGADORES (2 a 4 jugadores): \n-> ";
                cin >> cantJ;

                if (cantJ < 2 || cantJ > 4)
                {
                    cout << "Solo se admiten de 2 a 4 jugadores. " << endl;
                    cout << " " << endl;
                }
            } while (cantJ < 2 || cantJ > 4); //Repetir hasta que se coloque una cantidad entre 2 y 4

            //Definir el nombre de cada jugador
            for (int i = 1; i <= cantJ; i++)
            {
                cout << "Ingrese el nickname del jugador " << i << ": \n-> ";
                cin >> nombre;

                jugadores.push_back(new Jugador(nombre));
            }

            cout << " " << endl;
            cout << LGREEN << "INFORMACION DE JUGADORES" << WHITE << endl;

            for (int i = 0; i < cantJ; i++)
            {
                cout << "Jugador " << i + 1 << ": " << jugadores[i]->GetNombre() << endl;
            }

            poolGeneral.GenerarPool(); //Generar pool para la partida
            poolGeneral.Barajar(); //Barajar (desordenar) el pool generado

            cout << " \n" << endl;
            cout << LGREEN << "- - POOL DE LA PARTIDA - -" << WHITE << endl;
            poolGeneral.PrintPool(); //Imprimir el pool que se utilizara en la partida

            //Repartir las cartas a los jugadores
            cout << " " << endl;
            for (int contador = 1; contador <= 4; contador++) //Repetir 4 veces para que cada jugador tenga 4 cartas
            {
                for (int i = 0; i < cantJ; i++)
                {
                    jugadores[i]->SetPool(poolGeneral.Repartir());
                    poolGeneral.Pop();
                }
            }

            cout << "\nEmpezando partida..." << endl;
            cin >> c1;

            condicion = 0;

            //Bucle que se termina hasta que se cumpla la condicion de victoria o se acaben las cartas del pool general
            while (condicion == 0 || poolGeneral.GetPoolGeneral().size() != 0)
            {
                for (int i = 0; i < cantJ; i++)
                {
                     
                    cout << LGREEN << "\nTURNO DEL JUGADOR " << i + 1 << ": " << WHITE << jugadores[i]->GetNombre() << endl;
                    cout << LGREEN << ".  POOL . . . . " << WHITE << endl;
                    jugadores[i]->PrintPool();
                    cout << "" << endl;

                    c = '0';
                    while(c != 'b')
                    {
                        cout << "a) Escoger carta \nb) Saltar turno \n-> ";
                        cin >> c;

                        switch (c)
                        {
                        case 'a': //El jugador decide realizar una jugada con una de sus cartas
                            do
                            {
                                cout << "\nQue numero de carta desea utilizar? \n-> ";
                                cin >> num;

                                if (num < 1 || num > 5)
                                {
                                    cout << "Numero de carta fuera del rango de su pool (1 a 4). " << endl;
                                    cout << " " << endl;
                                }
                            } while (num < 1 || num > 5); //Repetir hasta que ingrese una carta en el rango de su pool

                            num--; //se resta -1 al numero para usarlo como el indice para la lista del pool del jugador
                            carta = jugadores[i]->GetPool().GetElemento(num); //Se extrae la carta en una variable temporal

                            //SI LA CARTA ES UNA PLANTA
                            if (carta->GetTipo() == "Planta")
                            {
                                while (c1 != 'y')
                                {
                                    cout << "\nPULSE 'y' PARA COLOCAR LA PLANTA EN SU JARDIN" << endl;
                                    cin >> c1; 

                                    jugadores[i]->SetGarden(carta); //Se coloca la planta en el jardin del jugador
                                    jugadores[i]->EliminarCartaPool(num); //Se elimina la planta del pool del jugador

                                    cout << " " << endl;
                                    cout << "Wow! Esa planta le da vida a su jardin. " << endl;

                                    cout << "\nJARDIN ACTUALIZADO DEL JUGADOR " << i + 1 << ": " << jugadores[i]->GetNombre() << endl;
                                    jugadores[i]->GetGarden().PrintLista(); //Imprimir el jardin actualizado
                                    cout << " " << endl;
                                }
                                c1 = '0'; //Reinicio de la variable
                            }
                            //SI LA CARTA ES UN HONGO
                            else if (carta->GetTipo() == "Hongo")
                            {
                                Hongo* hongo = dynamic_cast<Hongo*>(carta);  //Se convierte la carta en un objeto tipo hongo para acceder a sus metodos

                                cout << "Que jugador tiene la mala suerte de sufrir el hongo en una de sus plantas?" << endl;

                                for (int j = 0; j < cantJ; j++) //Imprimir los jugadores y su jardin
                                {
                                    if (i != j)
                                    {
                                        cout << " " << endl;
                                        cout << "Jugador " << j + 1 << ": " << jugadores[j]->GetNombre() << endl;
                                        jugadores[j]->GetGarden().PrintLista();
                                    }
                                }

                                do
                                {  //Ingresar el jugador afectado
                                    cout << "\n-> ";
                                    cin >> num2;

                                    if (num2 < 1 || num2 > cantJ)
                                    {
                                        cout << "Jugador fuera de la lista. " << endl;
                                    }

                                } while (num2 < 1 || num2 > cantJ); //Repetir hasta que se ingrese un numero entre la cantidad de jugadores

                                j = num2 - 1; //Restarle -1 al numero para usarlo como indice en el vector de jugadores
                                jugadores[j]->PrintInfo(); //Acceder a la informacion del jugador afectado

                                while (c1 != 'b')
                                {
                                    //Confirmar que se procedera con ese jugador
                                    cout << "\na) Continuar \nb) Regresar \n-> ";
                                    cin >> c1;

                                    switch (c1)
                                    {
                                    case 'a': //El jugador en turno decide continuar
                                        do
                                        { //Ingresar el numero en el jardin del jugador afectado donde se colocara el hongo
                                            cout << "\nINGRESE EL NUMERO DE PLANTA QUE SERA CONTAMINADA: \n-> ";
                                            cin >> num2;

                                            if (num2 < 1 || num2 >(jugadores[j]->GetGarden().Size() + 1))
                                            {
                                                cout << "Numero de planta fuera del rango del jardin del jugador." << endl;
                                                cout << " " << endl;
                                            }

                                        } while (num2 < 1 || num2 >(jugadores[j]->GetGarden().Size() + 1)); //Repetir hasta ingresar un numero entre la cantida de jugadores

                                        num2--; //restar -1 para usarlo como indice para obtener la planta del jardin del jugador afectado
                                        
                                        
                                        p = jugadores[j]->AsignarEfectosPlanta(hongo, num2); //Asignar el efecto de hongo a la planta
                                        planta = dynamic_cast<Planta*>(p); 

                                        //Se actualizan los efectos de la planta en el jardin del jugador
                                        jugadores[j]->EliminarPlantaGarden(num2); 
                                        jugadores[j]->InsertInGarden(p, num2);

                                        //Si el efecto en la planta es mayor a 1
                                        if(planta->GetHongo() > 1)
                                        {
                                            jugadores[j]->EliminarPlantaGarden(num2); //Se elimina la planta del jardin del jugador afectado
                                        }

                                        jugadores[i]->EliminarCartaPool(num); //Se elimina la carta de hongo del pool del jugador

                                        c1 = 'b'; //Reiniciar la opcion para terminar el ciclo while
                                        break;

                                    case 'b': //El jugador cancela su eleccion
                                        break;

                                    default:
                                        cout << "Opcion invalida. " << endl;
                                        break;
                                    }
                                }
                                c1 = '0';
                            }
                            //SI LA CARTA ES UNA FUNGICIDA
                            else if (carta->GetTipo() == "Fungicida")
                            {
                                Fungicida* fungicida = dynamic_cast<Fungicida*>(carta);  //Se convierte la carta en un objeto tipo fungicida para acceder a sus metodos
                                jugadores[i]->PrintInfo();

                                do
                                { //Escoger planta donde se colocara la fungicida
                                    cout << "\nQue planta desea proteger? \n-> ";
                                    cin >> num2;

                                    if (num2 < 1 || num2 >(jugadores[i]->GetGarden().Size() + 1))
                                    {
                                        cout << "Planta fuera del rango de su jardin. " << endl;
                                        cout << " " << endl;
                                    }

                                } while (num2 < 1 || num2 > (jugadores[i]->GetGarden().Size() + 1)); //Repetir hasta que se ingrese un numero en el rango de jugadores

                                cout << " " << endl;
                                p = jugadores[i]->AsignarEfectosPlanta(fungicida, num2); //Se asigna el efecto a la planta escogida

                                //Verificar que la fungicida sea del mismo color que la planta
                                if (fungicida->GetColor() == jugadores[i]->GetGarden().GetElemento(num2)->GetColor())
                                {
                                    //Actualizacion de los efectos de la planta
                                    jugadores[i]->EliminarPlantaGarden(num2);
                                    jugadores[i]->InsertInGarden(p, num2); 

                                    jugadores[i]->EliminarCartaPool(num); //Se elimina la carta utilizada del pool del jugador
                                }
                            }
                            //SI LA CARTA ES DE TRUCO
                            else if (carta->GetTipo() == "Truco")
                            {
                                Truco* truco = dynamic_cast<Truco*>(carta);  //Se convierte la carta en un objeto tipo truco para acceder a sus metodos

                                //LA CARTA DE TRUCO ES DE TIPO TRASPLANTAR
                                if (truco->GetTipoTruco() == "Trasplantar")
                                {
                                    while(c1 != 'a')
                                    {
                                        cout << "\nA que jugador le robara una planta?" << endl;

                                        for (int j = 0; j < cantJ; j++) //Imprimir los jugadores y su jardin 
                                        {
                                            if (i != j)
                                            {
                                                cout << " " << endl;
                                                cout << "Jugador " << j + 1 << ": " << jugadores[j]->GetNombre() << endl;
                                                jugadores[j]->GetGarden().PrintLista();

                                            }
                                        }

                                        do
                                        {  //Ingresar el jugador afectado
                                            cout << "\n-> ";
                                            cin >> num2;

                                            if (num2 < 1 || num2 > cantJ)
                                            {
                                                cout << "Jugador fuera de la lista. " << endl;
                                                cout << " " << endl;
                                            }

                                            if (num2 == i + 1)
                                            {
                                                cout << "No puede elegirse a usted mismo! " << endl;
                                                cout << " " << endl;
                                            }

                                        } while (num2 < 1 || num2 > cantJ || num2 == i + 1); //Repetir hasta que se ingrese un numero entre la cantidad de jugadores

                                        j = num2 - 1; //Restarle -1 al numero para usarlo como indice en el vector de jugadores
                                        cout << LGREEN << "\nJUGADOR ESCOGIDO: " << WHITE << endl;
                                        jugadores[j]->PrintInfo(); //Acceder a la informacion del jugador afectado

                                        while (c1 != 'b')
                                        {
                                            //Confirmar que se procedera con ese jugador
                                            cout << "\na) Continuar \nb) Regresar \n-> ";
                                            cin >> c1;

                                            switch (c1)
                                            {
                                            case 'a': //El jugador en turno decide continuar
                                                do
                                                { //Ingresar el numero en el jardin del jugador afectado donde se colocara el hongo
                                                    cout << "\nINGRESE EL NUMERO DE PLANTA QUE TRASPLANTARA A SU JARDIN: \n-> ";
                                                    cin >> num2;

                                                    if (num2 < 1 || num2 >(jugadores[j]->GetGarden().Size() + 1))
                                                    {
                                                        cout << "Numero de planta fuera del rango del jardin del jugador." << endl;
                                                        cout << " " << endl;
                                                    }

                                                } while (num2 < 1 || num2 >(jugadores[j]->GetGarden().Size() + 1)); //Repetir hasta ingresar un numero entre la cantida de jugadores

                                                num2--; //restar -1 para usarlo como indice para obtener la planta del jardin del jugador afectado
                                                p = jugadores[j]->GetGarden().GetElemento(num2); //declarar la planta que se trasplantara
                                                planta = dynamic_cast<Planta*>(p);  //Se convierte la carta en un objeto tipo planta para acceder a sus metodos

                                                cout << "Se transplantara: ";
                                                planta->PrintInfo();
                                                cout << "\nA su jardin, esta de acuerdo? (y/n) \n-> ";
                                                cin >> c2;

                                                //Confirmacion de trasplante
                                                if (c2 == 'y')
                                                {
                                                    jugadores[i]->SetGarden(planta); //Se agrega la planta al jardin del jugador actual
                                                    jugadores[j]->EliminarPlantaGarden(num2); //Se elimina la planta del jardin del jugador afectado

                                                    jugadores[i]->EliminarCartaPool(num); //Se elimina la carta de trasplantar del pool del jugador

                                                    cout << "\nSe ha trasplantado la planta del jugador enemigo a su jardin!" << endl;
                                                }
                                                c1 = 'b';
                                                break;

                                            case 'b': //El jugador cancela su eleccion
                                                break;

                                            default:
                                                cout << "Opcion invalida. " << endl;
                                                break;
                                            }
                                        }
                                    } 
                                    c1 = '0';
                                }
                                //LA CARTA DE TRUCO ES DE TIPO INTERCAMBIO
                                else if (truco->GetTipoTruco() == "Intercambio")
                                {
                                    while (c1 != 'a')
                                    {
                                        cout << "\nCon que jugador quiere intercambiar su jardin?" << endl;

                                        for (int j = 0; j < cantJ; j++) //Imprimir los jugadores y su jardin 
                                        {
                                            if (i != j)
                                            {
                                                cout << " " << endl;
                                                cout << "Jugador " << j + 1 << ": " << jugadores[j]->GetNombre() << endl;
                                                jugadores[j]->GetGarden().PrintLista();

                                            }
                                        }

                                        do
                                        {  //Ingresar el jugador afectado
                                            cout << "\n-> ";
                                            cin >> num2;

                                            if (num2 < 1 || num2 > cantJ)
                                            {
                                                cout << "Jugador fuera de la lista. " << endl;
                                                cout << "" << endl;
                                            }
                                            if (num2 == i + 1)
                                            {
                                                cout << "No puede escogerse a si mismo! " << endl;
                                                cout << " " << endl;
                                            }

                                        } while (num2 < 1 || num2 > cantJ || num2 == i + 1); //Repetir hasta que se ingrese un numero entre la cantidad de jugadores

                                        j = num2 - 1; //Restarle -1 al numero para usarlo como indice en el vector de jugadores
                                        cout << LGREEN << "JUGADOR ESCOGIDO: " << WHITE << endl;
                                        jugadores[j]->PrintInfo(); //Acceder a la informacion del jugador afectado

                                        while (c1 != 'b')
                                        {
                                            //Confirmar que se procedera con ese jugador
                                            cout << "\na) Continuar \nb) Regresar \n-> ";
                                            cin >> c1;

                                            switch (c1)
                                            {
                                            case 'a': //El jugador en turno decide continuar
                                                //Confirmacion de intercambio
                                                cout << "\nSe intercambiara su jardin con el del jugador " << j + 1 << ", esta de acuerdo? (y/n) \n-> ";
                                                cin >> c2;

                                                if (c2 == 'y')
                                                {
                                                    cout << " " << endl;
                                                    //Obtener una copia temporal de los dos jardines
                                                    g1 = jugadores[i]->GetGarden();
                                                    g2 = jugadores[j]->GetGarden();

                                                    //Asignacion de los jardines contrarios
                                                    jugadores[i]->SetGarden(g2);
                                                    jugadores[j]->SetGarden(g1);

                                                    jugadores[i]->EliminarCartaPool(num); //Se elimina la carta de intercambio del pool del jugador
                                                }
                                                c1 = 'b';
                                                break;

                                            case 'b': //El jugador cancela su eleccion
                                                break;

                                            default:
                                                cout << "Opcion invalida. " << endl;
                                                break;
                                            }
                                        }
                                    }
                                    c1 = '0';
                                }
                            }
                            c = 'b';   
                            break;

                        case 'b': //El jugador salta su turno
                            cout << "El jugador " << i + 1 << " ha saltado su turno. " << endl;
                            cout << " " << endl;
                            break;

                        default:
                            cout << "Opcion no disponible. " << endl;
                            break;
                        }
                    } 

                    //Contador de plantas en el jardin del jugador por color
                    for (int k = 0; k < jugadores[i]->GetGarden().Size(); k++)
                    {
                        if (jugadores[i]->GetGarden().GetElemento(k)->GetColor() == "rojo")
                        {
                            contadorR++;
                        }
                        else if (jugadores[i]->GetGarden().GetElemento(k)->GetColor() == "azul")
                        {
                            contadorAz++;
                        }
                        else
                        {
                            contadorAm++;
                        }
                    }

                    //Condicion para ganar, 3 plantas de diferente color (rojo, amarillo, azul) 
                    if ((contadorR >= 1) && (contadorAz >= 1) && (contadorAm >= 1))
                    {
                        condicion = 1;
                        cout << "El jugador " << i + 1 << " ha plantado 3 plantas de diferente color en su jardin" << endl;
                        cout << "Tenemos un ganador! Felicidades, " << jugadores[i]->GetNombre() << endl;
                        contadorR = 0;
                        contadorAm = 0;
                        contadorAz = 0;
                    }

                    //Verificar que el jugador tenga 4 cartas en su pool
                    while (jugadores[i]->GetPool().Size() < 4)
                    {
                        jugadores[i]->SetPool(poolGeneral.Repartir()); //Repartir carta si no tiene 4
                        poolGeneral.Pop();
                    }

                    //Imprimir la cantidad de cartas en el pool general y la informacion de cada jugador por turno
                    cout << LGREEN << "\nCartas restantes en el pool: " << WHITE << poolGeneral.GetPoolGeneral().size() << endl; 

                    cout << LGREEN << "\nINFORMACION DE JUGADORES: " << WHITE << endl; 
                    for (int k = 0; k < jugadores.size(); k++)
                    {
                        jugadores[k]->PrintInfo(); 
                        cout << " " << endl; 
                    }

                    //Reiniciar el contador de plantas por jardin de jugador en cada turno
                    contadorR = 0;
                    contadorAm = 0;
                    contadorAz = 0;

                    
                }
            }

            if (poolGeneral.GetPoolGeneral().size() == 0)
            {
                cout << " " << endl;
                cout << "Oh no! Se han acabado las cartas del pool general, no se puede continuar con la partida." << endl;
            }

            //LIBERAR MEMORIA ELIMINANDO LOS DATOS DE LA PARTIDA ACTUAL

            //Eliminar cada jugador que participo en la partida
            for (Jugador* jugador : jugadores)
            {
                delete jugador;
            }

            //Eliminar los punteros a los jugadores 
            jugadores.clear(); 
            jugadores.shrink_to_fit(); //Eliminar la memoria reservada para el vector

            poolGeneral.~PoolGeneral(); 
            break;

        case 2:
            break;

        default:
            cout << "Opcion no disponible. " << endl;
        } 
    } while (op != 2);
} 

