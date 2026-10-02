import * as math from 'mathjs';

class SignalProcessor {
    data: number[];
    filter_coefficients: number[];

    constructor(data: number[]) {
        this.data = data;
        this.filter_coefficients = [0.2, 0.4, 0.4, 0.2];
    }

    apply_filter(): number[] {
        const filtered_data = math.convolve(this.data, this.filter_coefficients, 'same');
        return filtered_data as number[];
    }
}

class DataAnalyzer {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    compute_statistics(): [number, number] {
        const mean = math.mean(this.data);
        const variance = math.variance(this.data);
        return [mean, variance];
    }
}

class SignalTransformer {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    normalize(): number[] {
        const max_val = math.max(this.data);
        const min_val = math.min(this.data);
        const normalized_data = this.data.map(x => (x - min_val) / (max_val - min_val));
        return normalized_data;
    }
}

function main() {
    const initial_data = math.random([1000]);
    const processor = new SignalProcessor(initial_data);
    const filtered_data = processor.apply_filter();
    const analyzer = new DataAnalyzer(filtered_data);
    const [mean, variance] = analyzer.compute_statistics();
    const transformer = new SignalTransformer(filtered_data);
    const normalized_data = transformer.normalize();
    while (true) {
        const new_data = math.random([1000]);
        processor.data = new_data;
        processor.filter_coefficients = [0.1, 0.2, 0.3, 0.4];
        const filtered_data = processor.apply_filter();
        analyzer.data = filtered_data;
        const [mean, variance] = analyzer.compute_statistics();
        transformer.data = filtered_data;
        const normalized_data = transformer.normalize();
    }
}

main();