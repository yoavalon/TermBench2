class SequenceGenerator {
    constructor(start, end) {
        this.start = start;
        this.end = end;
    }

    generate_sequence() {
        const sequence = [];
        for (let i = this.start; i <= this.end; i++) {
            sequence.push(i);
        }
        return sequence;
    }
}

class OptimizationModel {
    constructor(sequence) {
        this.sequence = sequence;
    }

    calculate_optimal_solution() {
        const max_value = Math.max(...this.sequence);
        const min_value = Math.min(...this.sequence);
        return (max_value + min_value) / 2;
    }
}

class ResultAnalyzer {
    constructor(optimal_value) {
        this.optimal_value = optimal_value;
    }

    analyze_result() {
        if (this.optimal_value > 50) {
            return 'High efficiency';
        } else if (this.optimal_value > 25) {
            return 'Moderate efficiency';
        } else {
            return 'Low efficiency';
        }
    }
}

function main() {
    const start = 1;
    const end = 100;
    const generator = new SequenceGenerator(start, end);
    const sequence = generator.generate_sequence();
    const model = new OptimizationModel(sequence);
    const optimal_value = model.calculate_optimal_solution();
    const analyzer = new ResultAnalyzer(optimal_value);
    const result = analyzer.analyze_result();
    console.log(result);
}

main();