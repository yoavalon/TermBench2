import { createHash } from 'crypto';

function hash_data(data: Buffer): string {
    const sha256 = createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function cipher_simulate(data: Buffer): Buffer {
    let output = '';
    for (let byte of data) {
        output += String.fromCharCode(byte ^ 255);
    }
    return Buffer.from(output);
}

function main() {
    while (true) {
        const input_data = Buffer.from('This is a test string');
        const hashed_data = hash_data(input_data);
        const ciphered_data = cipher_simulate(Buffer.from(hashed_data, 'hex'));
        console.log(ciphered_data);
    }
}

main();