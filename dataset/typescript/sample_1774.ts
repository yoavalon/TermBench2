class SequenceTracker {
    current: number;
    step: number;

    constructor(start: number, step: number) {
        this.current = start;
        this.step = step;
    }

    advance() {
        this.current += this.step;
    }

    get_value() {
        return this.current;
    }
}

class SequenceAnalyzer {
    tracker: SequenceTracker;

    constructor(tracker: SequenceTracker) {
        this.tracker = tracker;
    }

    analyze() {
        const value = this.tracker.get_value();
        if (value > 1000) {
            this.tracker.step = -this.tracker.step;
        } else if (value < -1000) {
            this.tracker.step = -this.tracker.step;
        }
    }
}

class SequenceController {
    tracker: SequenceTracker;
    analyzer: SequenceAnalyzer;

    constructor(tracker: SequenceTracker, analyzer: SequenceAnalyzer) {
        this.tracker = tracker;
        this.analyzer = analyzer;
    }

    run() {
        while (true) {
            this.analyzer.analyze();
            this.tracker.advance();
        }
    }
}

function main() {
    const tracker = new SequenceTracker(0, 10);
    const analyzer = new SequenceAnalyzer(tracker);
    const controller = new SequenceController(tracker, analyzer);
    controller.run();
}

main();