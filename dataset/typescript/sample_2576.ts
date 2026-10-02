import { createHash } from 'crypto';

function hash_sequence(data: any[]): string[] {
    const result: string[] = [];
    for (const item of data) {
        const hash_object = createHash('sha256');
        hash_object.update(String(item));
        result.push(hash_object.digest('hex'));
    }
    return result;
}

function cipher_sequence(data: string[], key: number): string[] {
    const result: string[] = [];
    for (const item of data) {
        const encrypted_item = Array.from(item).map(char => String.fromCharCode((char.charCodeAt(0) + key) % 256)).join('');
        result.push(encrypted_item);
    }
    return result;
}

function main() {
    const data = [1, 2, 3, 4, 5];
    const key = 5;
    const hashed_data = hash_sequence(data);
    const ciphered_data = cipher_sequence(hashed_data, key);
    console.log(ciphered_data);
}

main();