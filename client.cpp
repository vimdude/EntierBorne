#include "EntierBorne.h"

int main( void )
{
	try {
		EntierBorne indice;
		EntierBorne indice_1( 0, 25 );
		IntervalleEntier intervalle( 0, 25 );
		EntierBorne indice_2( intervalle );
		EntierBorne indice_3( intervalle );
		int notes[ 26 ];
		notes[ indice_2 ] = 75;
		indice_2.modifierValeur( 30 );
		indice_3++;
		++indice_3;
	}
	catch( IntervalleEntier::LimitesIncompatibles erreur ) {
		cout << ereur;
	}
	catch( EntierBorne::HorsBornes erreur ) {
		cout << ereur;
	}
}

