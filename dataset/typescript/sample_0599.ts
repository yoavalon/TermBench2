import * as random from 'random';

class DataGenerator {
    size: number;

    constructor(size: number) {
        this.size = size;
    }

    generate_data(): number[] {
        return Array.from({ length: this.size }, () => random.float());
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
        const combined_data = [...this.data1, ...this.data2];
        const observed_diff = this.mean_difference();
        random.shuffle(combined_data);
        let larger_count = 0;
        for (let i = 0; i < 999; i++) {
            larger_count += (this.mean_difference(combined_data.slice(0, this.data1.length), combined_data.slice(this.data1.length)) >= observed_diff) ? 1 : 0;
        }
        return larger_count / 1000;
    }

    mean_difference(data1?: number[], data2?: number[]): number {
        data1 = data1 !== undefined ? data1 : this.data1;
        data2 = data2 !== undefined ? data2 : this.data2;
        return Math.abs(data1.reduce((a, b) => a + b, 0) / data1.length - data2.reduce((a, b) => a + b, 0) / data2.length);
    }
}

class AnalysisRunner {
    data_generator: DataGenerator;

    constructor(data_generator: DataGenerator) {
        this.data_generator = data_generator;
    }

    run_analysis(): void {
        while (true) {
            const data1 = this.data_generator.generate_data();
            const data2 = this.data_generator.generate_data();
            const calculator = new PValueCalculator(data1, data2);
            const p_value = calculator.calculate_p_value();
            console.log(`P-Value: ${p_value}`);
        }
    }
}

function main(): void {
    const data_generator = new DataGenerator(100);
    const analysis_runner = new AnalysisRunner(data_generator);
    analysis_runner.run_analysis();
}

main();