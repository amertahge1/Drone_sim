#ifndef IRSERVEURUDP_H
#define IRSERVEURUDP_H

#ifdef __unix__
#include <arpa/inet.h>
#include <unistd.h>
#elif _WIN32 || _WIN64
#include <winsock2.h>
//#pragma comment(lib, "Ws2_32.dll")
#endif

#include <string>

class IRServeurUDP
{
    private :
        std::string m_adresseIPDEcoute;
        unsigned short m_portDEcoute;
        int m_socketServeurUDP;
        static int m_nbServeurUDP;
        struct sockaddr_in m_addrServeur;
        struct sockaddr_in from; // Le client

    public :
        IRServeurUDP();
        ~IRServeurUDP();

	    /*!
            \brief Méthode permettant d'ouvrir la socket serveur UDP et l'attacher à une adresse IP et un port.
            \param adresseIPDEcoute l'adresse IP du serveur UDP, 0.0.0.0 pour écouter sur toutes les interfaces réseaux disponibles
            \param portDEcoute le port d'écoute du serveur UDP
	        \return Cette méthode renvoie true si la socket serveur est bien ouverte, false sinon.
	        \sa FermerLaSocket()
	    */
        bool OuvrirLaSocketDEcoute(unsigned short portDEcoute, std::string adresseIPDEcoute = "0.0.0.0");

	    /**
         *   @brief Méthode permettant d'envoyer un message au serveur UDP.
         *   @param message le message à envoyer
	     *   @return Cette méthode renvoie true si le message a été correctement émis, false sinon.
	     *   @sa EnvoyerDesOctets(const char * tableau, int taille)
	     */        
        bool EnvoyerUnMessage(std::string message);
	    /**
         *   @brief Méthode permettant d'envoyer un tableau d'octets au serveur UDP.
         *   @param message le tableau d'octets à envoyer
         *   @param taille la taille du tableau d'octets à envoyer
	     *   @return Cette méthode renvoie true si le message a été correctement émis, false sinon.
	     *   @sa EnvoyerUnMessage(std::string message)
	     */     
        bool EnvoyerDesOctets(const unsigned char * tableau, int taille);
	    /**
         *   @brief Méthode permettant de recevoir un message provenant du serveur UDP.
         *   @param message une référence au message qui contiendra le message à recevoir 
	     *   @return Cette méthode renvoie le nombre d'octets reçus. En cas d'échec, cette méthode renvoie 0 ou une valeur négative.
	     *   @sa RecevoirDesOctets(char * tableau, int tailleMax)
	     */     
        int RecevoirUnMessage(std::string & message,int timeout_us);
	    /**
         *   @brief Méthode permettant de recevoir un tableau d'octets provenant du serveur UDP.
         *   @param tableau le tableau d'octet qui contiendra les données à recevoir
         *   @param tailleMax le nombre d'octets maximum que peut contenir le tableau d'octet
	     *   @return Cette méthode renvoie le nombre d'octets reçus. En cas d'échec, cette méthode renvoie 0 ou une valeur négative.
	     *   @sa RecevoirDesOctets(char * tableau, int tailleMax)
	     */     
        int RecevoirDesOctets(char * tableau, int tailleMax);


        //! Méthode permettant de fermer la socket cliente UDP.
	    /*!
	        \return Cette méthode renvoie true si la socket de communication est bien fermée, false sinon.
	        \sa OuvrirLaSocket(std::string adresseIPServeur, unsigned short portServeur)
	    */
        bool FermerLaSocket();
};

#endif