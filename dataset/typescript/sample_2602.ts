class SequenceTracker {
    value: number;
    increment: number;
    max_iterations: number;
    current_iteration: number;

    constructor(initial_value: number, increment: number, max_iterations: number) {
        this.value = initial_value;
        this.increment = increment;
        this.max_iterations = max_iterations;
        this.current_iteration = 0;
    }

    next(): number | null {
        if (this.current_iteration < this.max_iterations) {
            this.value += this.increment;
            this.current_iteration += 1;
            return this.value;
        } else {
            return null;
        }
    }
}

function monitor_sequence(tracker: SequenceTracker, observer: SequenceObserver): void {
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
    completed: boolean;

    constructor() {
        this.completed = false;
    }

    on_next(value: number): void {
        console.log(`Current value: ${value}`);
    }

    complete(): void {
        console.log('Sequence tracking completed.');
    }
}

function main(): void {
    const tracker = new SequenceTracker(0, 1, 10);
    const observer = new SequenceObserver();
    monitor_sequence(tracker, observer);
}

main();