#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char **data;
    size_t front;
    size_t rear;
    size_t capacity;
} Queue;

Queue* createQueue(size_t capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (char**)malloc(capacity * sizeof(char*));
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

void enqueue(Queue* queue, char* item) {
    queue->data[queue->rear] = strdup(item);
    queue->rear = (queue->rear + 1) % queue->capacity;
}

char* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    char* item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return item;
}

void freeQueue(Queue* queue) {
    for (size_t i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
        free(queue->data[i]);
    }
    free(queue->data);
    free(queue);
}

char** tokenize(const char* str, size_t* count) {
    const char* delimiters = " \t\n.,!?;:";
    char** tokens = NULL;
    size_t token_count = 0;
    const char* start = str;
    const char* end = str;

    while (1) {
        while (isspace((unsigned char)*start)) start++;
        if (*start == '\0') break;

        end = start;
        while (!isspace((unsigned char)*end) && *end != '\0') end++;

        size_t len = end - start;
        tokens = (char**)realloc(tokens, (token_count + 1) * sizeof(char*));
        tokens[token_count] = (char*)malloc((len + 1) * sizeof(char));
        strncpy(tokens[token_count], start, len);
        tokens[token_count][len] = '\0';

        start = end;
        token_count++;
    }

    *count = token_count;
    return tokens;
}

void process_data() {
    const char* text = "Sample text for processing. It includes various words and punctuation!";
    Queue* queue = createQueue(100);
    enqueue(queue, (char*)text);

    while (!isEmpty(queue)) {
        char* item = dequeue(queue);
        size_t token_count;
        char** tokens = tokenize(item, &token_count);

        for (size_t i = 0; i < token_count; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");

        for (size_t i = 0; i < token_count; i++) {
            enqueue(queue, tokens[i]);
            free(tokens[i]);
        }
        free(tokens);

        free(item);
    }

    freeQueue(queue);
}

int main() {
    process_data();
    return 0;
}