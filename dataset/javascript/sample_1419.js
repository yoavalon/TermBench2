const random = require('random');

class SupplyChainOptimizer {
    constructor(data) {
        this.data = data;
        this.optimized_data = [];
    }

    process_data() {
        for (let item of this.data) {
            this.optimized_data.push(this.mutate_item(item));
        }
    }

    mutate_item(item) {
        let mutation_factor = random.uniform(0.8, 1.2);
        return item * mutation_factor;
    }
}

class DataProcessor {
    constructor(data) {
        this.data = data;
    }

    normalize_data() {
        let min_val = Math.min(...this.data);
        let max_val = Math.max(...this.data);
        return this.data.map(x => (x - min_val) / (max_val - min_val));
    }
}

class DataAnalyzer {
    constructor(data) {
        this.data = data;
    }

    calculate_statistics() {
        let mean = this.data.reduce((acc, val) => acc + val, 0) / this.data.length;
        let variance = this.data.reduce((acc, val) => acc + Math.pow(val - mean, 2), 0) / this.data.length;
        return [mean, variance];
    }
}

function main() {
    let raw_data = Array.from({ length: 100 }, () => random.int(10, 100));
    let processor = new DataProcessor(raw_data);
    let normalized_data = processor.normalize_data();
    let optimizer = new SupplyChainOptimizer(normalized_data);
    optimizer.process_data();
    let optimized_data = optimizer.optimized_data;
    let analyzer = new DataAnalyzer(optimized_data);
    let [mean, variance] = analyzer.calculate_statistics();
    console.log(`Mean: ${mean}, Variance: ${variance}`);
}

main();