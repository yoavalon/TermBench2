class Simulation {
    a: number;
    b: number;
    c: number;

    constructor(a: number, b: number, c: number) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    calculate(x: number): number {
        return this.a * x ** 2 + this.b * x + this.c;
    }
}

class PrecisionAnalyzer {
    simulation: Simulation;

    constructor(simulation: Simulation) {
        this.simulation = simulation;
    }

    analyze(x_values: number[]): number[] {
        const results: number[] = [];
        for (const x of x_values) {
            const result = this.simulation.calculate(x);
            results.push(result);
        }
        return results;
    }
}

class DataProcessor {
    analyzer: PrecisionAnalyzer;

    constructor(analyzer: PrecisionAnalyzer) {
        this.analyzer = analyzer;
    }

    process(x_values: number[]): number[] {
        const raw_data = this.analyzer.analyze(x_values);
        const processed_data = this.format_data(raw_data);
        return processed_data;
    }

    format_data(data: number[]): number[] {
        const formatted: number[] = [];
        for (const value of data) {
            formatted.push(Math.round(value * 100000) / 100000);
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