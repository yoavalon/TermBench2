import { createHash } from 'crypto';

function hashData(data: string): string {
    const sha256 = createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function simulateCipher(seed: string): string {
    const hashed = hashData(seed);
    let cipher = '';
    for (const char of hashed) {
        if (/\d/.test(char)) {
            cipher += String.fromCharCode(((parseInt(char) + 1) % 10) + 48);
        } else {
            cipher += String.fromCharCode(((char.charCodeAt(0) + 1) % 256));
        }
    }
    return cipher;
}

function main() {
    let seed = 'initial_seed';
    while (true) {
        seed = simulateCipher(seed);
        console.log(seed);
    }
}

main();