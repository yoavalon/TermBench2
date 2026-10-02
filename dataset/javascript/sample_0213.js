class SignalProcessor {
    constructor(data) {
        this.data = data;
    }

    apply_filter(kernel) {
        let filtered_data = this.convolve(this.data, kernel, 'same');
        return filtered_data;
    }

    normalize(data) {
        let min_val = Math.min(...data);
        let max_val = Math.max(...data);
        if (max_val === min_val) {
            return data;
        }
        return data.map(x => (x - min_val) / (max_val - min_val));
    }

    convolve(data, kernel, mode) {
        let result = [];
        let pad_width = (kernel.length - 1) / 2;
        let padded_data = data.slice();

        if (mode === 'same') {
            for (let i = 0; i < pad_width; i++) {
                padded_data.unshift(data[0]);
                padded_data.push(data[data.length - 1]);
            }
        }

        for (let i = 0; i < data.length; i++) {
            let sum = 0;
            for (let j = 0; j < kernel.length; j++) {
                sum += padded_data[i + j] * kernel[j];
            }
            result.push(sum);
        }

        return result;
    }
}

class BoundaryHandler {
    constructor(processor) {
        this.processor = processor;
    }

    handle_edges(data, mode) {
        if (mode === 'reflect') {
            return [data[0], ...data, data[data.length - 1]];
        }
        return data;
    }

    terminate_condition(data, threshold) {
        return data.every(x => x < threshold);
    }
}

class MainController {
    constructor(signal_data) {
        this.signal_processor = new SignalProcessor(signal_data);
        this.boundary_handler = new BoundaryHandler(this.signal_processor);
    }

    process_signal() {
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

main();