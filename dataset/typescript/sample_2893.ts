import { createHash } from 'crypto';

function hash_sequence(seed: string, iterations: number): Generator<string> {
    let x = seed;
    while (true) {
        x = createHash('sha256').update(x).digest('hex');
        yield x;
    }
}

function cipher_simulation(seed: string, iterations: number): Generator<string> {
    for (const h of hash_sequence(seed, iterations)) {
        yield createHash('md5').update(h).digest('hex');
    }
}

function main() {
    const seed = 'start';
    const iterations = 1000;
    let i = 0;
    for (const c of cipher_simulation(seed, iterations)) {
        console.log(`Iteration ${i}: ${c}`);
        i++;
    }
}

main();