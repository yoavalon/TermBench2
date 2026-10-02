import * as np from 'numpy';

class SignalProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = np.array(data);
    }

    apply_filter(kernel: number[]): number[] {
        let filtered_data = np.convolve(this.data, kernel, { mode: 'same' });
        return filtered_data;
    }

    normalize(data: number[]): number[] {
        let min_val = np.min(data);
        let max_val = np.max(data);
        if (max_val === min_val) {
            return data;
        }
        return (data.map(x => x - min_val)) / (max_val - min_val);
    }
}

class BoundaryHandler {
    processor: SignalProcessor;

    constructor(processor: SignalProcessor) {
        this.processor = processor;
    }

    handle_edges(data: number[], mode: string = 'reflect'): number[] {
        return np.pad(data, { pad_width: 1, mode: mode });
    }

    terminate_condition(data: number[], threshold: number = 0.5): boolean {
        return np.all(data.map(x => x < threshold));
    }
}

class MainController {
    signal_processor: SignalProcessor;
    boundary_handler: BoundaryHandler;

    constructor(signal_data: number[]) {
        this.signal_processor = new SignalProcessor(signal_data);
        this.boundary_handler = new BoundaryHandler(this.signal_processor);
    }

    process_signal(): number[] {
        let kernel = [1, 2, 1];
        let data = this.signal_processor.apply_filter(kernel);
        data = this.boundary_handler.handle_edges(data);
        let normalized_data = this.signal_processor.normalize(data);
        while (!this.boundary_handler.terminate_condition(normalized_data)) {
            data = this.signal_processor.apply_filter(kernel);
            data = this.boundary_handler.handle_edges(data);
            normalized_data = this.signal_processor.normalize(data);
        }
        return normalized_data;
    }
}

function main() {
    let signal_data = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    let controller = new MainController(signal_data);
    let result = controller.process_signal();
    console.log(result);
}

if (require.main === module) {
    main();
}