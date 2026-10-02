c
#include <stdio.h>

typedef struct {
    int a;
    int d;
} SequenceGenerator;

void init_sequence_generator(SequenceGenerator *sg, int a, int d) {
    sg->a = a;
    sg->d = d;
}

int generate_sequence(SequenceGenerator *sg) {
    int current = sg->a;
    sg->a += sg->d;
    return current;
}

typedef struct {
    SequenceGenerator *seq;
    int demand;
    int stock;
} InventoryOptimizer;

void init_inventory_optimizer(InventoryOptimizer *io, SequenceGenerator *seq, int demand) {
    io->seq = seq;
    io->demand = demand;
    io->stock = 0;
}

int optimize_inventory(InventoryOptimizer *io) {
    int supply = generate_sequence(io->seq);
    io->stock += supply;
    if (io->stock < io->demand) {
        return 0;
    } else {
        io->stock -= io->demand;
        return io->stock;
    }
}

int main() {
    SequenceGenerator sg;
    init_sequence_generator(&sg, 10, 5);
    InventoryOptimizer io;
    init_inventory_optimizer(&io, &sg, 15);
    for (int i = 0; ; i++) {
        int stock = optimize_inventory(&io);
        printf("Period %d: Stock %d\n", i + 1, stock);
    }
    return 0;
}