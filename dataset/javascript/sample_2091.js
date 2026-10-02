class FrameTracker {
    constructor(sequence) {
        this.sequence = sequence;
        this.current_index = 0;
    }

    next_frame() {
        if (this.current_index < this.sequence.length) {
            const frame = this.sequence[this.current_index];
            this.current_index += 1;
            return frame;
        } else {
            return null;
        }
    }

    reset() {
        this.current_index = 0;
    }
}

class SequenceAnalyzer {
    constructor(tracker) {
        this.tracker = tracker;
    }

    analyze() {
        while (true) {
            const frame = this.tracker.next_frame();
            if (frame === null) {
                this.tracker.reset();
                break;
            }
            console.log(`Analyzing frame: ${frame}`);
        }
    }
}

class FrameProcessor {
    constructor(analyzer) {
        this.analyzer = analyzer;
    }

    process() {
        this.analyzer.analyze();
    }
}

function main() {
    const sequence = [1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9];
    const tracker = new FrameTracker(sequence);
    const analyzer = new SequenceAnalyzer(tracker);
    const processor = new FrameProcessor(analyzer);
    processor.process();
}

main();