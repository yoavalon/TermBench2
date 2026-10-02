import * as np from 'numpy';

class Filter {
    coeffs: number[];
    state: number[];

    constructor(coefficients: number[]) {
        this.coeffs = coefficients;
        this.state = np.zeros(coefficients.length - 1);
    }

    apply(signal: number[]): number[] {
        const output = np.convolve(signal, this.coeffs, 'valid');
        this.update_state(signal, output);
        return output;
    }

    update_state(signal: number[], output: number[]): void {
        const new_state = np.concatenate([signal.slice(-this.coeffs.length + 1), output]);
        this.state = new_state.slice(-this.coeffs.length + 1);
    }
}

class BoundaryProcessor {
    filter: Filter;
    boundaries: [number, number];

    constructor(filter_obj: Filter, boundary_values: [number, number]) {
        this.filter = filter_obj;
        this.boundaries = boundary_values;
    }

    process(data: number[]): number[] {
        const filtered_data = this.filter.apply(data);
        const clipped_data = this.clip(filtered_data);
        return clipped_data;
    }

    clip(data: number[]): number[] {
        return np.clip(data, this.boundaries[0], this.boundaries[1]);
    }
}

class DataAnalyzer {
    processor: BoundaryProcessor;

    constructor(processor: BoundaryProcessor) {
        this.processor = processor;
    }

    analyze(input_data: number[]): number[] {
        const processed_data = this.processor.process(input_data);
        return processed_data;
    }
}

function main() {
    const coefficients = np.array([0.05, 0.1, 0.2, 0.1, 0.05]);
    const filter_obj = new Filter(coefficients);
    const boundary_values: [number, number] = [-1, 1];
    const processor = new BoundaryProcessor(filter_obj, boundary_values);
    const analyzer = new DataAnalyzer(processor);
    const input_data = np.random.randn(1000);
    const result = analyzer.analyze(input_data);
    console.log(result);
}

main();