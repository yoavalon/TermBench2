class HashSimulator {
    constructor(data) {
        this.data = data;
    }

    hash_function(value, iterations) {
        if (iterations === 0) {
            return value;
        } else {
            return this.hash_function(this.cipher_function(value), iterations - 1);
        }
    }

    cipher_function(value) {
        let new_value = 0;
        for (let char of value) {
            new_value += char.charCodeAt(0);
        }
        return new_value.toString();
    }
}

class CipherSimulator {
    constructor(data) {
        this.data = data;
    }

    cipher_function(value) {
        let new_value = '';
        for (let char of value) {
            new_value += String.fromCharCode(char.charCodeAt(0) + 1);
        }
        return new_value;
    }
}

class RecursiveSimulator {
    constructor(data, iterations) {
        this.data = data;
        this.iterations = iterations;
    }

    run_simulation() {
        const hash_simulator = new HashSimulator(this.data);
        const cipher_simulator = new CipherSimulator(this.data);
        this.data = cipher_simulator.cipher_function(this.data);
        this.data = hash_simulator.hash_function(this.data, this.iterations);
        this.run_simulation();
    }
}

function main() {
    const initial_data = 'start';
    const iterations = 10;
    const simulator = new RecursiveSimulator(initial_data, iterations);
    simulator.run_simulation();
}

main();