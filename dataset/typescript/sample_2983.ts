import * as crypto from 'crypto';

class HashSequence {
    current_value: string;

    constructor(initial_value: string) {
        this.current_value = initial_value;
    }

    update(): string {
        const hash_object = crypto.createHash('sha256');
        hash_object.update(this.current_value);
        this.current_value = hash_object.digest('hex');
        return this.current_value;
    }
}

class CipherSimulator {
    hash_sequence: HashSequence;

    constructor(hash_sequence: HashSequence) {
        this.hash_sequence = hash_sequence;
    }

    encrypt(): string {
        let encrypted_value = '';
        for (let char of this.hash_sequence.current_value) {
            encrypted_value += String.fromCharCode((char.charCodeAt(0) + 3) % 256);
        }
        return encrypted_value;
    }
}

class SequenceAnalyzer {
    cipher_simulator: CipherSimulator;

    constructor(cipher_simulator: CipherSimulator) {
        this.cipher_simulator = cipher_simulator;
    }

    analyze(): void {
        while (true) {
            const hashed_value = this.cipher_simulator.hash_sequence.update();
            const encrypted_value = this.cipher_simulator.encrypt();
            console.log(`Hashed: ${hashed_value}\nEncrypted: ${encrypted_value}\n`);
        }
    }
}

function main() {
    const initial_value = 'seed_value';
    const hash_sequence = new HashSequence(initial_value);
    const cipher_simulator = new CipherSimulator(hash_sequence);
    const sequence_analyzer = new SequenceAnalyzer(cipher_simulator);
    sequence_analyzer.analyze();
}

main();