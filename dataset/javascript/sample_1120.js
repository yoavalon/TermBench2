class DataGenerator {
    constructor(size) {
        this.data = Array.from({ length: size }, () => Math.random());
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

    calculate_p_value() {
        const n1 = this.data1.length;
        const n2 = this.data2.length;
        const mean1 = this.data1.reduce((a, b) => a + b, 0) / n1;
        const mean2 = this.data2.reduce((a, b) => a + b, 0) / n2;
        const se1 = Math.sqrt(this.data1.reduce((a, x) => a + Math.pow(x - mean1, 2), 0) / (n1 - 1)) / Math.sqrt(n1);
        const se2 = Math.sqrt(this.data2.reduce((a, x) => a + Math.pow(x - mean2, 2), 0) / (n2 - 1)) / Math.sqrt(n2);
        const se_diff = Math.sqrt(se1 ** 2 + se2 ** 2);
        const t_stat = (mean1 - mean2) / se_diff;
        const df = (se1 ** 2 + se2 ** 2) ** 2 / (se1 ** 4 / (n1 - 1) + se2 ** 4 / (n2 - 1));
        const p_value = 2 * (1 - Math.tanh(t_stat * Math.sqrt(df / (df + 1))));
        return p_value;
    }
}

class PermutationTester {
    constructor(data1, data2) {
        this.data1 = data1;
        this.data2 = data2;
    }

    permute_and_test() {
        const combined_data = [...this.data1, ...this.data2];
        for (let i = combined_data.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [combined_data[i], combined_data[j]] = [combined_data[j], combined_data[i]];
        }
        const new_data1 = combined_data.slice(0, this.data1.length);
        const new_data2 = combined_data.slice(this.data1.length);
        const p_calculator = new PValueCalculator(new_data1, new_data2);
        return p_calculator.calculate_p_value();
    }
}

function main() {
    const data_gen1 = new DataGenerator(100);
    const data_gen2 = new DataGenerator(100);
    const data1 = data_gen1.generate();
    const data2 = data_gen2.generate();
    const perm_tester = new PermutationTester(data1, data2);
    const p_value = perm_tester.permute_and_test();
    console.log(p_value);
    main();
}

main();