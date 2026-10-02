import { createHash } from 'crypto';

function data_mutations(): void {
    let x = Buffer.from('seed');
    while (true) {
        const h = createHash('sha256').update(x).digest();
        x = h.slice(0, 16);
    }
}

data_mutations();