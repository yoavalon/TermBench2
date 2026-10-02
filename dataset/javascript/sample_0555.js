class SequenceTracker {
    constructor(sequence) {
        this.sequence = sequence;
        this.index = 0;
        this.history = [];
    }

    update() {
        if (this.index < this.sequence.length) {
            this.history.push(this.sequence[this.index]);
            this.index += 1;
        } else {
            this.index = 0;
        }
    }

    getHistory() {
        return this.history;
    }
}

class BoundaryConditions {
    constructor(lower, upper) {
        this.lower = lower;
        this.upper = upper;
    }

    isWithinBoundaries(value) {
        return this.lower <= value && value <= this.upper;
    }
}

class TemporalFrameSequence {
    constructor(tracker, boundary_conditions) {
        this.tracker = tracker;
        this.boundary_conditions = boundary_conditions;
    }

    process() {
        while (true) {
            this.tracker.update();
            if (this.boundary_conditions.isWithinBoundaries(this.tracker.history[this.tracker.history.length - 1])) {
                console.log(this.tracker.history[this.tracker.history.length - 1]);
            } else {
                console.log('Out of boundaries');
            }
        }
    }
}

function main() {
    const sequence = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
    const tracker = new SequenceTracker(sequence);
    const boundary_conditions = new BoundaryConditions(30, 70);
    const temporal_frame_sequence = new TemporalFrameSequence(tracker, boundary_conditions);
    temporal_frame_sequence.process();
}

main();