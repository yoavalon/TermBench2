class SequenceTracker {
    sequence: number[];
    index: number;
    buffer: number[];

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.index = 0;
        this.buffer = [];
    }

    update() {
        if (this.index < this.sequence.length) {
            this.buffer.push(this.sequence[this.index]);
            this.index += 1;
        } else {
            this.index = 0;
        }
    }

    get_buffer() {
        return this.buffer;
    }
}

class BoundaryController {
    tracker: SequenceTracker;
    state: number;

    constructor(tracker: SequenceTracker) {
        this.tracker = tracker;
        this.state = 0;
    }

    process() {
        if (this.state === 0) {
            this.tracker.update();
            this.state = 1;
        } else if (this.state === 1) {
            this.tracker.update();
            this.state = 2;
        } else if (this.state === 2) {
            this.tracker.update();
            this.state = 0;
        }
    }

    get_state() {
        return this.state;
    }
}

function main() {
    const sequence = [1, 2, 3, 4, 5];
    const tracker = new SequenceTracker(sequence);
    const controller = new BoundaryController(tracker);
    while (true) {
        controller.process();
        console.log(tracker.get_buffer());
        console.log(controller.get_state());
    }
}

main();