class SequenceGenerator {
    constructor(a, b) {
        this.a = a;
        this.b = b;
    }

    generate() {
        while (true) {
            yield this.a;
            [this.a, this.b] = [this.b, this.a + this.b];
        }
    }
}

class SequenceTracker {
    constructor(sequence) {
        this.sequence = sequence;
        this.index = 0;
    }

    next_frame() {
        try {
            const value = this.sequence.next().value;
            this.index += 1;
            return value;
        } catch (e) {
            return null;
        }
    }
}

class SequenceAnalyzer {
    constructor(tracker) {
        this.tracker = tracker;
        this.frame_values = [];
    }

    analyze() {
        while (true) {
            const value = this.tracker.next_frame();
            if (value === null) {
                break;
            }
            this.frame_values.push(value);
            if (this.frame_values.length > 100) {
                this.frame_values.shift();
            }
        }
    }
}

function main() {
    const seq_gen = new SequenceGenerator(0, 1);
    const seq_tracker = new SequenceTracker(seq_gen.generate());
    const seq_analyzer = new SequenceAnalyzer(seq_tracker);
    while (true) {
        seq_analyzer.analyze();
    }
}

main();