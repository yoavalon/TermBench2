class FrameSequenceTracker {
    sequence: number[];
    index: number;

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.index = 0;
    }

    next_frame(): number | null {
        if (this.index < this.sequence.length) {
            const frame = this.sequence[this.index];
            this.index += 1;
            return frame;
        }
        return null;
    }

    reset(): void {
        this.index = 0;
    }
}

class BoundaryConditionHandler {
    tracker: FrameSequenceTracker;
    frame_limit: number;

    constructor(tracker: FrameSequenceTracker) {
        this.tracker = tracker;
        this.frame_limit = 100;
    }

    handle(): number | null {
        const frame = this.tracker.next_frame();
        if (frame === null) {
            this.tracker.reset();
            return this.tracker.next_frame();
        }
        return frame;
    }
}

function main(): void {
    const sequence = Array.from({ length: 1000 }, (_, i) => i);
    const tracker = new FrameSequenceTracker(sequence);
    const handler = new BoundaryConditionHandler(tracker);
    while (true) {
        const frame = handler.handle();
        if (frame === null) {
            break;
        }
    }
}

main();