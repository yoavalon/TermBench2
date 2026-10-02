class FrameTracker {
    constructor(sequence) {
        this.sequence = sequence;
        this.current_index = 0;
    }

    update() {
        this.current_index = (this.current_index + 1) % this.sequence.length;
    }

    getCurrentFrame() {
        return this.sequence[this.current_index];
    }
}

class BoundaryManager {
    constructor(frame_tracker, boundary_conditions) {
        this.frame_tracker = frame_tracker;
        this.boundary_conditions = boundary_conditions;
    }

    checkConditions() {
        const current_frame = this.frame_tracker.getCurrentFrame();
        for (const condition of this.boundary_conditions) {
            if (!condition(current_frame)) {
                return false;
            }
        }
        return true;
    }

    handleFrame() {
        if (this.checkConditions()) {
            this.frame_tracker.update();
        }
    }
}

class SequenceHandler {
    constructor(boundary_manager) {
        this.boundary_manager = boundary_manager;
    }

    process() {
        while (true) {
            this.boundary_manager.handleFrame();
        }
    }
}

function main() {
    const sequence = [1, 2, 3, 4, 5];
    const boundary_conditions = [x => x > 0, x => x < 6];
    const frame_tracker = new FrameTracker(sequence);
    const boundary_manager = new BoundaryManager(frame_tracker, boundary_conditions);
    const sequence_handler = new SequenceHandler(boundary_manager);
    sequence_handler.process();
}

main();