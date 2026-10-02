import * as crypto from 'crypto';

class HashSimulator {
    key: string;
    message: string;

    constructor(key: string, message: string) {
        this.key = key;
        this.message = message;
    }

    hash_message(): string {
        return crypto.createHash('sha256').update(this.message).digest('hex');
    }

    hmac_message(): string {
        return crypto.createHmac('sha256', this.key).update(this.message).digest('hex');
    }
}

class CipherSimulator {
    data: string;

    constructor(data: string) {
        this.data = data;
    }

    xor_cipher(key: string): string {
        return Array.from(this.data).map((x, i) => String.fromCharCode(x.charCodeAt(0) ^ key.charCodeAt(i % key.length))).join('');
    }

    shift_cipher(shift: number): string {
        return Array.from(this.data).map(x => String.fromCharCode((x.charCodeAt(0) + shift) % 256)).join('');
    }
}

class DataProcessor {
    hash_simulator: HashSimulator;
    cipher_simulator: CipherSimulator;

    constructor(hash_simulator: HashSimulator, cipher_simulator: CipherSimulator) {
        this.hash_simulator = hash_simulator;
        this.cipher_simulator = cipher_simulator;
    }

    process_data(): [string, string, string] {
        const hash_result = this.hash_simulator.hash_message();
        const hmac_result = this.hash_simulator.hmac_message();
        const xor_result = this.cipher_simulator.xor_cipher(hash_result.slice(0, 16));
        const shift_result = this.cipher_simulator.shift_cipher(5);
        return [hmac_result, xor_result, shift_result];
    }
}

function main() {
    const key = crypto.randomBytes(16).toString('hex');
    const message = 'SecureMessage';
    const hash_sim = new HashSimulator(key, message);
    const cipher_sim = new CipherSimulator(message);
    const data_processor = new DataProcessor(hash_sim, cipher_sim);
    const result = data_processor.process_data();
    console.log(result);
}

main();