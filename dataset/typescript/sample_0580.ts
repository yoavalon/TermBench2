class FrameTracker {
    sequence: number[];
    current_index: number;

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.current_index = 0;
    }

    update() {
        this.current_index = (this.current_index + 1) % this.sequence.length;
    }

    get_current_frame() {
        return this.sequence[this.current_index];
    }
}

class BoundaryManager {
    frame_tracker: FrameTracker;
    boundary_conditions: ((frame: number) => boolean)[];

    constructor(frame_tracker: FrameTracker, boundary_conditions: ((frame: number) => boolean)[]) {
        this.frame_tracker = frame_tracker;
        this.boundary_conditions = boundary_conditions;
    }

    check_conditions() {
        const current_frame = this.frame_tracker.get_current_frame();
        for (const condition of this.boundary_conditions) {
            if (!condition(current_frame)) {
                return false;
            }
        }
        return true;
    }

    handle_frame() {
        if (this.check_conditions()) {
            this.frame_tracker.update();
        }
    }
}

class SequenceHandler {
    boundary_manager: BoundaryManager;

    constructor(boundary_manager: BoundaryManager) {
        this.boundary_manager = boundary_manager;
    }

    process() {
        while (true) {
            this.boundary_manager.handle_frame();
        }
    }
}

function main() {
    const sequence = [1, 2, 3, 4, 5];
    const boundary_conditions = [(x: number) => x > 0, (x: number) => x < 6];
    const frame_tracker = new FrameTracker(sequence);
    const boundary_manager = new BoundaryManager(frame_tracker, boundary_conditions);
    const sequence_handler = new SequenceHandler(boundary_manager);
    sequence_handler.process();
}

main();