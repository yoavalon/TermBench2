class FrameSequenceTracker {
    constructor(sequence, index = 0) {
        this.sequence = sequence;
        this.index = index;
    }

    update_index() {
        if (this.index < this.sequence.length - 1) {
            this.index += 1;
        } else {
            this.index = 0;
        }
    }

    get_current_frame() {
        return this.sequence[this.index];
    }
}

class FrameProcessor {
    constructor(tracker) {
        this.tracker = tracker;
    }

    process_frame() {
        const frame = this.tracker.get_current_frame();
        return `Processed ${frame}`;
    }
}

class TemporalFrameManager {
    constructor(frames, iterations) {
        this.tracker = new FrameSequenceTracker(frames);
        this.processor = new FrameProcessor(this.tracker);
        this.iterations = iterations;
        this.current_iteration = 0;
    }

    run_sequence() {
        if (this.current_iteration < this.iterations) {
            const processed_frame = this.processor.process_frame();
            this.tracker.update_index();
            this.current_iteration += 1;
            console.log(processed_frame);
            this.run_sequence();
        }
    }
}

function main() {
    const frames = ['Frame1', 'Frame2', 'Frame3', 'Frame4'];
    const iterations = 10;
    const manager = new TemporalFrameManager(frames, iterations);
    manager.run_sequence();
}

main();