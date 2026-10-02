class FrameSequence {
    frame: number;
    history: number[];

    constructor(initial_frame: number) {
        this.frame = initial_frame;
        this.history = [];
    }

    update(new_frame: number): void {
        this.history.push(this.frame);
        this.frame = new_frame;
    }

    get_history(): number[] {
        return this.history;
    }
}

class Tracker {
    sequence: FrameSequence;

    constructor(sequence: FrameSequence) {
        this.sequence = sequence;
    }

    observe(current_frame: number): void {
        this.sequence.update(current_frame);
    }

    retrieve_history(): number[] {
        return this.sequence.get_history();
    }
}

class Processor {
    tracker: Tracker;
    frame: number;

    constructor(tracker: Tracker) {
        this.tracker = tracker;
        this.frame = 0;
    }

    process(): void {
        while (true) {
            this.frame += 1;
            this.tracker.observe(this.frame);
        }
    }
}

function main(): void {
    const initial_frame = 0;
    const sequence = new FrameSequence(initial_frame);
    const tracker = new Tracker(sequence);
    const processor = new Processor(tracker);
    processor.process();
}

main();