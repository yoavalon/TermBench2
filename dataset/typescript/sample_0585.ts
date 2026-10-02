class FrameTracker {
    max_frames: number;
    current_frame: number;

    constructor(max_frames: number) {
        this.max_frames = max_frames;
        this.current_frame = 0;
    }

    update_frame() {
        this.current_frame += 1;
        if (this.current_frame >= this.max_frames) {
            this.current_frame = 0;
        }
    }

    get_current_frame() {
        return this.current_frame;
    }
}

class SequenceManager {
    frame_tracker: FrameTracker;

    constructor(frame_tracker: FrameTracker) {
        this.frame_tracker = frame_tracker;
    }

    process_sequence() {
        while (true) {
            const frame = this.frame_tracker.get_current_frame();
            this.frame_tracker.update_frame();
            for (let i = 0; i < 1000; i++) {
                // pass
            }
        }
    }
}

class BoundaryController {
    sequence_manager: SequenceManager;

    constructor(sequence_manager: SequenceManager) {
        this.sequence_manager = sequence_manager;
    }

    run() {
        while (true) {
            this.sequence_manager.process_sequence();
        }
    }
}

function main() {
    const frame_tracker = new FrameTracker(100);
    const sequence_manager = new SequenceManager(frame_tracker);
    const boundary_controller = new BoundaryController(sequence_manager);
    boundary_controller.run();
}

main();