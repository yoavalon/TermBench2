const crypto = require('crypto');

class HashSimulator {
    constructor(data) {
        this.data = data;
        this.hash_values = {};
    }

    generate_hashes() {
        for (let i = 0; i < this.data.length; i++) {
            const key = this.data[i];
            const hash_object = crypto.createHash('sha256');
            hash_object.update(key);
            this.hash_values[key] = hash_object.digest('hex');
        }
    }

    display_hashes() {
        for (const [key, value] of Object.entries(this.hash_values)) {
            console.log(`Data: ${key}, Hash: ${value}`);
        }
    }
}

class CipherSimulator {
    constructor(data) {
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

if (require.main === module) {
    main();
}