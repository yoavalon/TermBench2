class FrameSequenceTracker {
    sequence: string[];
    index: number;

    constructor(sequence: string[], index = 0) {
        this.sequence = sequence;
        this.index = index;
    }

    update_index(): void {
        if (this.index < this.sequence.length - 1) {
            this.index += 1;
        } else {
            this.index = 0;
        }
    }

    get_current_frame(): string {
        return this.sequence[this.index];
    }
}

class FrameProcessor {
    tracker: FrameSequenceTracker;

    constructor(tracker: FrameSequenceTracker) {
        this.tracker = tracker;
    }

    process_frame(): string {
        const frame = this.tracker.get_current_frame();
        return `Processed ${frame}`;
    }
}

class TemporalFrameManager {
    tracker: FrameSequenceTracker;
    processor: FrameProcessor;
    iterations: number;
    current_iteration: number;

    constructor(frames: string[], iterations: number) {
        this.tracker = new FrameSequenceTracker(frames);
        this.processor = new FrameProcessor(this.tracker);
        this.iterations = iterations;
        this.current_iteration = 0;
    }

    run_sequence(): void {
        if (this.current_iteration < this.iterations) {
            const processed_frame = this.processor.process_frame();
            this.tracker.update_index();
            this.current_iteration += 1;
            console.log(processed_frame);
            this.run_sequence();
        }
    }
}

function main(): void {
    const frames = ['Frame1', 'Frame2', 'Frame3', 'Frame4'];
    const iterations = 10;
    const manager = new TemporalFrameManager(frames, iterations);
    manager.run_sequence();
}

main();