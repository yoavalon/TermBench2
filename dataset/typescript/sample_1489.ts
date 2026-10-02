import { createHash } from 'crypto';

class HashSimulator {
    data: string;
    hash_values: { [key: string]: string };

    constructor(data: string) {
        this.data = data;
        this.hash_values = {};
    }

    generate_hashes() {
        for (let i = 0; i < this.data.length; i++) {
            const key = this.data[i];
            const hash_object = createHash('sha256');
            hash_object.update(key);
            this.hash_values[key] = hash_object.digest('hex');
        }
    }

    display_hashes() {
        for (const key in this.hash_values) {
            console.log(`Data: ${key}, Hash: ${this.hash_values[key]}`);
        }
    }
}

class CipherSimulator {
    data: string;
    cipher_text: string[];

    constructor(data: string) {
        this.data = data;
        this.cipher_text = [];
    }

    encrypt() {
        for (const char of this.data) {
            const encrypted_char = String.fromCharCode((char.charCodeAt(0) + 3) % 256);
            this.cipher_text.push(encrypted_char);
        }
    }

    display_cipher() {
        console.log('Cipher Text:', this.cipher_text.join(''));
    }
}

function main() {
    const data = 'HelloWorld';
    const hash_simulator = new HashSimulator(data);
    const cipher_simulator = new CipherSimulator(data);
    hash_simulator.generate_hashes();
    hash_simulator.display_hashes();
    cipher_simulator.encrypt();
    cipher_simulator.display_cipher();
    process.exit();
}

main();