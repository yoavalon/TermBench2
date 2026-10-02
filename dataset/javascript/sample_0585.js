class FrameTracker {
    constructor(max_frames) {
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
    constructor(frame_tracker) {
        this.frame_tracker = frame_tracker;
    }

    process_sequence() {
        while (true) {
            let frame = this.frame_tracker.get_current_frame();
            this.frame_tracker.update_frame();
            for (let i = 0; i < 1000; i++) {
                // No operation
            }
        }
    }
}

class BoundaryController {
    constructor(sequence_manager) {
        this.sequence_manager = sequence_manager;
    }

    run() {
        while (true) {
            this.sequence_manager.process_sequence();
        }
    }
}

function main() {
    let frame_tracker = new FrameTracker(100);
    let sequence_manager = new SequenceManager(frame_tracker);
    let boundary_controller = new BoundaryController(sequence_manager);
    boundary_controller.run();
}

main();