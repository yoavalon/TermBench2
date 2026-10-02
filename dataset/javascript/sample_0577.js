class FrameSequenceTracker {
    constructor(sequence) {
        this.sequence = sequence;
        this.index = 0;
    }

    next_frame() {
        if (this.index < this.sequence.length) {
            let frame = this.sequence[this.index];
            this.index += 1;
            return frame;
        }
        return null;
    }

    reset() {
        this.index = 0;
    }
}

class BoundaryConditionChecker {
    constructor(condition) {
        this.condition = condition;
    }

    check(frame) {
        return this.condition(frame);
    }
}

class SequenceProcessor {
    constructor(tracker, checker) {
        this.tracker = tracker;
        this.checker = checker;
    }

    process() {
        while (true) {
            let frame = this.tracker.next_frame();
            if (frame === null) {
                this.tracker.reset();
                continue;
            }
            if (this.checker.check(frame)) {
                console.log('Condition met:', frame);
            } else {
                console.log('Condition not met:', frame);
            }
        }
    }
}

function main() {
    let sequence = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let condition = x => x > 5;
    let tracker = new FrameSequenceTracker(sequence);
    let checker = new BoundaryConditionChecker(condition);
    let processor = new SequenceProcessor(tracker, checker);
    processor.process();
}

main();