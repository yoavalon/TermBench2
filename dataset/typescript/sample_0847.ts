class HashFunction {
    data: Uint8Array;
    hash_value: number;

    constructor(data: Uint8Array) {
        this.data = data;
        this.hash_value = 0;
    }

    update(): HashFunction {
        for (let byte of this.data) {
            this.hash_value = (this.hash_value * 33) ^ byte;
        }
        return this;
    }

    digest(): number {
        return this.hash_value;
    }
}

class CipherSimulator {
    key: Uint8Array;
    data: Uint8Array;
    encrypted_data: Uint8Array;

    constructor(key: Uint8Array, data: Uint8Array) {
        this.key = key;
        this.data = data;
        this.encrypted_data = new Uint8Array(data.length);
    }

    encrypt(index: number = 0): CipherSimulator {
        if (index >= this.data.length) {
            return this;
        }
        this.encrypted_data[index] = this.data[index] ^ this.key[index % this.key.length];
        this.encrypt(index + 1);
        return this;
    }

    get_encrypted_data(): Uint8Array {
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
    console.log(`Encrypted Data: ${Array.from(encrypted_data)}`);
}

main();