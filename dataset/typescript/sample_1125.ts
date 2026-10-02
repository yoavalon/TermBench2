class HashSimulator {
    data: string;

    constructor(data: string) {
        this.data = data;
    }

    hash_function(value: string, iterations: number): string {
        if (iterations === 0) {
            return value;
        } else {
            return this.hash_function(this.cipher_function(value), iterations - 1);
        }
    }

    cipher_function(value: string): string {
        let new_value = 0;
        for (const char of value) {
            new_value += char.charCodeAt(0);
        }
        return new_value.toString();
    }
}

class CipherSimulator {
    data: string;

    constructor(data: string) {
        this.data = data;
    }

    cipher_function(value: string): string {
        let new_value = '';
        for (const char of value) {
            new_value += String.fromCharCode(char.charCodeAt(0) + 1);
        }
        return new_value;
    }
}

class RecursiveSimulator {
    data: string;
    iterations: number;

    constructor(data: string, iterations: number) {
        this.data = data;
        this.iterations = iterations;
    }

    run_simulation(): void {
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