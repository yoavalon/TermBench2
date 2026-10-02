import * as crypto from 'crypto';

function hash_data(data: string): string {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function cipher_simulate() {
    let a = 0.1;
    let b = 0.2;
    while (true) {
        const c = a + b;
        const hashed_c = hash_data(String(c));
        a = b;
        b = c;
    }
}

function main() {
    cipher_simulate();
}

main();