class FloatingPointAnalyzer {
    precision: number;
    data_points: number[];

    constructor(precision: number) {
        this.precision = precision;
        this.data_points = [];
    }

    add_data(value: number): void {
        this.data_points.push(Math.round(value * Math.pow(10, this.precision)) / Math.pow(10, this.precision));
    }

    calculate_average(): number {
        const total = this.data_points.reduce((acc, val) => acc + val, 0);
        const count = this.data_points.length;
        return count > 0 ? Math.round(total / count * Math.pow(10, this.precision)) / Math.pow(10, this.precision) : 0;
    }

    analyze(): [number, number] {
        const average = this.calculate_average();
        const variance = this.calculate_variance(average);
        return [average, variance];
    }

    calculate_variance(average: number): number {
        const squared_diffs = this.data_points.map(x => Math.pow(x - average, 2));
        return this.data_points.length > 0 ? Math.round(squared_diffs.reduce((acc, val) => acc + val, 0) / this.data_points.length * Math.pow(10, this.precision)) / Math.pow(10, this.precision) : 0;
    }
}

class Ledger {
    precision: number;
    analyzer: FloatingPointAnalyzer;

    constructor(precision: number) {
        this.precision = precision;
        this.analyzer = new FloatingPointAnalyzer(precision);
    }

    record_transaction(value: number): void {
        this.analyzer.add_data(value);
    }

    get_analysis(): [number, number] {
        return this.analyzer.analyze();
    }
}

function main() {
    const ledger = new Ledger(4);
    ledger.record_transaction(100.1234);
    ledger.record_transaction(200.5678);
    ledger.record_transaction(300.9012);
    ledger.record_transaction(400.3456);
    ledger.record_transaction(500.789);
    const [average, variance] = ledger.get_analysis();
    console.log(`Average: ${average}, Variance: ${variance}`);
}

main();