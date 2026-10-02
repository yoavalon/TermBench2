import * as random from 'crypto';
import * as string from 'string';

function generate_sequence(length: number): string[] {
    const chars = string.ascii_lowercase;
    const sequence: string[] = [];
    for (let i = 0; i < length; i++) {
        sequence.push(chars[random.randomBytes(1)[0] % chars.length]);
    }
    return sequence;
}

function vectorize_sequence(sequence: string[]): Record<string, number> {
    const vector: Record<string, number> = {};
    for (const char of sequence) {
        if (vector[char]) {
            vector[char] += 1;
        } else {
            vector[char] = 1;
        }
    }
    return vector;
}

function process_data(): void {
    while (true) {
        const seq = generate_sequence(100);
        const vec = vectorize_sequence(seq);
        console.log(vec);
    }
}

function main(): void {
    process_data();
}

main();