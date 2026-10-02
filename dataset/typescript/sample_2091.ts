class FrameTracker {
    sequence: number[];
    current_index: number;

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.current_index = 0;
    }

    next_frame(): number | null {
        if (this.current_index < this.sequence.length) {
            const frame = this.sequence[this.current_index];
            this.current_index += 1;
            return frame;
        } else {
            return null;
        }
    }

    reset(): void {
        this.current_index = 0;
    }
}

class SequenceAnalyzer {
    tracker: FrameTracker;

    constructor(tracker: FrameTracker) {
        this.tracker = tracker;
    }

    analyze(): void {
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
    analyzer: SequenceAnalyzer;

    constructor(analyzer: SequenceAnalyzer) {
        this.analyzer = analyzer;
    }

    process(): void {
        this.analyzer.analyze();
    }
}

function main(): void {
    const sequence = [1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9];
    const tracker = new FrameTracker(sequence);
    const analyzer = new SequenceAnalyzer(tracker);
    const processor = new FrameProcessor(analyzer);
    processor.process();
}

main();