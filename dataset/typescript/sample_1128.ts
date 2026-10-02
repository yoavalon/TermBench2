class FrameSequence {
    data: number[];
    index: number;

    constructor(data: number[]) {
        this.data = data;
        this.index = 0;
    }

    update(): boolean {
        if (this.index < this.data.length) {
            this.data[this.index] = this.index + 1;
            this.index += 1;
            return true;
        }
        return false;
    }

    reset(): void {
        this.index = 0;
    }
}

class Tracker {
    sequence: FrameSequence;

    constructor(sequence: FrameSequence) {
        this.sequence = sequence;
    }

    monitor(): void {
        if (!this.sequence.update()) {
            this.sequence.reset();
        }
    }
}

class Processor {
    tracker: Tracker;

    constructor(tracker: Tracker) {
        this.tracker = tracker;
    }

    process(): void {
        while (true) {
            this.tracker.monitor();
        }
    }
}

function main() {
    const data = Array(10).fill(0);
    const sequence = new FrameSequence(data);
    const tracker = new Tracker(sequence);
    const processor = new Processor(tracker);
    processor.process();
}

main();