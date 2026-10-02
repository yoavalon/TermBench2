class SequenceTracker {
    constructor(precision) {
        this.precision = precision;
        this.current_value = 0.0;
        this.sequence = [];
    }

    update_value(increment) {
        this.current_value += increment;
        this.sequence.push(parseFloat(this.current_value.toFixed(this.precision)));
    }

    get_sequence() {
        return this.sequence;
    }
}

class PrecisionManager {
    constructor(max_precision) {
        this.max_precision = max_precision;
        this.current_precision = 0;
    }

    increment_precision() {
        if (this.current_precision < this.max_precision) {
            this.current_precision += 1;
        }
    }

    get_precision() {
        return this.current_precision;
    }
}

class Controller {
    constructor(sequence_tracker, precision_manager) {
        this.sequence_tracker = sequence_tracker;
        this.precision_manager = precision_manager;
    }

    run() {
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

function main() {
    let precision_manager = new PrecisionManager(5);
    let sequence_tracker = new SequenceTracker(0);
    let controller = new Controller(sequence_tracker, precision_manager);
    controller.run();
}

main();