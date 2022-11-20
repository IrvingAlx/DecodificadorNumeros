#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "../libs/unity.h"
#include "../libs/Encoder.h"

#define TEST_ARRAY "Hello BuddyBud \0"
#define SECRET_CODE "77,112,33,105,98,116,33,109,112,104,115,98,101,112,34,33,\0"

static char* buffer = NULL;

void setUp(void){
    buffer = calloc(BUFSIZ, sizeof(char));
    strncpy(buffer, TEST_ARRAY, BUFSIZ);
}

void tearDown(void){
    free(buffer);
}

void test_encoderInit(void){
    puts("Positive Test");
    Message frame = newMessageContainer(TEST_ARRAY);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, getMessage(frame), strlen(TEST_ARRAY));

}

void test_encoderOffset(void){
    Message frame = NULL;
    puts("Testing offset Encoder");
    frame = newMessageContainer(SECRET_CODE);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(SECRET_CODE,getMessage(frame), strlen(SECRET_CODE));

}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_encoderInit, __LINE__);
    RUN_TEST(test_encoderOffset, __LINE__);
    
    Message example = newMessageContainer(SECRET_CODE);
    setMessage(example, SECRET_CODE);

    encodeMessage(example, -1);
    
    return UNITY_END();

}