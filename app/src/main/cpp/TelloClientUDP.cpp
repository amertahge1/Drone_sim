//---------------------------------------------------------------------------

#pragma hdrstop

#include "TelloClientUDP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TelloClientUDP::TelloClientUDP(string IP)
{   //client.OuvrirLaSocketDeCommunication("192.168.10.1",8889);
	//client.OuvrirLaSocketDeCommunication("127.0.0.1",8889);
	client.OuvrirLaSocketDeCommunication(IP.c_str(),8889);
	ModeCommande();
}
string TelloClientUDP::EnvoyerCommande(string commande)
{   string msg="";
	client.EnvoyerUnMessage(commande);
	int n=client.RecevoirUnMessage(msg,200000);
	if(n==0) return "-";
	return msg;
}
string TelloClientUDP::ModeCommande()
{   derniereCommande="command";
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::Decoller()
{   derniereCommande="takeoff";
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::Atterrir()
{   derniereCommande="land";
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::Monter(int cm)
{   stringstream sst; sst<<cm;
	derniereCommande="up "+sst.str();
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::Descendre(int cm)
{	stringstream sst; sst<<cm;
	derniereCommande="down "+sst.str();
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::Gauche(int cm)
{   stringstream sst; sst<<cm;
	derniereCommande="left "+sst.str();
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::Droite(int cm)
{	stringstream sst; sst<<cm;
	derniereCommande="right "+sst.str();
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::Avant(int cm)
{	stringstream sst; sst<<cm;
	derniereCommande="forward "+sst.str();
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::Arriere(int cm)
{	stringstream sst; sst<<cm;
	derniereCommande="back "+sst.str();
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::TournerHoraire(int deg)
{	stringstream sst; sst<<deg;
	derniereCommande="cw "+sst.str();
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::TournerTrigo(int deg)
{	stringstream sst; sst<<deg;
	derniereCommande="ccw "+sst.str();
	return EnvoyerCommande(derniereCommande);
}
string TelloClientUDP::DeplacerXYZ(int x,int y,int z, int vitesse)
{   stringstream sst; sst<<x<<" "<<y<<" "<<z<<" "<<vitesse;
	derniereCommande="go "+sst.str();
	return EnvoyerCommande(derniereCommande);
}



