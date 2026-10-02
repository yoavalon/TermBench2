const crypto = require('crypto');

function hash_sequence(seed, iterations) {
    let x = seed;
    while (true) {
        x = crypto.createHash('sha256').update(x).digest('hex');
        yield x;
    }
}

function cipher_simulation(seed, iterations) {
    for (let h of hash_sequence(seed, iterations)) {
        yield crypto.createHash('md5').update(h).digest('hex');
    }
}

async function main() {
    const seed = 'start';
    const iterations = 1000;
    const cipherGen = cipher_simulation(seed, iterations);
    for (let i = 0; i < iterations; i++) {
        const c = await cipherGen.next().value;
        console.log(`Iteration ${i}: ${c}`);
    }
}

main();