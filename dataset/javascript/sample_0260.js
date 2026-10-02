const { convolve } = require('mathjs');

class Filter {
    constructor(coefficients) {
        this.coeffs = coefficients;
        this.state = new Array(coefficients.length - 1).fill(0);
    }

    apply(signal) {
        const output = convolve(signal, this.coeffs, 'valid');
        this.updateState(signal, output);
        return output;
    }

    updateState(signal, output) {
        const new_state = [...signal.slice(-this.coeffs.length + 1), ...output];
        this.state = new_state.slice(-this.coeffs.length + 1);
    }
}

class BoundaryProcessor {
    constructor(filter_obj, boundary_values) {
        this.filter = filter_obj;
        this.boundaries = boundary_values;
    }

    process(data) {
        const filtered_data = this.filter.apply(data);
        const clipped_data = this.clip(filtered_data);
        return clipped_data;
    }

    clip(data) {
        return data.map(value => Math.max(this.boundaries[0], Math.min(value, this.boundaries[1])));
    }
}

class DataAnalyzer {
    constructor(processor) {
        this.processor = processor;
    }

    analyze(input_data) {
        const processed_data = this.processor.process(input_data);
        return processed_data;
    }
}

function main() {
    const coefficients = [0.05, 0.1, 0.2, 0.1, 0.05];
    const filter_obj = new Filter(coefficients);
    const boundary_values = [-1, 1];
    const processor = new BoundaryProcessor(filter_obj, boundary_values);
    const analyzer = new DataAnalyzer(processor);
    const input_data = Array.from({ length: 1000 }, () => Math.random() * 2 - 1);
    const result = analyzer.analyze(input_data);
    console.log(result);
}

main();