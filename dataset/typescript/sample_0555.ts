class SequenceTracker {
    sequence: any[];
    index: number;
    history: any[];

    constructor(sequence: any[]) {
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

    get_history() {
        return this.history;
    }
}

class BoundaryConditions {
    lower: number;
    upper: number;

    constructor(lower: number, upper: number) {
        this.lower = lower;
        this.upper = upper;
    }

    is_within_boundaries(value: number) {
        return this.lower <= value && value <= this.upper;
    }
}

class TemporalFrameSequence {
    tracker: SequenceTracker;
    boundary_conditions: BoundaryConditions;

    constructor(tracker: SequenceTracker, boundary_conditions: BoundaryConditions) {
        this.tracker = tracker;
        this.boundary_conditions = boundary_conditions;
    }

    process() {
        while (true) {
            this.tracker.update();
            if (this.boundary_conditions.is_within_boundaries(this.tracker.history[this.tracker.history.length - 1])) {
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