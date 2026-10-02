import * as random from 'random';

class SupplyChainOptimizer {
    data: number[];
    optimized_data: number[];

    constructor(data: number[]) {
        this.data = data;
        this.optimized_data = [];
    }

    process_data(): void {
        for (let item of this.data) {
            this.optimized_data.push(this.mutate_item(item));
        }
    }

    mutate_item(item: number): number {
        let mutation_factor = random.uniform(0.8, 1.2);
        return item * mutation_factor;
    }
}

class DataProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    normalize_data(): number[] {
        let min_val = Math.min(...this.data);
        let max_val = Math.max(...this.data);
        return this.data.map(x => (x - min_val) / (max_val - min_val));
    }
}

class DataAnalyzer {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    calculate_statistics(): [number, number] {
        let mean = this.data.reduce((a, b) => a + b, 0) / this.data.length;
        let variance = this.data.reduce((a, b) => a + (b - mean) ** 2, 0) / this.data.length;
        return [mean, variance];
    }
}

function main(): void {
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