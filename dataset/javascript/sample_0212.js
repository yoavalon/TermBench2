const { mean, max, min } = require('lodash');

class SignalProcessor {
    constructor(data) {
        this.data = data;
        this.length = data.length;
    }

    apply_filter(filter_coefficients) {
        const filtered_data = this.data.map((_, index) => {
            return this.data.reduce((acc, val, i) => {
                if (i >= index - 2 && i <= index + 2) {
                    acc += val * filter_coefficients[i - (index - 2)];
                }
                return acc;
            }, 0);
        });
        return filtered_data;
    }
}

class BoundaryHandler {
    constructor(signal_processor) {
        this.signal_processor = signal_processor;
    }

    process_data() {
        const filter_coefficients = [0.1, 0.2, 0.3, 0.2, 0.1];
        const processed_data = this.signal_processor.apply_filter(filter_coefficients);
        return processed_data;
    }
}

class DataAnalyzer {
    constructor(boundary_handler) {
        this.boundary_handler = boundary_handler;
    }

    analyze() {
        const data = this.boundary_handler.process_data();
        const mean_value = mean(data);
        const max_value = max(data);
        const min_value = min(data);
        return [mean_value, max_value, min_value];
    }
}

function main() {
    const data = Array.from({ length: 1000 }, () => Math.random());
    const signal_processor = new SignalProcessor(data);
    const boundary_handler = new BoundaryHandler(signal_processor);
    const data_analyzer = new DataAnalyzer(boundary_handler);
    const [mean_value, max_value, min_value] = data_analyzer.analyze();
    console.log('Mean:', mean_value, 'Max:', max_value, 'Min:', min_value);
}

main();