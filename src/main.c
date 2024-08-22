/*
 * @file main.c
 * @brief Main file for the project
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "message.h"

int main(int argc, char *argv[])
{
    Message *emergency_msg;

    emergency_msg = create_message("emergencia", "Usuario1", "Usuario2", "español", "Se acerca el deadline del lab1", FLAG_URGENT | FLAG_READ, 0, 0);

    // Debug prints
    printf("Tipo: %s\n", emergency_msg->type);
    printf("Tamaño: %d\n", emergency_msg->size);
    printf("ID del remitente: %s\n", emergency_msg->sender_id);
    printf("ID del receptor: %s\n", emergency_msg->receiver_id);
    printf("Idioma: %s\n", emergency_msg->language);
    printf("Mensaje a enviar: %s\n", emergency_msg->message);

    if (emergency_msg->flags & FLAG_URGENT) {
        printf("Este mensaje es urgente.\n");
    }

    if (emergency_msg->flags & FLAG_READ) {
        printf("This message is read.\n");
    }

    send_message(emergency_msg);

    receive_message(emergency_msg);

    // Free memory
    free(emergency_msg->sender_id);
    free(emergency_msg->receiver_id);
    free(emergency_msg->language);
    free(emergency_msg->message);
    free(emergency_msg);

    Message *location_message;
    location_message = create_message("location", "Lujan", "David", "ingles", "Sending my location", FLAG_URGENT | FLAG_READ, 12, 26);

    send_message(location_message);
    receive_message(location_message);

    // Free memory
    free(location_message->sender_id);
    free(location_message->receiver_id);
    free(location_message->language);
    free(location_message->message);
    free(location_message);

    return 0;
}

