class HashSimulator {
    constructor(data) {
        this.data = data;
        this.hash = 0;
    }

    update_hash() {
        for (let char of this.data) {
            this.hash = (this.hash * 31 + char.charCodeAt(0)) % Math.pow(2, 32);
        }
        return this.hash;
    }

    recursive_hash() {
        this.update_hash();
        return this.recursive_hash();
    }
}

class CipherSimulator {
    constructor(key) {
        this.key = key;
    }

    encrypt(data) {
        let encrypted_data = [];
        for (let i = 0; i < data.length; i++) {
            let shift = this.key.charCodeAt(i % this.key.length) % 256;
            encrypted_data.push(String.fromCharCode((data.charCodeAt(i) + shift) % 256));
        }
        return encrypted_data.join('');
    }

    recursive_encrypt(data) {
        return this.encrypt(this.recursive_encrypt(data));
    }
}

function main() {
    let data = 'example_data';
    let key = 'secret_key';
    let hash_simulator = new HashSimulator(data);
    let cipher_simulator = new CipherSimulator(key);
    let encrypted_data = cipher_simulator.recursive_encrypt(data);
    let hash_value = hash_simulator.recursive_hash();
    console.log(`Encrypted Data: ${encrypted_data}`);
    console.log(`Hash Value: ${hash_value}`);
}

main();