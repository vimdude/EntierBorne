/* -+----1----+----2----+----3----+----4----+----5----+----6----+----7----+- */
/* Abdel Said                                           le 13 septembre 2001 */
/* ========================================================================= */
/*                               correcteur.cpp                              */
/* ========================================================================= */
/*                                                                           */
/* Correcteur de la classe EntierBorne.                                      */
/*                                                                           */
/* ========================================================================= */

#include <iostream.h>
#include <fstream.h>
#include <exception>
#include <stdio.h>
#include <string.h>

#include "EntierBorne.h"
#include "IntervalleEntier.h"

static void rapporter( ofstream &correction, char *message );

// ----------------------------------------------------------------------------
int main( int nombreDArguments, char *arguments[ ] )
// ----------------------------------------------------------------------------
{
	char *nomDuFichierDeCorrection = "correction.txt";
	if ( nombreDArguments == 2 ) {
		nomDuFichierDeCorrection = arguments[ 1 ];
	}
	ofstream correction = ofstream( nomDuFichierDeCorrection, ios::out );
	if ( correction == 0 ) {
		cerr << "Echec de l'ouverture de \"" << nomDuFichierDeCorrection
			<< "\"" << endl;
		return 1;
	}

	char message[ 1024 ];
	double valeur;
	bool continuer = true;
	double noteMax = 0.0;
	double note = 0.0;
	unsigned int numeroDeTest = 0;

 	EntierBorne unite;


	/*
	* test des limites d'un EntierBorne implicite.
	*/
	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( unite.fournirMinimum( ) != 0 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMinimum( ) d'un EntierBorne implicite devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"etre 0.\n" );
			rapporter( correction, message );
		}
	}
	
	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( unite.fournirMaximum( ) != 1 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMaximum( ) d'un EntierBorne implicite devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"etre 1.\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( unite.fournirValeur( ) != 0 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMaximum( ) d'un EntierBorne implicite devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"etre 1.\n" );
			rapporter( correction, message );
		}
	}

	int minimum = 0;
	int maximum = 10;
 	EntierBorne indice( minimum, maximum );

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( indice.fournirMinimum( ) != minimum ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMinimum( ) d'un EntierBorne implicite devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"etre 0.\n" );
			rapporter( correction, message );
		}
	}
	
	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( indice.fournirMaximum( ) != maximum ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMaximum( ) d'un EntierBorne implicite devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"etre 1.\n" );
			rapporter( correction, message );
		}
	}
	
	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( indice.fournirValeur( ) != minimum ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMaximum( ) d'un EntierBorne implicite devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"etre 1.\n" );
			rapporter( correction, message );
		}
	}

	indice.fixerAuMaximum( );
	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( indice.fournirValeur( ) != maximum ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMaximum( ) d'un EntierBorne implicite devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"etre 1.\n" );
			rapporter( correction, message );
		}
	}

	indice.fixerAuMinimum( );
	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( indice.fournirValeur( ) != minimum ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMaximum( ) d'un EntierBorne implicite devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"etre 1.\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		bool exceptionCapturee = false;
		try {
			indice.modifierValeur( maximum + 1 );
		}
		catch( EntierBorne::HorsBornes ) {
			exceptionCapturee = true;
		}
		if ( !exceptionCapturee ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) exception HorsBornes non declenchee dans\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"modifierValeur().\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		bool exceptionCapturee = false;
		try {
			indice.modifierValeur( minimum - 1 );
		}
		catch( EntierBorne::HorsBornes ) {
			exceptionCapturee = true;
		}
		if ( !exceptionCapturee ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) exception HorsBornes non declenchee dans\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"modifierValeur().\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		bool exceptionCapturee = false;
		try {
			indice.modifierValeur( maximum );
		}
		catch( EntierBorne::HorsBornes ) {
			exceptionCapturee = true;
		}
		if ( exceptionCapturee ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) exception HorsBornes declenchee pour valeur = maximum dans\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"modifierValeur().\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		bool exceptionCapturee = false;
		try {
			indice.modifierValeur( minimum );
		}
		catch( EntierBorne::HorsBornes ) {
			exceptionCapturee = true;
		}
		if ( exceptionCapturee ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) exception HorsBornes declenchee pour valeur = minimum dans\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"modifierValeur().\n" );
			rapporter( correction, message );
		}
	}

	IntervalleEntier intervalle( minimum, maximum );
 	EntierBorne repere( intervalle );

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( repere.fournirMinimum( ) != minimum ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMinimum( ) d'un EntierBorne construit sur un\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"IntervalleEntier [0..10] devrait renvoyer 0.\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( repere.fournirMaximum( ) != maximum ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fournirMinimum( ) d'un EntierBorne construit sur un\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"IntervalleEntier [0..10] devrait renvoyer 10.\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		bool exceptionCapturee = false;
		try {
			repere.modifierValeur(( maximum + minimum )/2 );
		}
		catch( EntierBorne::HorsBornes ) {
			exceptionCapturee = true;
		}
		if ( exceptionCapturee ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fixer un EntierBorne au milieur de son IntervalleEntier\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"ne devrait pas declencher d'exception.\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		bool exceptionCapturee = false;
		try {
			repere.modifierValeur( maximum + 1 );
		}
		catch( EntierBorne::HorsBornes ) {
			exceptionCapturee = true;
		}
		if ( !exceptionCapturee ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fixer un EntierBorne au dessus de son maximum\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"devrait declencher l'exception HorsBornes.\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		bool exceptionCapturee = false;
		try {
			repere.modifierValeur( minimum - 1 );
		}
		catch( EntierBorne::HorsBornes ) {
			exceptionCapturee = true;
		}
		if ( !exceptionCapturee ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fixer un EntierBorne au dessous de son minimum\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"devrait declencher l'exception HorsBornes.\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		bool exceptionCapturee = false;
		try {
			repere.modifierValeur( minimum );
		}
		catch( EntierBorne::HorsBornes ) {
			exceptionCapturee = true;
		}
		if ( exceptionCapturee ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fixer un EntierBorne a son minimum ne devrait pas\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"declencher d'exception.\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		bool exceptionCapturee = false;
		try {
			repere.modifierValeur( maximum );
		}
		catch( EntierBorne::HorsBornes ) {
			exceptionCapturee = true;
		}
		if ( exceptionCapturee ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) fixer un EntierBorne a son maximum ne devrait pas\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"declencher d'exception.\n" );
			rapporter( correction, message );
		}
	}

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		bool exceptionCapturee = false;
		try {
			repere++;
		}
		catch( EntierBorne::HorsBornes ) {
			exceptionCapturee = true;
		}
		if ( !exceptionCapturee ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) decrementer un EntierBorne en dessous de son minimum devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"declencher l'exception HorsBornes.\n" );
			rapporter( correction, message );
		}
	}

	int notes[ 10 ];
	EntierBorne index( 0, 10 );
	notes[ 3 ] = 3;

	numeroDeTest++;
	valeur = 10.0;
	noteMax += valeur;
	note -= valeur;
	if ( continuer ) {
		note += valeur;
		if ( notes[ 3 ] != 3 ) {
			note -= valeur;
			continuer = false;
			char *pt = message;
			sprintf( pt,
				"(%u) Un EntierBorne utiliser en indice de tableau devrait\n",
				numeroDeTest );
			sprintf( pt += strlen( pt ),
				"acceder a la cellule correspondant a sa valeur.\n" );
			rapporter( correction, message );
		}
	}

	/* ----------------------------- service --------------------------------- */
	note += noteMax;
	note = note/noteMax;
	sprintf( message, "note obtenue: %6.2lf.\n", note );
	rapporter( correction, message );
	return 0;
}

/* ------------------------------------------------------------------------- */
static void rapporter( ofstream &correction, char *message )
/* ------------------------------------------------------------------------- */
{
	correction << message << flush;
	cout << message << flush;
} 
