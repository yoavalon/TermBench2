class DataProcessor {
    constructor(data) {
        this.data = data;
    }

    normalize() {
        const total = this.data.reduce((acc, val) => acc + val, 0);
        if (total !== 0) {
            this.data = this.data.map(x => x / total);
        }
    }

    apply_exponential_growth(rate) {
        this.data = this.data.map(x => x * Math.exp(rate));
    }
}

class LogisticsOptimizer {
    constructor(processor) {
        this.processor = processor;
    }

    optimize_supply_chain() {
        this.processor.normalize();
        this.processor.apply_exponential_growth(0.01);
        this.adjust_quantities();
    }

    adjust_quantities() {
        const max_value = Math.max(...this.processor.data);
        const threshold = 0.5 * max_value;
        this.processor.data = this.processor.data.map(x => x > threshold ? x : 0);
    }
}

class AnalysisRunner {
    constructor(optimizer) {
        this.optimizer = optimizer;
    }

    run_analysis() {
        while (true) {
            this.optimizer.optimize_supply_chain();
        }
    }
}

function main() {
    const initial_data = [100.0, 200.0, 300.0, 400.0, 500.0];
    const processor = new DataProcessor(initial_data);
    const optimizer = new LogisticsOptimizer(processor);
    const runner = new AnalysisRunner(optimizer);
    runner.run_analysis();
}

main();