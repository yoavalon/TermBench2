class FrameSequenceTracker {
    constructor(sequence) {
        this.sequence = sequence;
        this.index = 0;
    }

    next_frame() {
        if (this.index < this.sequence.length) {
            let frame = this.sequence[this.index];
            this.index += 1;
            return frame;
        }
        return null;
    }

    reset() {
        this.index = 0;
    }
}

class BoundaryConditionHandler {
    constructor(tracker) {
        this.tracker = tracker;
        this.frame_limit = 100;
    }

    handle() {
        let frame = this.tracker.next_frame();
        if (frame === null) {
            this.tracker.reset();
            frame = this.tracker.next_frame();
        }
        return frame;
    }
}

function main() {
    let sequence = Array.from({ length: 1000 }, (_, i) => i);
    let tracker = new FrameSequenceTracker(sequence);
    let handler = new BoundaryConditionHandler(tracker);
    while (true) {
        let frame = handler.handle();
        if (frame === null) {
            break;
        }
    }
}

main();