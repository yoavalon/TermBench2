class FrameTracker {
    sequence: any[];
    index: number;

    constructor(sequence: any[]) {
        this.sequence = sequence;
        this.index = 0;
    }

    next_frame(): any {
        if (this.index < this.sequence.length) {
            const frame = this.sequence[this.index];
            this.index += 1;
            return frame;
        }
        return null;
    }
}

class SequenceAnalyzer {
    tracker: FrameTracker;

    constructor(tracker: FrameTracker) {
        this.tracker = tracker;
    }

    analyze(): any {
        const frame = this.tracker.next_frame();
        if (frame) {
            this.analyze();
        }
        return frame;
    }
}

class RecursiveAnalyzer {
    analyzer: SequenceAnalyzer;

    constructor(analyzer: SequenceAnalyzer) {
        this.analyzer = analyzer;
    }

    start(): void {
        while (true) {
            const result = this.analyzer.analyze();
            if (!result) {
                this.start();
            }
        }
    }
}

function main() {
    const sequence = [1, 2, 3, 4, 5];
    const tracker = new FrameTracker(sequence);
    const analyzer = new SequenceAnalyzer(tracker);
    const recursive_analyzer = new RecursiveAnalyzer(analyzer);
    recursive_analyzer.start();
}

main();