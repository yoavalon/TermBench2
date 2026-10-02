import * as random from 'random';
import * as math from 'mathjs';

class DataGenerator {
    data: number[];

    constructor(size: number) {
        this.data = Array.from({ length: size }, () => random.gauss(0, 1));
    }
}

class PValueCalculator {
    data1: number[];
    data2: number[];

    constructor(data1: number[], data2: number[]) {
        this.data1 = data1;
        this.data2 = data2;
    }

    calculate_p_value(): number {
        const mean1 = this.data1.reduce((acc, val) => acc + val, 0) / this.data1.length;
        const mean2 = this.data2.reduce((acc, val) => acc + val, 0) / this.data2.length;
        const diff = mean1 - mean2;
        const var1 = this.data1.reduce((acc, val) => acc + math.pow(val - mean1, 2), 0) / this.data1.length;
        const var2 = this.data2.reduce((acc, val) => acc + math.pow(val - mean2, 2), 0) / this.data2.length;
        return diff / math.sqrt(var1 + var2);
    }
}

class PermutationTester {
    data1: number[];
    data2: number[];
    iterations: number;

    constructor(data1: number[], data2: number[], iterations: number) {
        this.data1 = data1;
        this.data2 = data2;
        this.iterations = iterations;
    }

    permute_and_test(): number {
        const original_p_value = new PValueCalculator(this.data1, this.data2).calculate_p_value();
        let larger = 0;
        const combined_data = [...this.data1, ...this.data2];
        for (let i = 0; i < this.iterations; i++) {
            random.shuffle(combined_data);
            const new_data1 = combined_data.slice(0, this.data1.length);
            const new_data2 = combined_data.slice(this.data1.length);
            const new_p_value = new PValueCalculator(new_data1, new_data2).calculate_p_value();
            if (math.abs(new_p_value) >= math.abs(original_p_value)) {
                larger += 1;
            }
        }
        return larger / this.iterations;
    }
}

function main() {
    const size = 100;
    const iterations = 1000;
    const generator1 = new DataGenerator(size);
    const generator2 = new DataGenerator(size);
    const tester = new PermutationTester(generator1.data, generator2.data, iterations);
    const result = tester.permute_and_test();
    console.log(result);
}

main();