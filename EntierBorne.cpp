/* -+----1----+----2----+----3----+----4----+----5----+----6----+----7----+- */
/* Abdel Said                                      le 16 septembre 2001*/
/* ------------------------------------------------------------------------- */
/*                                EntierBorne.cpp                            */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Fichier de fonctions membres de la classe EntierBorne.                    */
/*                                                                           */
/* ------------------------------------------------------------------------- */

#include <iostream.h>
#include <exception>
#include"IntervalleEntier.h"
#include"EntierBorne.h"


char const * const EntierBorne::HorsBornes::message=
										"la valeur n'est pas un Entier Borne";

/*---------------------------------------------------------------------------*/
/*return l'erreur: "la valeur n'est pas un Entier Borne"
/*---------------------------------------------------------------------------*/
ostream & operator << (ostream & sortie,
					   const EntierBorne::HorsBornes & erreur )
/*---------------------------------------------------------------------------*/
{
	return sortie << erreur.message;
}

/*---------------------------------------------------------------------------*/
/* return la valeur de borne
/*---------------------------------------------------------------------------*/
ostream &operator << ( ostream & sortie,
		const EntierBorne & borne )
/*---------------------------------------------------------------------------*/
{
	return sortie << borne.valeur;
}

/*---------------------------------------------------------------------------*/
/* le constructeur par defaut
/*---------------------------------------------------------------------------*/
EntierBorne::EntierBorne(void)
/*---------------------------------------------------------------------------*/
{
	intervalle=	new IntervalleEntier(0,1);
	this->suisProprietaireDeLIntervalle = true;
	valeur = intervalle->fournirMinimum();
}
/*---------------------------------------------------------------------------*/
/* construit un entier et un IntervalleEntier avec les deux limites. 
/* si il n'est pas un Entier Borne, declenche l'exception HorsBornes.
/*---------------------------------------------------------------------------*/
EntierBorne::EntierBorne(int minimum, int maximum)
				throw(IntervalleEntier::LimitesIncompatibles)
/*---------------------------------------------------------------------------*/
{
	if(minimum> maximum)
			throw IntervalleEntier::LimitesIncompatibles();
	intervalle = new IntervalleEntier(minimum,maximum);
	valeur = minimum;
}

/*---------------------------------------------------------------------------*/
/* construit une nouvelle intervalle. si l'intervalle n'est pas valide, 
/* declenche l'exception LimitesIncompatibles.
/*---------------------------------------------------------------------------*/
EntierBorne::EntierBorne( IntervalleEntier & intervalle )
/*---------------------------------------------------------------------------*/
{

	if(intervalle.fournirMinimum() > intervalle.fournirMaximum())
		throw IntervalleEntier::LimitesIncompatibles();

	EntierBorne::intervalle = new IntervalleEntier(intervalle.fournirMinimum(),
												intervalle.fournirMaximum());
	valeur = intervalle.fournirMinimum();
	this->suisProprietaireDeLIntervalle = false;
}

/*---------------------------------------------------------------------------*/
/* le deconstructeur
/*---------------------------------------------------------------------------*/
EntierBorne::~EntierBorne(void)
/*---------------------------------------------------------------------------*/
{
	if( this->suisProprietaireDeLIntervalle )
		delete intervalle;
}

/*---------------------------------------------------------------------------*/
/* construit une nouvelle valeur. si elle n'est pas un Entier Borne, 
/* declenche l'exception HorsBornes.
/*---------------------------------------------------------------------------*/
void EntierBorne::modifierValeur(int NouvelleValeur)
		throw(EntierBorne::HorsBornes)
/*---------------------------------------------------------------------------*/
{
	if(NouvelleValeur > intervalle->fournirMaximum() 
		|| NouvelleValeur < intervalle->fournirMinimum())
				throw EntierBorne::HorsBornes();
	valeur = NouvelleValeur;
}

/*---------------------------------------------------------------------------*/
/* fournir la valeur de minimum
/*---------------------------------------------------------------------------*/
int EntierBorne::fournirMinimum()
/*---------------------------------------------------------------------------*/
{
	return intervalle->fournirMinimum();
}

/*---------------------------------------------------------------------------*/
/* fournir la valeur de maximum
/*---------------------------------------------------------------------------*/
int EntierBorne::fournirMaximum()
/*---------------------------------------------------------------------------*/
{
	return intervalle->fournirMaximum();
}

/*---------------------------------------------------------------------------*/
/* fournir la valeur
/*---------------------------------------------------------------------------*/
int EntierBorne::fournirValeur( )
/*---------------------------------------------------------------------------*/
{
	return valeur;
}

/*---------------------------------------------------------------------------*/
/* fixer la valeur au maximum
/*---------------------------------------------------------------------------*/
void EntierBorne::fixerAuMaximum( )
/*---------------------------------------------------------------------------*/
{
	valeur = intervalle->fournirMaximum();
}

/*---------------------------------------------------------------------------*/
/* fixer la valeur au minimum
/*---------------------------------------------------------------------------*/
void EntierBorne::fixerAuMinimum( )
/*---------------------------------------------------------------------------*/
{
	valeur = intervalle->fournirMinimum();
}

/*---------------------------------------------------------------------------*/
/* operateur de converteur de type
/*---------------------------------------------------------------------------*/
EntierBorne::operator int( void )
/*---------------------------------------------------------------------------*/
{
	return valeur;
}

/*---------------------------------------------------------------------------*/
/* operateur de preincrimentation d'indice
/*---------------------------------------------------------------------------*/
EntierBorne & EntierBorne::operator ++ ( void )
	throw ( HorsBornes )
/*---------------------------------------------------------------------------*/
{
	if(valeur>=intervalle->fournirMaximum())
		throw HorsBornes();
	valeur++;
	return *this;
}

/*---------------------------------------------------------------------------*/
/* operateur de portincrimentation d'indice
/*---------------------------------------------------------------------------*/
EntierBorne & EntierBorne::operator ++ ( int )
	throw ( HorsBornes )
/*---------------------------------------------------------------------------*/
{
	if(valeur>=intervalle->fournirMaximum())
		throw HorsBornes();
	valeur++;
	return *this;
}
