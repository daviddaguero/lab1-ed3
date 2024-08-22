#pragma once

#include "message.h"

/**
 * handle_emergency
 * 
 * @brief This function simulates handling an emergency message in a zombie apocalypse context.
 * It performs the following actions:
 * 
 * 1. Displays the received emergency message.
 * 2. Simulates an emergency alert with a printed message.
 * 3. Simulates a perimeter check for zombie activity with a time delay.
 * 4. Activates automatic defenses, such as turrets and electrified barriers.
 * 5. Mobilizes an emergency response team to handle the situation.
 * 6. Sends an automatic response indicating that emergency measures are in progress.
 * 
 * @param msg A pointer to the Message structure containing the emergency details.
 */
void handle_emergency(const Message *msg);

/**
 * handle_location
 * 
 * @brief This function simulates handling a location message in a zombie apocalypse context.
 * It performs the following actions:
 * 
 * 1. Displays the received location message.
 * 2. Extracts the coordinates (latitude and longitude) from the message and simulates data extraction with a delay.
 * 3. Simulates scanning the area for nearby threats or resources with a delay.
 * 4. Provides information about any detected threats or available resources.
 * 5. Sends an acknowledgment or response indicating that the location has been received and instructions to proceed.
 * 
 * @param msg A pointer to the Message structure containing the location details.
 */
void handle_location(const Message *msg);

/**
 * handle_message
 * 
 * @brief This function handles a message by calling a specified handler function.
 * It passes the given message to the handler function, which processes the message based on its type.
 * 
 * @param msg A pointer to the Message structure that needs to be handled.
 * @param handler A function pointer to the handler function that processes the message.
 * 
 * The handler function should have the following signature:
 * void handler(const Message *msg);
 * 
 * The appropriate handler function can be selected based on the message type (e.g., handle_emergency, handle_location).
 */
void handle_message(const Message *msg, void (*handler)(const Message *));

