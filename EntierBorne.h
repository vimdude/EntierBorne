/* -+----1----+----2----+----3----+----4----+----5----+----6----+----7----+- */
/* Abdel Said                                      le 16 septembre 2001*/
/* ------------------------------------------------------------------------- */
/*                                EntierBorne.cpp                            */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Fichier de fonctions membres de la classe EntierBorne.                    */
/*                                                                           */
/* ------------------------------------------------------------------------- */

#ifndef ENTIER_BORNE
#define ENTIER_BORNE

#include <iostream>
#include "IntervalleEntier.h"


/* ------------------------------------------------------------------------- */
/* Un EntierBorne est un entier confine entre deux limites,					 */
/* son minimum, accessible, et son maximum, inaccessible.					 */
/* Ainsi un EntierBorne de minimum 0 et de maximum 10 peut prendre toutes	 */
/* les valeurs entre 0 et 9.												 */
/* ------------------------------------------------------------------------- */
class EntierBorne
/* ------------------------------------------------------------------------- */
{
	private: IntervalleEntier *intervalle;
	private: int valeur;
	private: bool suisProprietaireDeLIntervalle;

	//------------------------------------------------------
	// declenche lorsque valeur n'est pas un entier borne
	//------------------------------------------------------
	public: class HorsBornes
	//------------------------------------------------------
	{
		public: static const char * const message;
		friend ostream & operator << ( ostream & sortie,
			const HorsBornes & exception );
	};

	//------------------------------------------------------
	// le constructeur par defaut
	//------------------------------------------------------
	public: EntierBorne( void );
	
	//------------------------------------------------------
	// le deconstructeur
	//------------------------------------------------------
	public: ~EntierBorne( void );

	//------------------------------------------------------
	// le constructeur avec des arguments min et max
	// si min et superieur au max une exception va declencher
	//------------------------------------------------------
	public: EntierBorne( int minimum, int maximum )
		throw( IntervalleEntier::LimitesIncompatibles );

	//------------------------------------------------------
	// le constructeur avec un argument intervalle
	//------------------------------------------------------
	public: EntierBorne( IntervalleEntier & intervalle );
	
	//------------------------------------------------------
	// modifier la valeur d'entier borne
	//------------------------------------------------------
	public: void modifierValeur( int nouvelleValeur )
		throw( HorsBornes );

	//------------------------------------------------------
	// fournir minimum
	//------------------------------------------------------
	public: int fournirMinimum( );

	//------------------------------------------------------
	//  maximum
	//------------------------------------------------------
	public: int fournirMaximum( );
	
	//------------------------------------------------------
	// obtenir minimum
	//------------------------------------------------------
	public:	int fournirValeur( );
	public:	void fixerAuMaximum( );
	public:	void fixerAuMinimum( );
	public: operator int( void );
	public: EntierBorne & operator ++ ( void )
		throw ( HorsBornes );
	public: EntierBorne & operator ++ ( int )
		throw ( HorsBornes );
	friend ostream &operator << ( ostream & sortie,
		const EntierBorne & borne );
};

#endif
//ENTIER_BORNE
