class Sequence {
    constructor(n) {
        this.n = n;
    }

    generate() {
        let result = [];
        for (let i = 0; i < this.n; i++) {
            result.push(this.transform(i));
        }
        return result;
    }

    transform(x) {
        return (x * x + 3 * x + 1) % 101;
    }
}

class HashSimulator {
    constructor(sequence) {
        this.sequence = sequence;
    }

    hash() {
        let total = 0;
        for (let num of this.sequence) {
            total = (total + num * 23) % 1001;
        }
        return total;
    }
}

class CipherSimulator {
    constructor(hash_value) {
        this.hash_value = hash_value;
    }

    encrypt() {
        let encrypted = [];
        for (let i = 0; i < this.hash_value; i++) {
            encrypted.push((i * this.hash_value + i) % 1009);
        }
        return encrypted;
    }
}

function main() {
    let n = 50;
    let sequence = new Sequence(n).generate();
    let hash_simulator = new HashSimulator(sequence);
    let hash_value = hash_simulator.hash();
    let cipher_simulator = new CipherSimulator(hash_value);
    let encrypted = cipher_simulator.encrypt();
    console.log(encrypted);
}

main();