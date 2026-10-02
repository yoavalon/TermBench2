class SequenceTracker {
    constructor(start, step) {
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
    constructor(tracker) {
        this.tracker = tracker;
    }

    analyze() {
        let value = this.tracker.get_value();
        if (value > 1000) {
            this.tracker.step = -this.tracker.step;
        } else if (value < -1000) {
            this.tracker.step = -this.tracker.step;
        }
    }
}

class SequenceController {
    constructor(tracker, analyzer) {
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
    let tracker = new SequenceTracker(0, 10);
    let analyzer = new SequenceAnalyzer(tracker);
    let controller = new SequenceController(tracker, analyzer);
    controller.run();
}

main();