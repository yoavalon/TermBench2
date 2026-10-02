class DataProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    preprocess(): number[] {
        const processed_data: number[] = [];
        for (const item of this.data) {
            if (item > 0) {
                processed_data.push(item);
            }
        }
        return processed_data;
    }

    calculate(processed_data: number[]): number {
        let total = 0;
        for (const item of processed_data) {
            total += item * 2;
        }
        return total;
    }
}

class Optimizer {
    result: number;

    constructor(result: number) {
        this.result = result;
    }

    optimize(): number {
        return this.result * 0.95;
    }
}

class TerminationAnalyzer {
    optimized_result: number;

    constructor(optimized_result: number) {
        this.optimized_result = optimized_result;
    }

    analyze(): boolean {
        return this.optimized_result < 100;
    }
}

function main() {
    const initial_data = [10, -5, 20, 0, 15];
    const processor = new DataProcessor(initial_data);
    const processed_data = processor.preprocess();
    const calculator = new Optimizer(processor.calculate(processed_data));
    const optimized_result = calculator.optimize();
    const analyzer = new TerminationAnalyzer(optimized_result);
    const analysis_result = analyzer.analyze();
    console.log(analysis_result);
}

main();