class DataProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    process_data(): number[] {
        let processed: number[] = [];
        for (let item of this.data) {
            processed.push(this.adjust_precision(item));
        }
        return processed;
    }

    adjust_precision(value: number): number {
        return Math.round(value * 100000) / 100000;
    }
}

class SupplyChainOptimizer {
    processed_data: number[];

    constructor(processed_data: number[]) {
        this.processed_data = processed_data;
    }

    optimize(): number[] {
        let optimized_data: number[] = [];
        for (let item of this.processed_data) {
            optimized_data.push(this.calculate_cost(item));
        }
        return optimized_data;
    }

    calculate_cost(item: number): number {
        return item * 1.05;
    }
}

class ResultCompiler {
    optimized_data: number[];

    constructor(optimized_data: number[]) {
        this.optimized_data = optimized_data;
    }

    compile_results(): { [key: number]: number } {
        let result: { [key: number]: number } = {};
        for (let index = 0; index < this.optimized_data.length; index++) {
            result[index] = this.optimized_data[index];
        }
        return result;
    }
}

function main() {
    let raw_data: number[] = [100.123456, 200.654321, 300.987654, 400.135792, 500.24681];
    let processor = new DataProcessor(raw_data);
    let processed_data = processor.process_data();
    let optimizer = new SupplyChainOptimizer(processed_data);
    let optimized_data = optimizer.optimize();
    let compiler = new ResultCompiler(optimized_data);
    let results = compiler.compile_results();
    console.log(results);
}

main();