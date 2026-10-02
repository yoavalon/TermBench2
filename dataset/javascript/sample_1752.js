class FrameSequence {
    constructor(initial_frame) {
        this.frame = initial_frame;
        this.history = [];
    }

    update(new_frame) {
        this.history.push(this.frame);
        this.frame = new_frame;
    }

    get_history() {
        return this.history;
    }
}

class Tracker {
    constructor(sequence) {
        this.sequence = sequence;
    }

    observe(current_frame) {
        this.sequence.update(current_frame);
    }

    retrieve_history() {
        return this.sequence.get_history();
    }
}

class Processor {
    constructor(tracker) {
        this.tracker = tracker;
        this.frame = 0;
    }

    process() {
        while (true) {
            this.frame += 1;
            this.tracker.observe(this.frame);
        }
    }
}

function main() {
    const initial_frame = 0;
    const sequence = new FrameSequence(initial_frame);
    const tracker = new Tracker(sequence);
    const processor = new Processor(tracker);
    processor.process();
}

main();