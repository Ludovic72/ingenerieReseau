#ifndef CLIENTDATA_H
#define CLIENTDATA_H
#include <stdbool.h>
#define NOM strlen(client->nom) + 1
struct ClientData {
    char nom[50];
    int prix;
    bool gagner;
};

size_t serializeClientData(struct ClientData* client, char* buffer, size_t bufferSize) {
    // Assurez-vous que la taille du tampon est suffisante
    if (bufferSize < sizeof(int) + NOM + sizeof(bool)) {
        fprintf(stderr, "Erreur : taille du tampon insuffisante pour la sérialisation.\n");
        exit(1);
    }
    
    strcpy(buffer, client->nom);
    memcpy(buffer + NOM, &(client->prix), sizeof(int));
    memcpy(buffer + NOM + sizeof(int), &(client->gagner), sizeof(bool));

    return NOM + sizeof(int) + sizeof(bool);
}


struct ClientData deserializeClientData(char* buffer, size_t bufferSize) {
    struct ClientData client;

    if (bufferSize < sizeof(int) + 1 + sizeof(bool)) {
        fprintf(stderr, "Erreur : taille du tampon insuffisante pour la désérialisation.\n");
        exit(1);
    }

    // Allouez de la mémoire pour le nom
    client.nom = (char*)malloc(strlen(buffer) + 1);
    if (client.nom == NULL) {
        fprintf(stderr, "Erreur : impossible d'allouer de la mémoire pour le nom.\n");
        exit(1);
    }

    // Copiez le nom depuis le tampon
    strcpy(client.nom, buffer);

    // Copiez le prix après le nom
    memcpy(&(client.prix), buffer + strlen(buffer) + 1, sizeof(int));

    // Copiez le booléen après le prix
    memcpy(&(client.gagner), buffer + strlen(buffer) + 1 + sizeof(int), sizeof(bool));

    return client;
}

#endif

