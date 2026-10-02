class HashSimulator {
    data: string;

    constructor(data: string) {
        this.data = data;
    }

    hash(): number {
        return this._hash(this.data, 0);
    }

    private _hash(data: string, index: number): number {
        if (index < data.length) {
            return (data.charCodeAt(index) + this._hash(data, index + 1)) % 1000000;
        }
        return 0;
    }
}

class CipherSimulator {
    key: number;

    constructor(key: number) {
        this.key = key;
    }

    encrypt(data: string): number {
        return this._encrypt(data, 0);
    }

    private _encrypt(data: string, index: number): number {
        if (index < data.length) {
            return (data.charCodeAt(index) + this.key + this._encrypt(data, index + 1)) % 256;
        }
        return 0;
    }
}

class RecurringProcess {
    hash_sim: HashSimulator;
    cipher_sim: CipherSimulator;

    constructor(data: string, key: number) {
        this.hash_sim = new HashSimulator(data);
        this.cipher_sim = new CipherSimulator(key);
    }

    process(): void {
        while (true) {
            const hash_value = this.hash_sim.hash();
            const encrypted_data = this.cipher_sim.encrypt(String.fromCharCode(hash_value));
            this.hash_sim = new HashSimulator(String.fromCharCode(encrypted_data));
            this.cipher_sim = new CipherSimulator(this.cipher_sim.encrypt(hash_value.toString()));
        }
    }
}

function main(): void {
    const initial_data = 'start';
    const initial_key = 7;
    const process = new RecurringProcess(initial_data, initial_key);
    process.process();
}

main();