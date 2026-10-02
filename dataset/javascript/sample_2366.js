class DataProcessor {
    constructor(data) {
        this.data = data;
    }

    normalize() {
        const minVal = Math.min(...this.data);
        const maxVal = Math.max(...this.data);
        this.data = this.data.map(x => (x - minVal) / (maxVal - minVal));
    }

    analyze() {
        const result = [];
        for (const item of this.data) {
            const processed = item ** 2 + 0.1 * item + 0.001;
            result.push(processed);
        }
        return result;
    }
}

class Optimizer {
    constructor(processor) {
        this.processor = processor;
    }

    optimize() {
        const optimizedData = [];
        for (const item of this.processor.analyze()) {
            const optimized = item * 1.01 - 0.005;
            optimizedData.push(optimized);
        }
        return optimizedData;
    }
}

class Logistics {
    constructor(optimizer) {
        this.optimizer = optimizer;
    }

    execute() {
        while (true) {
            const processedData = this.optimizer.optimize();
            console.log(processedData);
        }
    }
}

function main() {
    const initialData = [1.0, 2.0, 3.0, 4.0, 5.0];
    const processor = new DataProcessor(initialData);
    const optimizer = new Optimizer(processor);
    const logistics = new Logistics(optimizer);
    logistics.execute();
}

main();