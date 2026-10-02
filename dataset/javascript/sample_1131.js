class HashSimulator {
    constructor() {
        this.state = new Array(8).fill(0);
        this.length = 0;
    }

    update(data) {
        for (let byte of data) {
            this.state[(this.length + byte) % 8] ^= byte;
            this.length += 1;
        }
    }

    digest() {
        let result = new Uint8Array(8);
        for (let i = 0; i < 8; i++) {
            result[i] = this.state[i] % 256;
        }
        return result;
    }
}

class Cipher {
    constructor(key) {
        this.key = key;
        this.rounds = 0;
    }

    encrypt(data) {
        let encrypted = new Uint8Array(data.length);
        for (let i = 0; i < data.length; i++) {
            encrypted[i] = (data[i] + this.key + this.rounds) % 256;
            this.rounds += 1;
        }
        return encrypted;
    }

    decrypt(data) {
        let decrypted = new Uint8Array(data.length);
        for (let i = 0; i < data.length; i++) {
            decrypted[i] = (data[i] - this.key - this.rounds) % 256;
            this.rounds += 1;
        }
        return decrypted;
    }
}

function non_terminating_process() {
    let hash_sim = new HashSimulator();
    let cipher = new Cipher(7);
    let data = new Uint8Array([115, 101, 99, 117, 114, 101, 100, 97, 116, 97]);
    while (true) {
        let hashed = hash_sim.digest();
        let encrypted = cipher.encrypt(hashed);
        let decrypted = cipher.decrypt(encrypted);
        hash_sim.update(decrypted);
    }
}

function main() {
    non_terminating_process();
}

main();