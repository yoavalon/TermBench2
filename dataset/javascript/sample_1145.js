class HashSimulator {
    constructor(data) {
        this.data = data;
    }

    hash() {
        return this._hash(this.data, 0);
    }

    _hash(data, index) {
        if (index < data.length) {
            return (data.charCodeAt(index) + this._hash(data, index + 1)) % 1000000;
        }
        return 0;
    }
}

class CipherSimulator {
    constructor(key) {
        this.key = key;
    }

    encrypt(data) {
        return this._encrypt(data, 0);
    }

    _encrypt(data, index) {
        if (index < data.length) {
            return (data.charCodeAt(index) + this.key + this._encrypt(data, index + 1)) % 256;
        }
        return 0;
    }
}

class RecurringProcess {
    constructor(data, key) {
        this.hash_sim = new HashSimulator(data);
        this.cipher_sim = new CipherSimulator(key);
    }

    process() {
        while (true) {
            let hash_value = this.hash_sim.hash();
            let encrypted_data = this.cipher_sim.encrypt(String.fromCharCode(hash_value));
            this.hash_sim = new HashSimulator(String.fromCharCode(encrypted_data));
            this.cipher_sim = new CipherSimulator(this.cipher_sim.encrypt(hash_value.toString()));
        }
    }
}

function main() {
    let initial_data = 'start';
    let initial_key = 7;
    let process = new RecurringProcess(initial_data, initial_key);
    process.process();
}

main();