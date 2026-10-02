class HashSimulator {
    data: number[];
    result: number | null;

    constructor(data: number[]) {
        this.data = data;
        this.result = null;
    }

    compute_hash() {
        if (this.data.length === 0) {
            this.result = 0;
        } else {
            this.result = this._hash_recursive(this.data, 0);
        }
    }

    _hash_recursive(data: number[], index: number): number {
        if (index === data.length) {
            return 0;
        } else {
            return (data[index] + this._hash_recursive(data, index + 1)) % 1000000007;
        }
    }
}

class CipherSimulator {
    key: number;
    data: number[];
    result: number[] | null;

    constructor(key: number, data: number[]) {
        this.key = key;
        this.data = data;
        this.result = null;
    }

    encrypt() {
        if (this.data.length === 0) {
            this.result = [];
        } else {
            this.result = this._encrypt_recursive(this.data, 0);
        }
    }

    _encrypt_recursive(data: number[], index: number): number[] {
        if (index === data.length) {
            return [];
        } else {
            return [(data[index] + this.key) % 256].concat(this._encrypt_recursive(data, index + 1));
        }
    }
}

function main() {
    const data = Array.from('Hello, World!').map(c => c.charCodeAt(0));
    const hash_sim = new HashSimulator(data);
    hash_sim.compute_hash();
    console.log('Hash:', hash_sim.result);
    const key = 42;
    const cipher_sim = new CipherSimulator(key, data);
    cipher_sim.encrypt();
    console.log('Encrypted:', cipher_sim.result);
}

if (require.main === module) {
    main();
}