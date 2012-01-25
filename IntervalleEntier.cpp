/* -+----1----+----2----+----3----+----4----+----5----+----6----+----7----+- */
/* Abdel Said                                      le 16 septembre 2001*/
/* ------------------------------------------------------------------------- */
/*                                IntervalleEntier.cpp                       */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Fichier de fonctions membres de la classe IntervalleEntier.               */
/*                                                                           */
/* ------------------------------------------------------------------------- */

#include <iostream.h>
#include <exception>
#include"IntervalleEntier.h"

char const * const IntervalleEntier::LimitesIncompatibles::message=
                                 "le minimum est superieur au maximum";

/* ------------------------------------------------------------------------- */
/*return l'erreur: "le minimum est superieur au maximum"
/* ------------------------------------------------------------------------- */
ostream & operator << (ostream & sortie,
	const IntervalleEntier::LimitesIncompatibles & erreur )
/* ------------------------------------------------------------------------- */
{
	return sortie << erreur.message;
}
				
/* ------------------------------------------------------------------------- */
/* affiche l'intervalle sous format [minimum, maximum]
/* ------------------------------------------------------------------------- */
ostream & operator << (ostream & sortie,
	const IntervalleEntier & Intervalle )
/* ------------------------------------------------------------------------- */
{
	return sortie << "["<<Intervalle.minimum<<", "
		          <<Intervalle.maximum<<"]";
}

/* ------------------------------------------------------------------------- */
/* construit une intervalle [0,1] . le constructeur par defaut
/* ------------------------------------------------------------------------- */
IntervalleEntier::IntervalleEntier(void)
	:minimum(0), maximum(1)
/* ------------------------------------------------------------------------- */
{
}

/* ------------------------------------------------------------------------- */
/* construit un IntervalleEntier avec les deux limites specifiees.	         */
/* si le nouveau minimum est superieur au maximum courant, declenche         */
/* l'exception LimitesIncompatibles.								         */
/* ------------------------------------------------------------------------- */
IntervalleEntier::IntervalleEntier(int minimum, int maximum)
				throw(LimitesIncompatibles)
:minimum(minimum), maximum(maximum)
/* ------------------------------------------------------------------------- */
{
	if(minimum > maximum)
		throw IntervalleEntier::LimitesIncompatibles();
}

/* ------------------------------------------------------------------------- */
/* Modifie le minimum de l'intervalle. Si le nouveau minimum est	         */
/* superieur au maximum courant, declenche l'exception				         */
/* LimitesIncompatibles.							        				 */
/* ------------------------------------------------------------------------- */
void IntervalleEntier::modifierMinimum(int nouveauMinimum)
		throw(LimitesIncompatibles)
/* ------------------------------------------------------------------------- */
{
	if(nouveauMinimum > maximum)
		throw IntervalleEntier::LimitesIncompatibles();
	minimum = nouveauMinimum;
}

/* ------------------------------------------------------------------------- */
/* Modifie le maximum de l'intervalle. Si le nouveau maximum est	         */
/* inferieur au minimum courant, declenche l'exception				         */
/* LimitesIncompatibles.											         */
/* ------------------------------------------------------------------------- */
void IntervalleEntier::modifierMaximum(int nouveauMaximum)
		throw(LimitesIncompatibles)
/* ------------------------------------------------------------------------- */
{
	if(nouveauMaximum < minimum)
		throw IntervalleEntier::LimitesIncompatibles();
	maximum = nouveauMaximum;
}

/* ------------------------------------------------------------------------- */
/* renvoie le minimum de l'intervalle								         */
/* ------------------------------------------------------------------------- */
int IntervalleEntier::fournirMinimum(void) const
/* ------------------------------------------------------------------------- */
{
	return minimum;
}

/* ------------------------------------------------------------------------- */
/* renvoie le maximum de l'intervalle                                        */
/* ------------------------------------------------------------------------- */
int IntervalleEntier::fournirMaximum(void) const
/* ------------------------------------------------------------------------- */
{
	return maximum;
}

/* ------------------------------------------------------------------------- */
/* renvoie vrai si entier est inclus dans l'intervalle, faux autrement       */
/* ------------------------------------------------------------------------- */
bool IntervalleEntier::inclus(int entier) const
/* ------------------------------------------------------------------------- */
{
	if(entier<maximum || entier>minimum) return true;
	else return false;
}
