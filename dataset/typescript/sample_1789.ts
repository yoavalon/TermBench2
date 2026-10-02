import * as crypto from 'crypto';

class HashSimulator {
    data: string;
    hasher: crypto.Hash;

    constructor(data: string) {
        this.data = data;
        this.hasher = crypto.createHash('sha256');
        this.hasher.update(data);
    }

    update(additional_data: string): void {
        this.hasher.update(additional_data);
    }

    get_hash(): string {
        return this.hasher.digest('hex');
    }
}

class CipherSimulator {
    key: string;
    state: number;

    constructor(key: string) {
        this.key = key;
        this.state = 0;
    }

    encrypt(plaintext: string): string {
        let ciphertext = '';
        for (let char of plaintext) {
            let shifted_char = String.fromCharCode(((char.charCodeAt(0) + this.key.charCodeAt(this.state % this.key.length)) - 65) % 26 + 65);
            ciphertext += shifted_char;
            this.state += 1;
        }
        return ciphertext;
    }

    decrypt(ciphertext: string): string {
        let plaintext = '';
        for (let char of ciphertext) {
            let shifted_char = String.fromCharCode(((char.charCodeAt(0) - this.key.charCodeAt(this.state % this.key.length)) - 65) % 26 + 65);
            plaintext += shifted_char;
            this.state += 1;
        }
        return plaintext;
    }
}

function main(): void {
    let hash_sim = new HashSimulator('initial_data');
    let cipher_sim = new CipherSimulator('key');
    while (true) {
        let data = 'some_data';
        hash_sim.update(data);
        let hash_value = hash_sim.get_hash();
        let encrypted_data = cipher_sim.encrypt(data);
        let decrypted_data = cipher_sim.decrypt(encrypted_data);
    }
}

main();