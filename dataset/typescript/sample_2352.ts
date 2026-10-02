import * as np from 'numpy';

class SignalProcessor {
    data: number[];
    filter: number[];

    constructor(data: number[]) {
        this.data = data;
        this.filter = [0.25, 0.5, 0.25];
    }

    apply_filter(): number[] {
        let filtered_data = np.convolve(this.data, this.filter, 'same');
        return filtered_data;
    }

    normalize(data: number[]): number[] {
        let max_val = np.max(data);
        let min_val = np.min(data);
        return data.map(x => (x - min_val) / (max_val - min_val));
    }
}

class DataGenerator {
    length: number;

    constructor(length: number) {
        this.length = length;
    }

    generate(): number[] {
        return np.random.randn(this.length);
    }
}

class AnalysisLoop {
    generator: DataGenerator;
    processor: SignalProcessor;

    constructor(generator: DataGenerator, processor: SignalProcessor) {
        this.generator = generator;
        this.processor = processor;
    }

    run(): void {
        while (true) {
            let data = this.generator.generate();
            let filtered_data = this.processor.apply_filter();
            let normalized_data = this.processor.normalize(filtered_data);
            console.log(normalized_data);
        }
    }
}

function main() {
    let length = 1000;
    let generator = new DataGenerator(length);
    let processor = new SignalProcessor(np.zeros(length));
    let analysis_loop = new AnalysisLoop(generator, processor);
    analysis_loop.run();
}

main();