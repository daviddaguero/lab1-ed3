#include "message.h"
#include "handlers.h"
#include <stdlib.h>
#include <string.h>

Message* create_message(const char *type, const char *sender, const char *receiver, const char *language, const char *msg, unsigned int flags, int latitude, int longitude) {
    Message *message = (Message *)malloc(sizeof(Message));

    strncpy(message->type, type, MAX_TYPE_LENGTH);

    int sender_id_size = strlen(sender);
    message->sender_id = (char *)malloc(sender_id_size + 1);
    strncpy(message->sender_id, sender, sender_id_size + 1);

    int receiver_id_size = strlen(receiver);
    message->receiver_id = (char *)malloc(receiver_id_size + 1);
    strncpy(message->receiver_id, receiver, receiver_id_size + 1);

    int language_size = strlen(language);
    message->language = (char *)malloc(language_size + 1);
    strncpy(message->language, language, language_size + 1);

    message->size = strlen(msg);
    message->message = (char *)malloc(message->size + 1);
    strncpy(message->message, msg, message->size + 1);

    message->flags = flags;

    if(!strcmp(type, "location")) {
        message->longitude = longitude;
        message->latitude = latitude;
    }

    return message;
}

void send_message(const Message *msg) {
    printf("Sending message...\n");
    printf("Type: %s\n", msg->type);
    printf("Message's size: %d\n", msg->size);
    printf("Sender's ID: %s\n", msg->sender_id);
    printf("Receiver's id: %s\n", msg->receiver_id);
    printf("Language: %s\n", msg->language);
    printf("Message: %s\n", msg->message);
    
    if (msg->flags & FLAG_URGENT) { 
        printf("The message to be sent is urgent.\n");
    }
    if (msg->flags & FLAG_CONFIDENTIAL) {
        printf("The message to be sent is confidential.\n");
    } 

    printf("Menssage sent succesfully.\n");
}

void receive_message(const Message *msg) {
    printf("Message received:\n");

    printf("Type: %s\n", msg->type);
    printf("Message's size: %d\n", msg->size);
    printf("Sender's ID: %s\n", msg->sender_id);
    printf("Receiver's id: %s\n", msg->receiver_id);
    printf("Language: %s\n", msg->language);
    printf("Message: %s\n", msg->message);
    
    if (msg->flags & FLAG_URGENT) {
        printf("The message received is urgent.\n");
    }
    if (msg->flags & FLAG_CONFIDENTIAL) {
        printf("The message received is confidential.\n");
    } 

    if (strcmp(msg->type, "emergency") == 0) {
        handle_message(msg, handle_emergency);
    } else if (strcmp(msg->type, "location") == 0) {
        handle_message(msg, handle_location);
    } else {
        printf("Unknown message type: %s\n", msg->type);
    }
}

