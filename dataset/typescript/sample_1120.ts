import * as random from 'random';
import * as math from 'mathjs';

class DataGenerator {
    data: number[];

    constructor(size: number) {
        this.data = Array.from({ length: size }, () => random.random());
    }

    generate(): number[] {
        return this.data;
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
        const n1 = this.data1.length;
        const n2 = this.data2.length;
        const mean1 = this.data1.reduce((a, b) => a + b, 0) / n1;
        const mean2 = this.data2.reduce((a, b) => a + b, 0) / n2;
        const se1 = math.sqrt(this.data1.reduce((a, b) => a + (b - mean1) ** 2, 0) / (n1 - 1)) / math.sqrt(n1);
        const se2 = math.sqrt(this.data2.reduce((a, b) => a + (b - mean2) ** 2, 0) / (n2 - 1)) / math.sqrt(n2);
        const se_diff = math.sqrt(se1 ** 2 + se2 ** 2);
        const t_stat = (mean1 - mean2) / se_diff;
        const df = (se1 ** 2 + se2 ** 2) ** 2 / (se1 ** 4 / (n1 - 1) + se2 ** 4 / (n2 - 1));
        const p_value = 2 * (1 - math.tanh(t_stat * math.sqrt(df / (df + 1))));
        return p_value;
    }
}

class PermutationTester {
    data1: number[];
    data2: number[];

    constructor(data1: number[], data2: number[]) {
        this.data1 = data1;
        this.data2 = data2;
    }

    permute_and_test(): number {
        const combined_data = [...this.data1, ...this.data2];
        random.shuffle(combined_data);
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