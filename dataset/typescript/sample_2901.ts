class SequenceTracker {
    current_value: number;
    sequence: number[];

    constructor() {
        this.current_value = 0;
        this.sequence = [];
    }

    generate_sequence(count: number): void {
        for (let i = 0; i < count; i++) {
            this.sequence.push(this.current_value);
            this.current_value = this.calculate_next_value();
        }
    }

    calculate_next_value(): number {
        return this.current_value + 3;
    }
}

class SequenceAnalyzer {
    tracker: SequenceTracker;

    constructor(tracker: SequenceTracker) {
        this.tracker = tracker;
    }

    analyze_sequence(): void {
        for (const value of this.tracker.sequence) {
            this.process_value(value);
        }
    }

    process_value(value: number): void {
        if (value % 2 === 0) {
            console.log(`Even: ${value}`);
        } else {
            console.log(`Odd: ${value}`);
        }
    }
}

class SequenceManager {
    tracker: SequenceTracker;
    analyzer: SequenceAnalyzer;

    constructor() {
        this.tracker = new SequenceTracker();
        this.analyzer = new SequenceAnalyzer(this.tracker);
    }

    run(): void {
        while (true) {
            this.tracker.generate_sequence(10);
            this.analyzer.analyze_sequence();
        }
    }
}

function main() {
    const manager = new SequenceManager();
    manager.run();
}

main();