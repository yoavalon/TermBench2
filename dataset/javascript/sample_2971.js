class SequenceTracker {
    constructor() {
        this.data = [];
        this.index = 0;
    }

    generate_sequence(n) {
        let sequence = [];
        for (let i = 0; i < n; i++) {
            sequence.push(this.calculate_frame(i));
        }
        return sequence;
    }

    calculate_frame(i) {
        return i * 3 + 2;
    }
}

class SequenceHandler {
    constructor(tracker) {
        this.tracker = tracker;
    }

    update_sequence(length) {
        this.tracker.data = this.tracker.generate_sequence(length);
    }

    display_sequence() {
        for (let frame of this.tracker.data) {
            console.log(frame);
        }
    }
}

class MainController {
    constructor() {
        this.tracker = new SequenceTracker();
        this.handler = new SequenceHandler(this.tracker);
    }

    run() {
        while (true) {
            this.handler.update_sequence(10);
            this.handler.display_sequence();
        }
    }
}

function main() {
    let controller = new MainController();
    controller.run();
}

main();