//---------------------------------------------------------------------------

#pragma hdrstop

#include "ServeurDonneeDrone.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//pitch:0;roll:0;yaw:0;vgx:0;vgy:0;vgz:0;templ:0;temph:0;tof:0;h:0;bat:0;baro:0.0;time:0;agx:0.00;agy:0.00;agz:0.00;
ServeurDonneeDrone::ServeurDonneeDrone(string pilote,string numeroDrone)
{	OuvrirFichierLog("serveur.log");
	AjoutFichierLog("SERVEUR : Demarrage...");
	serveurUDP.OuvrirLaSocketDEcoute(8890,"0.0.0.0");
	DebuterJSON(pilote,numeroDrone);
}
void ServeurDonneeDrone::AjouterDonneesJSON(string message)
{   int pos=0;
	while(message.find("\n")!=-1) message.erase(message.find("\n"),1);
	while(message.find("\r")!=-1) message.erase(message.find("\r"),1);
	message.insert(0,"{ \"");
	do
	{	pos=message.find(":",pos);
		if(pos>=0)
		{	message.replace(pos,1,"\":\"");
			pos+=2;
		}
	}while(pos>=0);
	pos=0;
	do
	{	pos=message.find(";",pos);
		if(pos>=0 && pos<message.length()-1)
		{	message.replace(pos,1,"\", \"");
		}
		if(pos==message.length()-1) message.replace(pos,1,"\" },");
	}while(pos>=0);
	leJSON+=message;
}
void ServeurDonneeDrone::OuvrirFichierLog(string nomFichier)
{	fichierLog.open(nomFichier.c_str());
}
void ServeurDonneeDrone::AjoutFichierLog(string texte)
{   fichierLog<<texte<<endl;
	cout<<texte<<endl;
}
void ServeurDonneeDrone::FermerFichierLog()
{   fichierLog.close();
}
int ServeurDonneeDrone::RecevoirDonneesDrone(string &msg)
{	int nbOctets = serveurUDP.RecevoirUnMessage(msg,2000000);   //2s
	if(msg!="")cout<<msg<<endl;
	if(nbOctets > 10)
	{   AjoutFichierLog("SERVEUR : message - "+msg);
		AjouterDonneesJSON(msg);
	}
	return nbOctets;
}
void ServeurDonneeDrone::DebuterJSON(string pilote,string numeroDrone)
{	stringstream stimestamp;
	int timestamp = (int)time(NULL);
	stimestamp<<timestamp;
	leJSON="{\"donneesVol\": { \"nom\":\""+pilote+"\",\"numero\":\""+numeroDrone+"\",\"time\":\""+stimestamp.str()+"\",\"etats\": [\n";
}
void ServeurDonneeDrone::CloreJSON()
{   leJSON.replace(leJSON.length()-1,1,"] } }");
	ofstream fichierJson;
	fichierJson.open("drone.json");
	fichierJson << leJSON;
	fichierJson.close();
}
void ServeurDonneeDrone::EnvoyerDonneesBDD(string IPREST,string urlREST)
{   CloreJSON();
	AjoutFichierLog("SERVEUR : Fin...");
	IRClientTCP clientREST;
	clientREST.SeConnecterAUnServeur(IPREST.c_str(),80);
	string requete,reponse;
	stringstream slongeur;
	slongeur<<leJSON.length();
	requete="POST "+urlREST+" HTTP/1.1\r\nHost: "+IPREST+"\r\nConnexion: keep-alive\r\nContent-type: text/plain\r\nContent-Length: "+slongeur.str()+"\r\n\r\n"+leJSON;
	clientREST.Envoyer(requete);
	AjoutFichierLog(requete);
	int n;
	reponseServeurHTTP="";
	do
	{	n=clientREST.Recevoir(reponse);
		if(n>0) {AjoutFichierLog(reponse);reponseServeurHTTP+=reponse;}
	}while(n>0);
	FermerFichierLog();
}