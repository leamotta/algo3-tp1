#ifndef ENEMIGO_H_
#define ENEMIGO_H_

class Enemigo{

		private:
			int numero;
			int x;
			int y;
			bool muerto;
			int kamehameha;

		public:

			Enemigo(int posX, int posY, int numeroEnemigo);

			~Enemigo();

			int X();

			int Y();

			int Kamehameha();

			int Numero();

			bool Muerto();

			void Matar();

			void Revivir();

			void AsignarKamehameha(int kamehameha);

			bool operator=(const Enemigo&) const;

			bool operator==(const Enemigo&) const;
	};




#endif /* ENEMIGO_H_ */
