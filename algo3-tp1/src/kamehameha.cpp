#include "kamehameha.h"
using namespace std;

int KAMEHAMEHAS_OPTIMOS = numeric_limits<int>::max();
int KAMEHAMEHA_NUMERO = 0;
int ENEMIGOS_VIVOS;
vector<Enemigo> enemigos;
vector<Enemigo> enemigosSolucion;


void resolverKamehameha(vector<Enemigo> ene){
	enemigos = ene;
	ENEMIGOS_VIVOS = ene.size();
	resolverKamehamehaAux();
    printf("%d\n", KAMEHAMEHAS_OPTIMOS);
    vector<string> enemigosEnLinea(KAMEHAMEHAS_OPTIMOS);
    vector<int> cantEnemigosEnLinea(KAMEHAMEHAS_OPTIMOS);
    for(vector<Enemigo>::iterator it = enemigosSolucion.begin(); it != enemigosSolucion.end(); it++){
        int i = it->Kamehameha() -1;
        enemigosEnLinea[i].append(NumberToString(it->Numero())+' ');//todos los enemigos que mate con el kamehameha i
        cantEnemigosEnLinea[i] ++;//cantidad que mate con el kamehameha i
    }
    for(int i=0; i < (int)enemigosEnLinea.size(); i++){
        printf("%d %s\n",cantEnemigosEnLinea[i],enemigosEnLinea[i].c_str());
    }
}

void resolverKamehamehaAux(){
    if(ENEMIGOS_VIVOS == 0){
    	KAMEHAMEHAS_OPTIMOS = KAMEHAMEHA_NUMERO;//solucion optima actual
        enemigosSolucion.clear();
        enemigosSolucion = enemigos;
    }
    else if(ENEMIGOS_VIVOS == 1){
        if(KAMEHAMEHA_NUMERO + 1 < KAMEHAMEHAS_OPTIMOS){//Poda: no sigo probando con soluciones que como mejor caso son iguales a la que ya tengo
            for(vector<Enemigo>::iterator it = enemigos.begin(); it != enemigos.end(); it++){
                if(!it->Muerto()){
                    ENEMIGOS_VIVOS -= matar(&(*it));
                    resolverKamehamehaAux();
                    ENEMIGOS_VIVOS += revivir(&(*it));
                }
            }
        }
    }
    else{
    	vector<Enemigo>::iterator itAux = enemigos.end();
    	itAux--;
        for(vector<Enemigo>::iterator it = enemigos.begin(); it != itAux; it++){//O(N)
            if(!it->Muerto()){//Poda: no es conveniente matar muertos
            	vector<Enemigo>::iterator itAux2 = it;
    		itAux2++;
                for(vector<Enemigo>::iterator it2 = itAux2; it2 != enemigos.end(); it2++){//O(N)
                    if(!it2->Muerto()){ //Poda: no es conveniente matar muertos
				if(KAMEHAMEHA_NUMERO + 1 < KAMEHAMEHAS_OPTIMOS){//no sigo probando con soluciones que como mejor caso son iguales a la que ya tengo
					ENEMIGOS_VIVOS -= matar(&(*it),&(*it2));
					resolverKamehamehaAux();
					ENEMIGOS_VIVOS += revivir(&(*it),&(*it2));
				}
                        }
                  }
                    
                
            }
        }
    }
}

/*
 * Mata todos los enemigos en la recta entre a y b
 */
int matar(Enemigo* a, Enemigo* b){
	KAMEHAMEHA_NUMERO++;
    int matados = 0;
    a->Matar();
    a->AsignarKamehameha(KAMEHAMEHA_NUMERO);
    b->Matar();
    b->AsignarKamehameha(KAMEHAMEHA_NUMERO);
    matados +=2;
    double pendienteAB = pendiente(*a,*b);
    for(vector<Enemigo>::iterator it = enemigos.begin(); it != enemigos.end(); ++it){//Recorro todos (O(n))
        if(!it->Muerto() && !(it->operator ==(*a)) && !(it->operator ==(*b))){//Si esta vivo y no es uno de los que ya mate...
            if(pendienteAB == pendiente(*a,*it)){//Chequeo si esta en la misma recta
                it->Matar();
                it->AsignarKamehameha(KAMEHAMEHA_NUMERO);
                matados++;
            }
        }
    }
    return matados;
}


/*
 * Mato sin importarme la recta ya que solo me queda un enemigo
 */
int matar(Enemigo* a){
	KAMEHAMEHA_NUMERO++;
    a->Matar();
    a->AsignarKamehameha(KAMEHAMEHA_NUMERO);
    return 1;
}

/*
 * Revive todos los enemigos en la recta entre a y b
 */
int revivir(Enemigo* a, Enemigo* b){
    KAMEHAMEHA_NUMERO--;
    int revividos = 0;
    a->Revivir();
    b->Revivir();
    revividos +=2;
    double pendienteAB = pendiente(*a,*b);
    for(vector<Enemigo>::iterator it = enemigos.begin(); it != enemigos.end(); ++it){//Recorro todos (O(n))
        if(it->Kamehameha() == a->Kamehameha() && !(it->operator ==(*a)) && !(it->operator ==(*b))){//Si tenian el mismo numero de kamehameha y no es uno de los que ya revivi...
            if(pendienteAB == pendiente(*a,*it)){//Chequeo si esta en la misma recta
                it->Revivir();
                revividos++;
            }
        }
    }
    return revividos;
}

/*
 * Revivo sin importarme la recta ya que solo me queda un enemigo
 */
int revivir(Enemigo* a){
    KAMEHAMEHA_NUMERO--;
    a->Revivir();
    return 1;
}

double pendiente(Enemigo a, Enemigo b){
    int x = a.X() - b.X();
    int y = a.Y() - b.Y();
    if(x == 0){//para evitar division por 0
        return numeric_limits<int>::max();
    }
    else{
        return double(y)/x;
    }
}
