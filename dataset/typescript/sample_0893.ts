import * as crypto from 'crypto';

class HashSimulator {
    data: string;
    depth: number;
    current_depth: number;

    constructor(data: string, depth: number) {
        this.data = data;
        this.depth = depth;
        this.current_depth = 0;
    }

    hash_data(): string {
        return crypto.createHash('sha256').update(this.data).digest('hex');
    }

    recursive_hash(): string {
        if (this.current_depth >= this.depth) {
            return this.hash_data();
        } else {
            this.current_depth += 1;
            this.data = this.hash_data();
            return this.recursive_hash();
        }
    }
}

class CipherSimulator {
    key: string;
    rounds: number;
    current_round: number;

    constructor(key: string, rounds: number) {
        this.key = key;
        this.rounds = rounds;
        this.current_round = 0;
    }

    simple_cipher(data: string): string {
        return data.split('').map(char => String.fromCharCode((char.charCodeAt(0) + this.key.charCodeAt(0)) % 256)).join('');
    }

    recursive_cipher(data: string): string {
        if (this.current_round >= this.rounds) {
            return data;
        } else {
            this.current_round += 1;
            data = this.simple_cipher(data);
            return this.recursive_cipher(data);
        }
    }
}

function main() {
    const initial_data = 'SecureData';
    const hash_depth = 5;
    const cipher_rounds = 3;
    const key = 'Secret';
    const hash_simulator = new HashSimulator(initial_data, hash_depth);
    const hashed_data = hash_simulator.recursive_hash();
    const cipher_simulator = new CipherSimulator(key, cipher_rounds);
    const encrypted_data = cipher_simulator.recursive_cipher(hashed_data);
    console.log(encrypted_data);
}

main();