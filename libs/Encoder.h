/// @file Encoder.h
/**
* 
* @author: Cesar Angeles
* @date:  09/2021
* @brief Module API dedicated to create, manage and encode text messages.
* Mainly used to create text frames that have to be encoded for encryption, network connections, etc. 
*/

#ifndef Encoder_H
#define Encoder_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Give an error code IDE to test for encoding success or failure
 */ 
typedef enum{
    FALSE, ///< Error code when an Encoder process was not completed
    TRUE ///< Error code when an Encoder process was successful.
}ERROR;
/**
 * Stores a given text message to be encoded.
 * It stores the memory a given message occupies.
*/

struct _frame{
    char *content;
    size_t length;
};


typedef struct _frame* Message;
/**
 * Constructs a new message container with a given string. 
 * If message = NULL - then an empty container is returned.
 * 
 * @param[in] message to be stored within the container.  
 * @param[out] Message created container reference.
 */ 
Message newMessageContainer(char* message);
/**
 * Sets a particular string message to a Message container module.
 * 
 * @param[in] frame objective to modify. 
 * @param[in] string to be set
 * 
 * @returns ERROR code. TRUE if was successfully set. FALSE otherwise.
 */ 
ERROR setMessage(Message frame, char* string);
/**
 * Returns a given char* reference to the string within a frame object. 
 * 
 * @param[in] frame object to be analised.
 * @param[out] message starting pointer.
 */ 
char* getMessage(Message frame);
/**
 * Encodes a given message contained within a frame by an offset. 
 * 
 * @param[in] frame object whose string is to be encoded.
 * @param[in] offset type encoding.
 * 
 * @returns ERROR CODE.
 */ 
ERROR encodeMessage(Message frame, size_t offset);

#endif
