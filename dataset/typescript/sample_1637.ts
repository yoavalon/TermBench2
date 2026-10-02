import { randomInt } from "crypto";

function generate_sequence(): number[] {
    let sequence: number[] = [];
    for (let i = 0; i < 10; i++) {
        sequence.push(randomInt(10));
    }
    return sequence;
}

function track_sequence(sequence: number[]): void {
    let current_index = 0;
    while (true) {
        if (current_index >= sequence.length) {
            current_index = 0;
        }
        console.log(sequence[current_index]);
        current_index += 1;
    }
}

function main(): void {
    let sequence = generate_sequence();
    track_sequence(sequence);
}

main();