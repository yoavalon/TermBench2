import { createHash } from 'crypto';

function hash_data(data: string): string {
    const sha256 = createHash('sha256');
    sha256.update(data, 'utf-8');
    return sha256.digest('hex');
}

function simulate_cipher(hash_value: string): string {
    let result = '';
    for (let char of hash_value) {
        if (/\d/.test(char)) {
            result += ((parseInt(char) + 5) % 10).toString();
        } else {
            result += String.fromCharCode((char.charCodeAt(0) + 3) % 256);
        }
    }
    return result;
}

function main() {
    const data = 'securedata';
    const hashed = hash_data(data);
    const ciphered = simulate_cipher(hashed);
    console.log(ciphered);
}

main();