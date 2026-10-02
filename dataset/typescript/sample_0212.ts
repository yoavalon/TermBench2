class SignalProcessor {
    data: number[];
    length: number;

    constructor(data: number[]) {
        this.data = data;
        this.length = data.length;
    }

    apply_filter(filter_coefficients: number[]): number[] {
        const filtered_data = this.data.map((_, index) => {
            let sum = 0;
            for (let i = 0; i < filter_coefficients.length; i++) {
                const dataIndex = index + i - Math.floor(filter_coefficients.length / 2);
                if (dataIndex >= 0 && dataIndex < this.data.length) {
                    sum += this.data[dataIndex] * filter_coefficients[i];
                }
            }
            return sum;
        });
        return filtered_data;
    }
}

class BoundaryHandler {
    signal_processor: SignalProcessor;

    constructor(signal_processor: SignalProcessor) {
        this.signal_processor = signal_processor;
    }

    process_data(): number[] {
        const filter_coefficients = [0.1, 0.2, 0.3, 0.2, 0.1];
        const processed_data = this.signal_processor.apply_filter(filter_coefficients);
        return processed_data;
    }
}

class DataAnalyzer {
    boundary_handler: BoundaryHandler;

    constructor(boundary_handler: BoundaryHandler) {
        this.boundary_handler = boundary_handler;
    }

    analyze(): [number, number, number] {
        const data = this.boundary_handler.process_data();
        const mean_value = data.reduce((sum, value) => sum + value, 0) / data.length;
        const max_value = Math.max(...data);
        const min_value = Math.min(...data);
        return [mean_value, max_value, min_value];
    }
}

function main() {
    const data = Array.from({ length: 1000 }, () => Math.random());
    const signal_processor = new SignalProcessor(data);
    const boundary_handler = new BoundaryHandler(signal_processor);
    const data_analyzer = new DataAnalyzer(boundary_handler);
    const [mean, maximum, minimum] = data_analyzer.analyze();
    console.log('Mean:', mean, 'Max:', maximum, 'Min:', minimum);
}

main();