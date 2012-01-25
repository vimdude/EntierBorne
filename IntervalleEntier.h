#ifndef INTERVALLE_ENTIER_H
#define INTERVALLE_ENTIER_H

#include <iostream.h>
#include <exception>

/**
* Un IntervalleEntier est defini comme l'espace compris entre deux limites
* enties, le minimum et le maximum
*/
//========================================================================
class IntervalleEntier
{
	private: int minimum;
	private: int maximum;
	
	/**
	* Declenchee lorsque le minimum est superieur au maximum
	*/
	//====================================================================
	public: class LimitesIncompatibles
	//====================================================================
			{ 
				public: static char const * const message;
				/**
				* Insere l'exception dans un stream.
				*/
				//========================================================
				friend ostream & operator << (ostream & sortie,
				const LimitesIncompatibles & erreur );
				//========================================================
			};	
			/**
			* construit un Intervalle unitaire [0,1]
			*/
	//====================================================================
	public: IntervalleEntier(void);
	//====================================================================
	/**
	* construit un IntervalleEntier avec les deux limites specifiees.
	* si le nouveau minimum est superieur au maximum courant, declenche
	* l'exception LimitesIncompatibles.
	*/
	
	//====================================================================
	public: IntervalleEntier(int minimum, int maximum)
				throw(LimitesIncompatibles);
	
	//====================================================================

	/**
	* Modifie le minimum de l'intervalle. Si le nouveau minimum est superieur
	* au maximum courant, declenche l'exception LimitesIncompatibles.
	*/
	//====================================================================
	public: void modifierMinimum(int nouveauMinimum)
				throw(LimitesIncompatibles);
	//====================================================================
	/**
	* Modifie le maximum de l'intervalle. Si le nouveau maximum est inferieur
	* au minimum courant, declenche l'exception LimitesIncompatibles.
	*/
	public: void modifierMaximum(int nouveauMaximum)
				throw(LimitesIncompatibles);
	//====================================================================
	
	/**
	* renvoie le minimum de l'intervalle
	*/
	//====================================================================
	public: int fournirMinimum(void) const;
	//====================================================================
	/**
	* renvoie le maximum de l'intervalle
	*/
	//====================================================================
	public: int fournirMaximum(void) const;
	//====================================================================
	/**
	* renvoie vrai si entier est inclus dans l'intervalle, faux autrement.
	*/
	//====================================================================
	public: bool inclus(int entier) const;
	//====================================================================
	/**
	* affiche l'intervalle sous le format [<minimum>-<maximum>].
	*/
	//====================================================================
	friend ostream & operator <<(ostream & sortie,
		const IntervalleEntier & intervalle);
	//====================================================================
};

#endif/*INTERVALLE_ENTIER_H*/