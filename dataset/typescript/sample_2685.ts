import * as crypto from 'crypto';

class HashSimulator {
    data: string;
    hash_values: string[];

    constructor(data: string) {
        this.data = data;
        this.hash_values = [];
    }

    generate_hashes(rounds: number): void {
        for (let _ = 0; _ < rounds; _++) {
            this.data = crypto.createHash('sha256').update(this.data).digest('hex');
            this.hash_values.push(this.data);
        }
    }

    get_hash_sequence(): string[] {
        return this.hash_values;
    }
}

class CipherSimulator {
    key: string;
    encrypted_values: string[];

    constructor(key: string) {
        this.key = key;
        this.encrypted_values = [];
    }

    encrypt(value: string): void {
        let encrypted_value = '';
        for (let i = 0; i < value.length; i++) {
            encrypted_value += String.fromCharCode(((value.charCodeAt(i) + this.key.charCodeAt(i % this.key.length)) % 256));
        }
        this.encrypted_values.push(encrypted_value);
    }

    get_encrypted_sequence(): string[] {
        return this.encrypted_values;
    }
}

function main() {
    const initial_data = 'seed';
    const hash_rounds = 5;
    const cipher_key = 'key';
    const hash_sim = new HashSimulator(initial_data);
    hash_sim.generate_hashes(hash_rounds);
    const hash_sequence = hash_sim.get_hash_sequence();
    const cipher_sim = new CipherSimulator(cipher_key);
    for (const hash_value of hash_sequence) {
        cipher_sim.encrypt(hash_value);
    }
    const encrypted_sequence = cipher_sim.get_encrypted_sequence();
    console.log(encrypted_sequence);
}

main();