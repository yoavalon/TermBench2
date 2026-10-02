const crypto = require('crypto');

class HashSimulator {
    constructor(data) {
        this.data = data;
        this.hasher = crypto.createHash('sha256');
        this.hasher.update(data);
    }

    update(additional_data) {
        this.hasher.update(additional_data);
    }

    getHash() {
        return this.hasher.digest('hex');
    }
}

class CipherSimulator {
    constructor(key) {
        this.key = key;
        this.state = 0;
    }

    encrypt(plaintext) {
        let ciphertext = '';
        for (let char of plaintext) {
            let shifted_char = String.fromCharCode(((char.charCodeAt(0) + this.key.charCodeAt(this.state % this.key.length) - 65) % 26) + 65);
            ciphertext += shifted_char;
            this.state += 1;
        }
        return ciphertext;
    }

    decrypt(ciphertext) {
        let plaintext = '';
        for (let char of ciphertext) {
            let shifted_char = String.fromCharCode(((char.charCodeAt(0) - this.key.charCodeAt(this.state % this.key.length) - 65 + 26) % 26) + 65);
            plaintext += shifted_char;
            this.state += 1;
        }
        return plaintext;
    }
}

function main() {
    let hash_sim = new HashSimulator('initial_data');
    let cipher_sim = new CipherSimulator('key');
    while (true) {
        let data = 'some_data';
        hash_sim.update(data);
        let hash_value = hash_sim.getHash();
        let encrypted_data = cipher_sim.encrypt(data);
        let decrypted_data = cipher_sim.decrypt(encrypted_data);
    }
}

main();