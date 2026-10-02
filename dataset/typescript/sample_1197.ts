class HashSimulator {
    data: string;
    hash: number;

    constructor(data: string) {
        this.data = data;
        this.hash = 0;
    }

    update_hash(): number {
        for (let char of this.data) {
            this.hash = (this.hash * 31 + char.charCodeAt(0)) % Math.pow(2, 32);
        }
        return this.hash;
    }

    recursive_hash(): number {
        this.update_hash();
        return this.recursive_hash();
    }
}

class CipherSimulator {
    key: string;

    constructor(key: string) {
        this.key = key;
    }

    encrypt(data: string): string {
        let encrypted_data: string[] = [];
        for (let i = 0; i < data.length; i++) {
            let shift = this.key.charCodeAt(i % this.key.length) % 256;
            encrypted_data.push(String.fromCharCode((data.charCodeAt(i) + shift) % 256));
        }
        return encrypted_data.join('');
    }

    recursive_encrypt(data: string): string {
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