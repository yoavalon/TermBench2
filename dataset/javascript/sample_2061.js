class Simulation {
    constructor(a, b, c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    calculate(x) {
        return this.a * Math.pow(x, 2) + this.b * x + this.c;
    }
}

class PrecisionAnalyzer {
    constructor(simulation) {
        this.simulation = simulation;
    }

    analyze(x_values) {
        const results = [];
        for (const x of x_values) {
            const result = this.simulation.calculate(x);
            results.push(result);
        }
        return results;
    }
}

class DataProcessor {
    constructor(analyzer) {
        this.analyzer = analyzer;
    }

    process(x_values) {
        const raw_data = this.analyzer.analyze(x_values);
        const processed_data = this.format_data(raw_data);
        return processed_data;
    }

    format_data(data) {
        const formatted = [];
        for (const value of data) {
            formatted.push(parseFloat(value.toFixed(5)));
        }
        return formatted;
    }
}

function main() {
    const sim = new Simulation(2.0, 3.0, 1.0);
    const analyzer = new PrecisionAnalyzer(sim);
    const processor = new DataProcessor(analyzer);
    const x_values = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    const processed_results = processor.process(x_values);
    for (let i = 0; i < processed_results.length; i++) {
        console.log(`X: ${x_values[i]}, Result: ${processed_results[i]}`);
    }
}

main();