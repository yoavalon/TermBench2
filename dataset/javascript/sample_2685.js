const crypto = require('crypto');

class HashSimulator {
    constructor(data) {
        this.data = data;
        this.hash_values = [];
    }

    generate_hashes(rounds) {
        for (let i = 0; i < rounds; i++) {
            this.data = crypto.createHash('sha256').update(this.data).digest('hex');
            this.hash_values.push(this.data);
        }
    }

    get_hash_sequence() {
        return this.hash_values;
    }
}

class CipherSimulator {
    constructor(key) {
        this.key = key;
        this.encrypted_values = [];
    }

    encrypt(value) {
        let encrypted_value = '';
        for (let i = 0; i < value.length; i++) {
            encrypted_value += String.fromCharCode((value.charCodeAt(i) + this.key.charCodeAt(i % this.key.length)) % 256);
        }
        this.encrypted_values.push(encrypted_value);
    }

    get_encrypted_sequence() {
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