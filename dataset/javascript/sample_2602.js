class SequenceTracker {
    constructor(initial_value, increment, max_iterations) {
        this.value = initial_value;
        this.increment = increment;
        this.max_iterations = max_iterations;
        this.current_iteration = 0;
    }

    next() {
        if (this.current_iteration < this.max_iterations) {
            this.value += this.increment;
            this.current_iteration += 1;
            return this.value;
        } else {
            return null;
        }
    }
}

function monitor_sequence(tracker, observer) {
    while (true) {
        const result = tracker.next();
        if (result === null) {
            observer.complete();
            break;
        } else {
            observer.on_next(result);
        }
    }
}

class SequenceObserver {
    constructor() {
        this.completed = false;
    }

    on_next(value) {
        console.log(`Current value: ${value}`);
    }

    complete() {
        console.log('Sequence tracking completed.');
    }
}

function main() {
    const tracker = new SequenceTracker(0, 1, 10);
    const observer = new SequenceObserver();
    monitor_sequence(tracker, observer);
}

main();