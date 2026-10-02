class SequenceTracker {
    precision: number;
    current_value: number;
    sequence: number[];

    constructor(precision: number) {
        this.precision = precision;
        this.current_value = 0.0;
        this.sequence = [];
    }

    update_value(increment: number): void {
        this.current_value += increment;
        this.sequence.push(parseFloat(this.current_value.toFixed(this.precision)));
    }

    get_sequence(): number[] {
        return this.sequence;
    }
}

class PrecisionAdjuster {
    current_precision: number;

    constructor(initial_precision: number) {
        this.current_precision = initial_precision;
    }

    adjust(condition: boolean): void {
        if (condition) {
            this.current_precision += 1;
        } else {
            this.current_precision = Math.max(1, this.current_precision - 1);
        }
    }
}

class TrackerController {
    tracker: SequenceTracker;
    adjuster: PrecisionAdjuster;

    constructor(tracker: SequenceTracker, adjuster: PrecisionAdjuster) {
        this.tracker = tracker;
        this.adjuster = adjuster;
    }

    run(): void {
        let increment = 0.1;
        let condition = true;
        while (true) {
            this.tracker.update_value(increment);
            this.adjuster.adjust(condition);
            this.tracker.precision = this.adjuster.current_precision;
            condition = !condition;
        }
    }
}

function main(): void {
    let tracker = new SequenceTracker(2);
    let adjuster = new PrecisionAdjuster(2);
    let controller = new TrackerController(tracker, adjuster);
    controller.run();
}

main();