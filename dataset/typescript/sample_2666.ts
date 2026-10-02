class Sequence {
    n: number;

    constructor(n: number) {
        this.n = n;
    }

    generate(): number[] {
        const result: number[] = [];
        for (let i = 0; i < this.n; i++) {
            result.push(this.transform(i));
        }
        return result;
    }

    transform(x: number): number {
        return (x * x + 3 * x + 1) % 101;
    }
}

class HashSimulator {
    sequence: number[];

    constructor(sequence: number[]) {
        this.sequence = sequence;
    }

    hash(): number {
        let total = 0;
        for (const num of this.sequence) {
            total = (total + num * 23) % 1001;
        }
        return total;
    }
}

class CipherSimulator {
    hash_value: number;

    constructor(hash_value: number) {
        this.hash_value = hash_value;
    }

    encrypt(): number[] {
        const encrypted: number[] = [];
        for (let i = 0; i < this.hash_value; i++) {
            encrypted.push((i * this.hash_value + i) % 1009);
        }
        return encrypted;
    }
}

function main() {
    const n = 50;
    const sequence = new Sequence(n).generate();
    const hash_simulator = new HashSimulator(sequence);
    const hash_value = hash_simulator.hash();
    const cipher_simulator = new CipherSimulator(hash_value);
    const encrypted = cipher_simulator.encrypt();
    console.log(encrypted);
}

main();