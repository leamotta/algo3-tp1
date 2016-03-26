#include "genkidama.h"
#include "Lista.h"
#include <iostream>


using namespace aed3;
using std::cout;


void genkidama(int cantSoldados,int T, Lista<Punto> lista){
        Lista<Tupla> enemBarridos = Lista<Tupla>();
        Lista<Punto>::Iterador iter = lista.CrearIt();
        Lista<Punto>::Iterador iter2 = lista.CrearIt();
        Lista<Tupla>::Iterador iterTupla = enemBarridos.CrearIt();
        Tupla tuplaAux;
        while (iter.HaySiguiente() == true){
            if (iter2.Siguiente().y <= iter.Siguiente().y + T && iter2.Siguiente().x <= iter.Siguiente().x + T){
                tuplaAux.x = iter2.Siguiente();
                tuplaAux.y = iter.Siguiente();
                tuplaAux.z = iter.Siguiente();
                if (iterTupla.HayAnterior() == true) {
                    iterTupla.EliminarAnterior();
                }
                enemBarridos.AgregarAtras(tuplaAux);
            }
            else{
                tuplaAux.x = iter.Siguiente();
                tuplaAux.y = iter.Siguiente();
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
        while (iterTupla2.HayAnterior() == true){
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
