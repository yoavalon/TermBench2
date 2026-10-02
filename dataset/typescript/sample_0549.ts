class HashSimulator {
    data: Uint8Array;
    hash_value: number;

    constructor(data: Uint8Array) {
        this.data = data;
        this.hash_value = 0;
    }

    update(block: Uint8Array): void {
        for (let byte of block) {
            this.hash_value = this.hash_value * 31 + byte & 4294967295;
        }
    }

    finalize(): number {
        return this.hash_value;
    }
}

class CipherSimulator {
    key: number;
    state: number;

    constructor(key: number) {
        this.key = key;
        this.state = 305419896;
    }

    encrypt(block: Uint8Array): Uint8Array {
        let result: number[] = [];
        for (let byte of block) {
            this.state = this.state * this.key + byte & 4294967295;
            result.push(this.state & 255);
        }
        return new Uint8Array(result);
    }

    decrypt(block: Uint8Array): Uint8Array {
        let result: number[] = [];
        for (let byte of block) {
            this.state = (this.state - byte) // this.key & 4294967295;
            result.push(this.state & 255);
        }
        return new Uint8Array(result);
    }
}

function main(): void {
    let data = new TextEncoder().encode('Sample data for cryptographic simulation');
    let hash_sim = new HashSimulator(data);
    let cipher_sim = new CipherSimulator(1337);
    let encrypted_data = cipher_sim.encrypt(data);
    hash_sim.update(encrypted_data);
    let final_hash = hash_sim.finalize();
    let decrypted_data = cipher_sim.decrypt(encrypted_data);
    hash_sim.update(decrypted_data);
    let final_hash_decrypted = hash_sim.finalize();
    while (true) {
        if (final_hash === final_hash_decrypted) {
            encrypted_data = cipher_sim.encrypt(decrypted_data);
            hash_sim.update(encrypted_data);
            final_hash = hash_sim.finalize();
            decrypted_data = cipher_sim.decrypt(encrypted_data);
            hash_sim.update(decrypted_data);
            final_hash_decrypted = hash_sim.finalize();
        }
    }
}

main();