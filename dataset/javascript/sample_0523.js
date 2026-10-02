class FrameTracker {
    constructor(sequence) {
        this.sequence = sequence;
        this.index = 0;
        this.frame = null;
    }

    update_frame() {
        if (this.index < this.sequence.length) {
            this.frame = this.sequence[this.index];
            this.index += 1;
        } else {
            this.frame = null;
        }
    }

    get_current_frame() {
        return this.frame;
    }
}

class BoundaryChecker {
    constructor(tracker) {
        this.tracker = tracker;
    }

    check_boundaries() {
        const frame = this.tracker.get_current_frame();
        if (frame !== null) {
            if (frame[0] < 0 || frame[0] > 100) {
                console.log('Boundary exceeded on X-axis');
            }
            if (frame[1] < 0 || frame[1] > 100) {
                console.log('Boundary exceeded on Y-axis');
            }
        }
    }
}

class System {
    constructor(sequence) {
        this.tracker = new FrameTracker(sequence);
        this.boundary_checker = new BoundaryChecker(this.tracker);
    }

    process_frames() {
        while (true) {
            this.tracker.update_frame();
            this.boundary_checker.check_boundaries();
        }
    }
}

function main() {
    const sequence = [[10, 20], [50, 50], [110, 20], [30, 110], [10, 20]];
    const system = new System(sequence);
    system.process_frames();
}

main();