//---------------------------------------------------------------------------

#ifndef ServeurDonneeDroneH
#define ServeurDonneeDroneH
#include <fstream>
#include <iostream>
#include <sstream>
#include "IRServeurUDP.h"
#include "IRClientTCP.h"
using namespace std;
//---------------------------------------------------------------------------
class ServeurDonneeDrone
{   private :
	ofstream fichierLog;
	IRServeurUDP serveurUDP;
	public :
	string leJSON;
	string reponseServeurHTTP;
	ServeurDonneeDrone(string pilote,string numeroDrone);
	void OuvrirFichierLog(string nomFichier);
	void AjoutFichierLog(string texte);

	void FermerFichierLog();

	int RecevoirDonneesDrone(string &msg);

	string CreerJSON(string pilote,string numeroDrone);

	void EnvoyerDonneesBDD(string IPREST,string urlREST);

	void DebuterJSON(string pilote,string numeroDrone);

	void AjouterDonneesJSON(string message);

	void CloreJSON();

};

#endif

/*Qu'en dis tu de ce nouveau format JSON ?
{
"nom":"hagot",
"time":1570456275,
"etats":[
{ "pitch": 0, //Attitude pitch, degree
"roll": 0, //Attitude roll, degree
"yaw": 0, //Attitude yaw, degree
"vgx": 0, //Speed x,
"vgy": 0, //Speed y,
"vgz": 0, //Speed z,
"templ": 20, //Lowest temperature, celcius degree
"temph": 40, //Highest temperature, celcius degree
"tof": 0, //TOF distance, cm
"h": 0, //Height, cm
"bat": 80, //Current battery percentage, %
"baro": 1, //Barometer measurement, cm
"time": 5, //Motors on time,
"agx": 0, //Acceleration x,
"agy": 0, //Acceleration y,
"agz": 0, //Acceleration z,
},
{
....
}
]
"commandes":[
{"nom":"command",
"value":"",
"time_ms":0
}
]
}*/