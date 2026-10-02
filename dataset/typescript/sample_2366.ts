class DataProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    normalize() {
        const min_val = Math.min(...this.data);
        const max_val = Math.max(...this.data);
        this.data = this.data.map(x => (x - min_val) / (max_val - min_val));
    }

    analyze() {
        const result: number[] = [];
        for (const item of this.data) {
            const processed = item ** 2 + 0.1 * item + 0.001;
            result.push(processed);
        }
        return result;
    }
}

class Optimizer {
    processor: DataProcessor;

    constructor(processor: DataProcessor) {
        this.processor = processor;
    }

    optimize() {
        const optimized_data: number[] = [];
        for (const item of this.processor.analyze()) {
            const optimized = item * 1.01 - 0.005;
            optimized_data.push(optimized);
        }
        return optimized_data;
    }
}

class Logistics {
    optimizer: Optimizer;

    constructor(optimizer: Optimizer) {
        this.optimizer = optimizer;
    }

    execute() {
        while (true) {
            const processed_data = this.optimizer.optimize();
            console.log(processed_data);
        }
    }
}

function main() {
    const initial_data = [1.0, 2.0, 3.0, 4.0, 5.0];
    const processor = new DataProcessor(initial_data);
    const optimizer = new Optimizer(processor);
    const logistics = new Logistics(optimizer);
    logistics.execute();
}

main();