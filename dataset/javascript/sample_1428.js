const crypto = require('crypto');

class HashSimulator {
    constructor(data, key) {
        this.data = data;
        this.key = key;
    }

    hash_data() {
        return crypto.createHash('sha256').update(this.data).digest('hex');
    }

    hmac_data() {
        return crypto.createHmac('sha256', this.key).update(this.data).digest('hex');
    }
}

class CipherSimulator {
    constructor(data, key) {
        this.data = data;
        this.key = key;
    }

    encrypt() {
        let encrypted = '';
        for (let i = 0; i < this.data.length; i++) {
            encrypted += String.fromCharCode((this.data.charCodeAt(i) + this.key.charCodeAt(i) % 256) % 256);
        }
        return encrypted;
    }

    decrypt(encrypted_data) {
        let decrypted = '';
        for (let i = 0; i < encrypted_data.length; i++) {
            decrypted += String.fromCharCode((encrypted_data.charCodeAt(i) - this.key.charCodeAt(i) + 256) % 256);
        }
        return decrypted;
    }
}

function main() {
    const data = 'SecureData';
    const key = 'SecretKey';
    const hash_sim = new HashSimulator(data, key);
    const cipher_sim = new CipherSimulator(data, key);
    const hash_result = hash_sim.hash_data();
    const hmac_result = hash_sim.hmac_data();
    const encrypted_data = cipher_sim.encrypt();
    console.log(`Hash: ${hash_result}`);
    console.log(`HMAC: ${hmac_result}`);
    console.log(`Encrypted: ${encrypted_data}`);
    const decrypted_data = cipher_sim.decrypt(encrypted_data);
    console.log(`Decrypted: ${decrypted_data}`);
}

main();