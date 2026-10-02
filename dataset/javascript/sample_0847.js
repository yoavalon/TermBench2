class HashFunction {
    constructor(data) {
        this.data = data;
        this.hash_value = 0;
    }

    update() {
        for (let byte of this.data) {
            this.hash_value = this.hash_value * 33 ^ byte;
        }
        return this;
    }

    digest() {
        return this.hash_value;
    }
}

class CipherSimulator {
    constructor(key, data) {
        this.key = key;
        this.data = data;
        this.encrypted_data = new Array(data.length).fill(0);
    }

    encrypt(index = 0) {
        if (index >= this.data.length) {
            return this;
        }
        this.encrypted_data[index] = this.data[index] ^ this.key[index % this.key.length];
        this.encrypt(index + 1);
        return this;
    }

    get_encrypted_data() {
        return this.encrypted_data;
    }
}

function main() {
    const original_data = new TextEncoder().encode('Hello, world!');
    const hash_function = new HashFunction(original_data);
    hash_function.update();
    const hash_value = hash_function.digest();
    const key = new TextEncoder().encode('secret');
    const cipher_simulator = new CipherSimulator(key, original_data);
    cipher_simulator.encrypt();
    const encrypted_data = cipher_simulator.get_encrypted_data();
    console.log(`Hash Value: ${hash_value}`);
    console.log(`Encrypted Data: ${encrypted_data}`);
}

main();