#include "genkidama.h"
#include "Lista.h"
#include <iostream>


using namespace aed3;
using std::cout;
/*un punto es una tupla (x,y,z) donde x seria la coordenada x, y seria la coordenada y, z seria el indice del punto, solo lo uso
a la hora de imprimir por pantalla (seria el numero que sale por pantalla).*/
/*un punto es una tupla (x,y,z) donde y es el punto correspondiente, x seria el punto mas anterior que llega a matar y, z seria el punto mas 
adelante que llega a matar y; hay que destacar que cuando hago la segunda iteracion pierdo la informacion de x en las tuplas, pero no importa porque para ese punto solo me interesan y, z.*/

void genkidama(int cantSoldados,int T, Lista<Punto> lista){
        Lista<Tupla> enemBarridos = Lista<Tupla>(); /*lista de tuplas que voy llenando con los puntos que matan a los anteriores*/
        Lista<Punto>::Iterador iter = lista.CrearIt();  /*este iterador recorre la lista de puntos que me pasaron*/
        Lista<Punto>::Iterador iter2 = lista.CrearIt(); /*este iterador esta parado sobre el punto con el que comparo el resto*/
        Lista<Tupla>::Iterador iterTupla = enemBarridos.CrearIt(); /*este iterador se encarga de agregar y borrar elementos segun sea necesario*/
        Tupla tuplaAux;
        while (iter.HaySiguiente() == true){
            if (iter2.Siguiente().y <= iter.Siguiente().y + T && iter2.Siguiente().x <= iter.Siguiente().x + T){ /*me fijo si el punto en iter2 esta dentro del rectangulo de iter*/
                tuplaAux.x = iter2.Siguiente(); /*x pasa a ser el punto en iter2, que es con el que estaba comparando*/
                tuplaAux.y = iter.Siguiente(); /*por obvias razones y es el punto en iter*/
                tuplaAux.z = iter.Siguiente(); /*por el momento no se nada de los puntos de adelante, solo se que en ese sentido y se mata a si mismo*/
                if (iterTupla.HayAnterior() == true) { /*si la lista de tuplas esta vacia no hay nada que borrar, si ya agregue un nuevo elemento lo borro porque hay uno mas adelante que mata a los de atras*/
                    iterTupla.EliminarAnterior();
                }
                enemBarridos.AgregarAtras(tuplaAux); 
            }
            else{
                tuplaAux.x = iter.Siguiente(); /*aca es cuando iter no mata a nadie de atras, entonces seria como empezar desde el principio pero tengo que actualizar iter2*/
                tuplaAux.y = iter.Siguiente(); /*y ademas agregar la tupla que indica que x se mata a si mismo a la lista de tuplas*/
                tuplaAux.z = iter.Siguiente();
                enemBarridos.AgregarAtras(tuplaAux);
                iter2 = iter;
                iterTupla.Avanzar();
            }
            iter.Avanzar();
        }
        Lista<Tupla>::Iterador iterTupla2 = enemBarridos.CrearItUlt();
        Lista<Tupla>::Iterador iterTupla3 = enemBarridos.CrearItUlt();
        Lista<Tupla> enemBarridos2 = Lista<Tupla>();
        Lista<Tupla>::Iterador iterTupla5 = enemBarridos2.CrearIt();
        while (iterTupla2.HayAnterior() == true){ /*en esta iteracion el proceso es analogo, solo que uso la lista de tuplas y arranco de atras para adelante; ademas en lugar de comparar con la componente x de la tupla, comparo con la coordenada z*/
            if (iterTupla3.Anterior().z.y <= iterTupla2.Anterior().y.y + T && iterTupla3.Anterior().z.x <= iterTupla2.Anterior().y.x + T) {
                tuplaAux.x = iterTupla2.Anterior().x;
                tuplaAux.y = iterTupla2.Anterior().y;
                tuplaAux.z = iterTupla3.Anterior().z;
                if (iterTupla5.HayAnterior() == true) {
                    iterTupla5.EliminarSiguiente();
                }
                enemBarridos2.AgregarAtras(tuplaAux);
            }
            else{
                tuplaAux.x = iterTupla2.Anterior().x;
                tuplaAux.y = iterTupla2.Anterior().y;
                tuplaAux.z = iterTupla2.Anterior().z;
                enemBarridos2.AgregarAtras(tuplaAux);
                iterTupla3 = iterTupla2;
                iterTupla5.Avanzar();
            }
            iterTupla2.Retroceder();
        }

        Lista<Tupla>::Iterador iterTupla4 = enemBarridos2.CrearIt();
        while (iterTupla4.HaySiguiente() == true){
            cout<<iterTupla4.Siguiente().y.z<<" ";


            iterTupla4.Avanzar();
        }




}
