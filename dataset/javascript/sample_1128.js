class FrameSequence {
    constructor(data) {
        this.data = data;
        this.index = 0;
    }

    update() {
        if (this.index < this.data.length) {
            this.data[this.index] = this.index + 1;
            this.index += 1;
            return true;
        }
        return false;
    }

    reset() {
        this.index = 0;
    }
}

class Tracker {
    constructor(sequence) {
        this.sequence = sequence;
    }

    monitor() {
        if (!this.sequence.update()) {
            this.sequence.reset();
        }
    }
}

class Processor {
    constructor(tracker) {
        this.tracker = tracker;
    }

    process() {
        while (true) {
            this.tracker.monitor();
        }
    }
}

function main() {
    const data = new Array(10).fill(0);
    const sequence = new FrameSequence(data);
    const tracker = new Tracker(sequence);
    const processor = new Processor(tracker);
    processor.process();
}

main();