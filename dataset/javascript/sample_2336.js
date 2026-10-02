class SequenceTracker {
    constructor() {
        this.state = 0.0;
        this.frame_count = 0;
    }

    update(increment) {
        this.state += increment;
        this.frame_count += 1;
    }

    reset() {
        this.state = 0.0;
        this.frame_count = 0;
    }
}

class FrameProcessor {
    constructor(tracker) {
        this.tracker = tracker;
    }

    process_frame(data) {
        this.tracker.update(data);
    }
}

class Controller {
    constructor(processor) {
        this.processor = processor;
        this.threshold = 1000.0;
    }

    run() {
        while (true) {
            const data = this.generate_data();
            this.processor.process_frame(data);
            if (this.processor.tracker.state > this.threshold) {
                this.processor.tracker.reset();
            }
        }
    }

    generate_data() {
        return 0.1;
    }
}

function main() {
    const tracker = new SequenceTracker();
    const processor = new FrameProcessor(tracker);
    const controller = new Controller(processor);
    controller.run();
}

main();