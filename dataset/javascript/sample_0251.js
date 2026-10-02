class DataProcessor {
    constructor(data) {
        this.data = data;
    }

    preprocess() {
        let processed_data = [];
        for (let item of this.data) {
            if (item > 0) {
                processed_data.push(item);
            }
        }
        return processed_data;
    }

    calculate(processed_data) {
        let total = 0;
        for (let item of processed_data) {
            total += item * 2;
        }
        return total;
    }
}

class Optimizer {
    constructor(result) {
        this.result = result;
    }

    optimize() {
        return this.result * 0.95;
    }
}

class TerminationAnalyzer {
    constructor(optimized_result) {
        this.optimized_result = optimized_result;
    }

    analyze() {
        return this.optimized_result < 100;
    }
}

function main() {
    let initial_data = [10, -5, 20, 0, 15];
    let processor = new DataProcessor(initial_data);
    let processed_data = processor.preprocess();
    let calculator = new Optimizer(processor.calculate(processed_data));
    let optimized_result = calculator.optimize();
    let analyzer = new TerminationAnalyzer(optimized_result);
    let analysis_result = analyzer.analyze();
    console.log(analysis_result);
}

main();