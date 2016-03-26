
#ifndef AED2_TIPOSBASICOS_H_INCLUDED
#define AED2_TIPOSBASICOS_H_INCLUDED



namespace aed3{
    struct Punto{
    int x;
    int y;
    int z;

    bool operator == (const Punto& a) const{
          return (a.x==this->x && a.y==this->y && a.z==this->z);
        }
        bool operator != (const Punto a) const {
          return (a.x!=this->x || a.y!=this->y || a.z!=this->z);
        }
    };
    struct Tupla{
    Punto x;
    Punto y;
    Punto z;
    bool operator == (const Tupla& a) const{
        return (a.x==this->x && a.y==this->y && a.z==this->z);
        }
    bool operator != (const Tupla a) const {
          return (a.x!=this->x || a.y!=this->y || a.z!=this->z);
        }
    };



};


#endif //AED2_TIPOSBASICOS_H_INCLUDED
