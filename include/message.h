#pragma once

#define MAX_TYPE_LENGTH 30
#define FLAG_URGENT 0x01   // 0000 0001
#define FLAG_READ   0x02   // 0000 0010

#include <stdio.h>

typedef struct {
    char type[MAX_TYPE_LENGTH];       // Tipo de mensaje ("emergency" o "location")
    int size;                         // Message size
    char *sender_id;                  // Sender's username
    char *receiver_id;                // Receiver's username
    char *language;                   // Message's language
    char *message;                    // The message to be send
    unsigned int flags;               // The flags for the message, using bitwise operators to handle control bits (read, urgent, etc)
    int latitude;                     // Latitude (only for location messages)
    int longitude;                    // Longitude (only for location messages)
} Message;

/**
 * create_message
 * 
 * @brief This function creates a new message structure, dynamically allocates memory for the message fields, and sets the provided values.
 * 
 * @param type The type of the message (e.g., "emergency", "location", request of supplies, etc).
 * @param sender The ID of the user sending the message.
 * @param receiver The ID of the user receiving the message.
 * @param language The language of the message (e.g., "español").
 * @param msg The actual content of the message.
 * @param flags The flags for the message, using bitwise operators to handle control bits.
 * @param latitude The latitude of the sender's location (only relevant if type is "location").
 * @param longitude The longitude of the sender's location (only relevant if type is "location").
 * @return A pointer to the newly created Message structure, or NULL if memory allocation fails.
 */
Message* create_message(const char *type, const char *sender, const char *receiver, const char *language, const char *msg, unsigned int flags, int longitude, int latitude);

/**
 * send_message
 * 
 * This function simulates the sending of a message by printing its details to the console.
 * 
 * @param msg A pointer to the Message structure that contains the message details to be sent.
 */
void send_message(const Message *msg);

