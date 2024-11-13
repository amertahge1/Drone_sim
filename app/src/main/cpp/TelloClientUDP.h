//---------------------------------------------------------------------------

#ifndef TelloClientUDPH
#define TelloClientUDPH
//---------------------------------------------------------------------------
#include "IRClientUDP.h"
#include <sstream>
#include <string>
using namespace std;
class TelloClientUDP
{   private :
		IRClientUDP client;
		string derniereCommande;
	public :
		TelloClientUDP(string IP);
		string DerniereCommande(){return derniereCommande;};
		string EnvoyerCommande(string commande);
		string ModeCommande();
		string Decoller();
		string Atterrir();
		string Monter(int cm);
		string DeplacerXYZ(int x,int y,int z, int vitesse);
		string Descendre(int cm);
		string Gauche(int cm);
		string Droite(int cm);
		string Avant(int cm);
		string Arriere(int cm);
		string TournerHoraire(int deg);
		string TournerTrigo(int deg);
};

#endif
