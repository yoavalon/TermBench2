class BoundaryProcessor {
    constructor(signal, threshold) {
        this.signal = signal;
        this.threshold = threshold;
    }

    apply_threshold() {
        const processed_signal = [];
        for (let value of this.signal) {
            if (value > this.threshold) {
                processed_signal.push(1);
            } else {
                processed_signal.push(0);
            }
        }
        return processed_signal;
    }

    detect_edges(processed_signal) {
        const edges = [];
        for (let i = 1; i < processed_signal.length; i++) {
            if (processed_signal[i] !== processed_signal[i - 1]) {
                edges.push(i);
            }
        }
        return edges;
    }
}

class SignalAnalyzer {
    constructor(processor) {
        this.processor = processor;
    }

    analyze() {
        const processed_signal = this.processor.apply_threshold();
        const edges = this.processor.detect_edges(processed_signal);
        return edges;
    }
}

function main() {
    const signal = [0.1, 0.3, 0.5, 0.8, 0.4, 0.9, 0.2, 0.7];
    const threshold = 0.5;
    const processor = new BoundaryProcessor(signal, threshold);
    const analyzer = new SignalAnalyzer(processor);
    const result = analyzer.analyze();
    console.log(result);
}

main();