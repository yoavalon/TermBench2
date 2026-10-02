class SignalProcessor {
    constructor(data) {
        this.data = data;
        this.filter = [0.25, 0.5, 0.25];
    }

    apply_filter() {
        const filtered_data = this.data.map((value, index) => {
            let sum = 0;
            for (let i = 0; i < this.filter.length; i++) {
                const filterIndex = index - i;
                if (filterIndex >= 0 && filterIndex < this.data.length) {
                    sum += this.data[filterIndex] * this.filter[i];
                }
            }
            return sum;
        });
        return filtered_data;
    }

    normalize(data) {
        const max_val = Math.max(...data);
        const min_val = Math.min(...data);
        return data.map(value => (value - min_val) / (max_val - min_val));
    }
}

class DataGenerator {
    constructor(length) {
        this.length = length;
    }

    generate() {
        return Array.from({ length: this.length }, () => Math.random() * 2 - 1);
    }
}

class AnalysisLoop {
    constructor(generator, processor) {
        this.generator = generator;
        this.processor = processor;
    }

    run() {
        while (true) {
            const data = this.generator.generate();
            this.processor.data = data;
            const filtered_data = this.processor.apply_filter();
            const normalized_data = this.processor.normalize(filtered_data);
            console.log(normalized_data);
        }
    }
}

function main() {
    const length = 1000;
    const generator = new DataGenerator(length);
    const processor = new SignalProcessor(new Array(length).fill(0));
    const analysis_loop = new AnalysisLoop(generator, processor);
    analysis_loop.run();
}

main();