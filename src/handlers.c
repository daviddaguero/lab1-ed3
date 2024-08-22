#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "message.h"

void handle_emergency(const Message *msg) {
    // Display the received emergency message
    printf("Handling emergency message: %s\n", msg->message);

    // Simulate an emergency alert
    printf("🔊 ALERT: ZOMBIE EMERGENCY DETECTED!\n");
    
    // Simulate perimeter check
    printf("🚨 Checking the perimeter for zombie activity...\n");
    // Simulate time for the check
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);  // Pause for 1 second to simulate real-time
    }
    printf("\n✅ Perimeter secure, no zombie activity detected.\n");

    // Simulate activation of defenses
    printf("🛡️ Activating automatic defenses: turrets and electrified barriers.\n");

    // Simulate mobilization of a response team
    printf("👥 Mobilizing emergency response team...\n");
    printf("🧟 Team ready to neutralize any zombie threat.\n");

    // Simulate sending an automatic response
    printf("💬 Sending response: 'Message received, emergency measures in progress.'\n");
}

void handle_location(const Message *msg) {
    // Display the received location message
    printf("Handling location message: %s\n", msg->message);

     // Extract the coordinates from the message
    double latitude = msg->latitude, longitude = msg->longitude;
   
    printf("📍 Extracting coordinates from the message...\n");
    // Simulate time for data extraction
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);  // Pause for 1 second to simulate real-time processing
    }
    printf("\n✅ Coordinates extracted: [Lat: %.4f, Long: %.4f].\n", latitude, longitude);

    // Simulate checking for nearby threats or resources
    printf("🔍 Scanning area for threats or resources...\n");
    // Simulate time for scanning
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n⚠️ No immediate threats detected. Resources located: Safe house nearby.\n");

    // Simulate sending an acknowledgement or response
    printf("💬 Sending acknowledgement: 'Location received. Proceed to the safe house.'\n");
}

void handle_message(const Message *msg, void (*handler)(const Message *)) {
    handler(msg);
}

