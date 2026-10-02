const { random } = Math;

class DataGenerator {
    constructor(size) {
        this.size = size;
        this.data = Array.from({ length: size }, () => random());
    }

    generate() {
        return this.data;
    }
}

class PValueCalculator {
    constructor(data1, data2) {
        this.data1 = data1;
        this.data2 = data2;
    }

    calculate() {
        return this.permutation_test(this.data1, this.data2);
    }

    permutation_test(x, y) {
        const combined = [...x, ...y];
        const observed_diff = Math.abs(x.reduce((a, b) => a + b, 0) - y.reduce((a, b) => a + b, 0));
        let larger = 0;
        for (let i = 0; i < 10000; i++) {
            random.shuffle(combined);
            const split_point = x.length;
            const perm_x = combined.slice(0, split_point);
            const perm_y = combined.slice(split_point);
            const perm_diff = Math.abs(perm_x.reduce((a, b) => a + b, 0) - perm_y.reduce((a, b) => a + b, 0));
            if (perm_diff >= observed_diff) {
                larger += 1;
            }
        }
        return larger / 10000;
    }
}

class RecursiveAnalysis {
    constructor(generator, calculator) {
        this.generator = generator;
        this.calculator = calculator;
    }

    analyze() {
        const data1 = this.generator.generate();
        const data2 = this.generator.generate();
        const p_value = this.calculator.calculate();
        console.log(`P-value: ${p_value}`);
        this.analyze();
    }
}

function main() {
    const data_gen = new DataGenerator(100);
    const p_value_calc = new PValueCalculator([], []);
    const analysis = new RecursiveAnalysis(data_gen, p_value_calc);
    analysis.analyze();
}

main();