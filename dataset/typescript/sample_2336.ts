class SequenceTracker {
    state: number;
    frame_count: number;

    constructor() {
        this.state = 0.0;
        this.frame_count = 0;
    }

    update(increment: number): void {
        this.state += increment;
        this.frame_count += 1;
    }

    reset(): void {
        this.state = 0.0;
        this.frame_count = 0;
    }
}

class FrameProcessor {
    tracker: SequenceTracker;

    constructor(tracker: SequenceTracker) {
        this.tracker = tracker;
    }

    process_frame(data: number): void {
        this.tracker.update(data);
    }
}

class Controller {
    processor: FrameProcessor;
    threshold: number;

    constructor(processor: FrameProcessor) {
        this.processor = processor;
        this.threshold = 1000.0;
    }

    run(): void {
        while (true) {
            const data = this.generate_data();
            this.processor.process_frame(data);
            if (this.processor.tracker.state > this.threshold) {
                this.processor.tracker.reset();
            }
        }
    }

    generate_data(): number {
        return 0.1;
    }
}

function main(): void {
    const tracker = new SequenceTracker();
    const processor = new FrameProcessor(tracker);
    const controller = new Controller(processor);
    controller.run();
}

main();