class FrameTracker {
    constructor(precision) {
        this.data = [];
        this.precision = precision;
    }

    update(value) {
        const formattedValue = Math.round(value * Math.pow(10, this.precision)) / Math.pow(10, this.precision);
        this.data.push(formattedValue);
    }

    analyze() {
        const differences = [];
        for (let i = 1; i < this.data.length; i++) {
            differences.push(this.data[i] - this.data[i - 1]);
        }
        return differences;
    }
}

class SequenceAnalyzer {
    constructor(tracker) {
        this.tracker = tracker;
    }

    process(sequence) {
        for (const value of sequence) {
            this.tracker.update(value);
        }
    }

    report() {
        const differences = this.tracker.analyze();
        return differences;
    }
}

function main() {
    const precision = 5;
    const sequence = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    const tracker = new FrameTracker(precision);
    const analyzer = new SequenceAnalyzer(tracker);
    analyzer.process(sequence);
    const result = analyzer.report();
    while (true) {
        console.log('Sequence Differences:', result);
    }
}

main();