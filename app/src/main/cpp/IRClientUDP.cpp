#include "IRClientUDP.h"

#include <iostream>

int IRClientUDP::m_nbClientUDP = 0;

 IRClientUDP::IRClientUDP()
 {
    m_adresseIPServeur = "127.0.0.1";
    m_portServeur = 4000;
    if(m_nbClientUDP == 0)
    {
		#if defined(_WIN32) || defined(_WIN64)
		WSADATA wsaData ;
		int iResult;
		iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
		if(iResult != 0)
		{
			std::cout << "Echec lors de l'initialisation de la DLL Winsock" << std::endl;
		}
		#endif
    }
	m_nbClientUDP++;

}

IRClientUDP::~IRClientUDP()
{
    FermerLaSocket();
}



 bool IRClientUDP::OuvrirLaSocketDeCommunication(std::string adresseIPServeur, unsigned short portServeur)
 {
    m_adresseIPServeur = adresseIPServeur;
    m_portServeur = portServeur;
    m_socketClientUDP = socket ( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
    if ( m_socketClientUDP == -1 )
    {
        std::cout << "Erreur de création de socket." << std::endl;
        return false;
    }

    m_addrServeur.sin_family = AF_INET;
    m_addrServeur.sin_port = htons ( m_portServeur );
    m_addrServeur.sin_addr.s_addr = inet_addr(m_adresseIPServeur.c_str());


    return true;
}

bool IRClientUDP::FermerLaSocket()
{
    #ifdef __unix__
    close(m_socketClientUDP);
    #elif defined(_WIN32) || defined(_WIN64)
    closesocket(m_socketClientUDP);
    #endif

    return true;

}

bool IRClientUDP::EnvoyerUnMessage(std::string message)
{
    int nbCaractEmi;
    nbCaractEmi = sendto ( m_socketClientUDP, message.c_str(), message.length()+1 , 0, (struct sockaddr *) &m_addrServeur, sizeof(m_addrServeur));
    // On vérifie qu'un message a bien été reçu
    if(nbCaractEmi == -1)
    {
        return false;
    }
    return true;
}

bool IRClientUDP::EnvoyerDesOctets(const unsigned char * tableau, int taille)
{
    int nbCaractEmi;
    nbCaractEmi = sendto ( m_socketClientUDP, (const char*)tableau, taille , 0, (struct sockaddr *) &m_addrServeur, sizeof(m_addrServeur));
    // On vérifie qu'un message a bien été reçu
    if(nbCaractEmi == -1)
    {
        return false;
    }
    return true;
}

int IRClientUDP::RecevoirUnMessage(std::string & message, int timeout_us)
{   char msg[1500];
	int nbCaracteresRecus=RecevoirDesOctets((unsigned char*)msg, 1500, timeout_us);
	if(nbCaracteresRecus > 1)
	{   msg[nbCaracteresRecus]=0;
		message = msg;
		return nbCaracteresRecus;
	}
    message = "";
    return -1;
}

int IRClientUDP::RecevoirDesOctets(unsigned char * tableau, int tailleMax, int timeout_us)
{
	fd_set fds;
	int n;
    struct timeval tv;
    FD_ZERO(&fds);
    FD_SET(m_socketClientUDP, &fds);
	tv.tv_sec =  timeout_us/1000000;
	tv.tv_usec = timeout_us%1000000;

    n = select(m_socketClientUDP, &fds, NULL, NULL, &tv);
    if(n==0)
    {
        //std::cout << "Timeout.." << std::endl;
        return 0;
    }
    else if(n==-1)
    {
        //std::cout << "Error.." << std::endl;
        return -1;
    }

    struct sockaddr_in from;
    socklen_t length = sizeof(from);
    int nbCaracteresRecus = recvfrom(m_socketClientUDP, (char *)tableau, tailleMax, 0, (struct sockaddr *)&from, &length);    
    if(nbCaracteresRecus > 1)
    {
        return nbCaracteresRecus;
    }
    return -1;
}