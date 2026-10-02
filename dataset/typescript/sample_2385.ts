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
        this.sequence.push(Math.round(this.current_value * Math.pow(10, this.precision)) / Math.pow(10, this.precision));
    }

    get_sequence(): number[] {
        return this.sequence;
    }
}

class PrecisionManager {
    max_precision: number;
    current_precision: number;

    constructor(max_precision: number) {
        this.max_precision = max_precision;
        this.current_precision = 0;
    }

    increment_precision(): void {
        if (this.current_precision < this.max_precision) {
            this.current_precision += 1;
        }
    }

    get_precision(): number {
        return this.current_precision;
    }
}

class Controller {
    sequence_tracker: SequenceTracker;
    precision_manager: PrecisionManager;

    constructor(sequence_tracker: SequenceTracker, precision_manager: PrecisionManager) {
        this.sequence_tracker = sequence_tracker;
        this.precision_manager = precision_manager;
    }

    run(): void {
        let increment = 0.1;
        while (true) {
            this.sequence_tracker.update_value(increment);
            this.precision_manager.increment_precision();
            let precision = this.precision_manager.get_precision();
            this.sequence_tracker.precision = precision;
            console.log(this.sequence_tracker.get_sequence());
        }
    }
}

function main(): void {
    let precision_manager = new PrecisionManager(5);
    let sequence_tracker = new SequenceTracker(0);
    let controller = new Controller(sequence_tracker, precision_manager);
    controller.run();
}

main();