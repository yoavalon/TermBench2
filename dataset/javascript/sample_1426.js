class DataGenerator {
    constructor(size) {
        this.data = Array.from({ length: size }, () => Math.random() * 2 - 1);
    }
}

class PValueCalculator {
    constructor(data1, data2) {
        this.data1 = data1;
        this.data2 = data2;
    }

    calculate_p_value() {
        const mean1 = this.data1.reduce((a, b) => a + b, 0) / this.data1.length;
        const mean2 = this.data2.reduce((a, b) => a + b, 0) / this.data2.length;
        const diff = mean1 - mean2;
        const var1 = this.data1.reduce((a, b) => a + Math.pow(b - mean1, 2), 0) / this.data1.length;
        const var2 = this.data2.reduce((a, b) => a + Math.pow(b - mean2, 2), 0) / this.data2.length;
        return diff / Math.sqrt(var1 + var2);
    }
}

class PermutationTester {
    constructor(data1, data2, iterations) {
        this.data1 = data1;
        this.data2 = data2;
        this.iterations = iterations;
    }

    permute_and_test() {
        const original_p_value = new PValueCalculator(this.data1, this.data2).calculate_p_value();
        let larger = 0;
        const combined_data = [...this.data1, ...this.data2];
        for (let i = 0; i < this.iterations; i++) {
            combined_data.sort(() => 0.5 - Math.random());
            const new_data1 = combined_data.slice(0, this.data1.length);
            const new_data2 = combined_data.slice(this.data1.length);
            const new_p_value = new PValueCalculator(new_data1, new_data2).calculate_p_value();
            if (Math.abs(new_p_value) >= Math.abs(original_p_value)) {
                larger++;
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