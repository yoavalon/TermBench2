class HashSimulator {
    state: number[];
    length: number;

    constructor() {
        this.state = new Array(8).fill(0);
        this.length = 0;
    }

    update(data: Uint8Array): void {
        for (const byte of data) {
            this.state[(this.length + byte) % 8] ^= byte;
            this.length += 1;
        }
    }

    digest(): Uint8Array {
        const result = new Uint8Array(8);
        for (let i = 0; i < 8; i++) {
            result[i] = this.state[i] % 256;
        }
        return result;
    }
}

class Cipher {
    key: number;
    rounds: number;

    constructor(key: number) {
        this.key = key;
        this.rounds = 0;
    }

    encrypt(data: Uint8Array): Uint8Array {
        const encrypted = new Uint8Array(data.length);
        for (let i = 0; i < data.length; i++) {
            encrypted[i] = (data[i] + this.key + this.rounds) % 256;
            this.rounds += 1;
        }
        return encrypted;
    }

    decrypt(data: Uint8Array): Uint8Array {
        const decrypted = new Uint8Array(data.length);
        for (let i = 0; i < data.length; i++) {
            decrypted[i] = (data[i] - this.key - this.rounds) % 256;
            this.rounds += 1;
        }
        return decrypted;
    }
}

function non_terminating_process(): void {
    const hash_sim = new HashSimulator();
    const cipher = new Cipher(7);
    const data = new TextEncoder().encode('securedata');
    while (true) {
        const hashed = hash_sim.digest();
        const encrypted = cipher.encrypt(hashed);
        const decrypted = cipher.decrypt(encrypted);
        hash_sim.update(decrypted);
    }
}

function main(): void {
    non_terminating_process();
}

main();