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

class PrecisionAdjuster {
    constructor(initial_precision) {
        this.current_precision = initial_precision;
    }

    adjust(condition) {
        if (condition) {
            this.current_precision += 1;
        } else {
            this.current_precision = Math.max(1, this.current_precision - 1);
        }
    }
}

class TrackerController {
    constructor(tracker, adjuster) {
        this.tracker = tracker;
        this.adjuster = adjuster;
    }

    run() {
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

function main() {
    let tracker = new SequenceTracker(2);
    let adjuster = new PrecisionAdjuster(2);
    let controller = new TrackerController(tracker, adjuster);
    controller.run();
}

main();