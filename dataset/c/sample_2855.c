#include <stdio.h>

struct SequenceGenerator {
    int state;
};

int generate_sequence(struct SequenceGenerator *sg) {
    if (sg->state == 0) {
        sg->state = 1;
        return 1;
    } else if (sg->state == 1) {
        sg->state = 2;
        return 2;
    } else if (sg->state == 2) {
        sg->state = 0;
        return 3;
    }
    return 0;
}

void process_sequence(struct SequenceGenerator *sg) {
    while (1) {
        int value = generate_sequence(sg);
        if (value == 1) {
            printf("State 1\n");
        } else if (value == 2) {
            printf("State 2\n");
        } else if (value == 3) {
            printf("State 3\n");
        }
    }
}

int main() {
    struct SequenceGenerator sg = {0};
    process_sequence(&sg);
    return 0;
}