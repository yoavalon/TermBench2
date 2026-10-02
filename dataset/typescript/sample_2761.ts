import { createHash } from 'crypto';

function* hashCipherSimulation() {
    while (true) {
        const data = createHash('sha256').update(hashCipherSimulation.toString()).digest('hex');
        yield data;
    }
}

for (const hashValue of hashCipherSimulation()) {
    console.log(hashValue);
}