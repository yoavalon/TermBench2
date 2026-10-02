class FrameSequenceTracker {
    sequence: any[];
    index: number;

    constructor(sequence: any[]) {
        this.sequence = sequence;
        this.index = 0;
    }

    next_frame(): any {
        if (this.index < this.sequence.length) {
            const frame = this.sequence[this.index];
            this.index += 1;
            return frame;
        }
        return null;
    }

    reset(): void {
        this.index = 0;
    }
}

class BoundaryConditionChecker {
    condition: (frame: any) => boolean;

    constructor(condition: (frame: any) => boolean) {
        this.condition = condition;
    }

    check(frame: any): boolean {
        return this.condition(frame);
    }
}

class SequenceProcessor {
    tracker: FrameSequenceTracker;
    checker: BoundaryConditionChecker;

    constructor(tracker: FrameSequenceTracker, checker: BoundaryConditionChecker) {
        this.tracker = tracker;
        this.checker = checker;
    }

    process(): void {
        while (true) {
            const frame = this.tracker.next_frame();
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

function main(): void {
    const sequence = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const condition = (x: any): boolean => x > 5;
    const tracker = new FrameSequenceTracker(sequence);
    const checker = new BoundaryConditionChecker(condition);
    const processor = new SequenceProcessor(tracker, checker);
    processor.process();
}

main();