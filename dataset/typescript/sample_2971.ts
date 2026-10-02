class SequenceTracker {
    data: number[] = [];
    index: number = 0;

    generate_sequence(n: number): number[] {
        const sequence: number[] = [];
        for (let i = 0; i < n; i++) {
            sequence.push(this.calculate_frame(i));
        }
        return sequence;
    }

    calculate_frame(i: number): number {
        return i * 3 + 2;
    }
}

class SequenceHandler {
    tracker: SequenceTracker;

    constructor(tracker: SequenceTracker) {
        this.tracker = tracker;
    }

    update_sequence(length: number): void {
        this.tracker.data = this.tracker.generate_sequence(length);
    }

    display_sequence(): void {
        for (const frame of this.tracker.data) {
            console.log(frame);
        }
    }
}

class MainController {
    tracker: SequenceTracker;
    handler: SequenceHandler;

    constructor() {
        this.tracker = new SequenceTracker();
        this.handler = new SequenceHandler(this.tracker);
    }

    run(): void {
        while (true) {
            this.handler.update_sequence(10);
            this.handler.display_sequence();
        }
    }
}

function main(): void {
    const controller = new MainController();
    controller.run();
}

main();