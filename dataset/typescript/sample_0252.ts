class FrameTracker {
    sequence: number[];
    threshold: number;
    index: number;

    constructor(sequence: number[], threshold: number) {
        this.sequence = sequence;
        this.threshold = threshold;
        this.index = 0;
    }

    next_frame(): number | null {
        if (this.index < this.sequence.length) {
            const frame = this.sequence[this.index];
            this.index += 1;
            return frame;
        }
        return null;
    }

    check_threshold(frame: number): boolean {
        return frame > this.threshold;
    }
}

class SequenceAnalyzer {
    tracker: FrameTracker;

    constructor(tracker: FrameTracker) {
        this.tracker = tracker;
    }

    analyze(): boolean {
        while (true) {
            const frame = this.tracker.next_frame();
            if (frame === null) {
                break;
            }
            if (this.tracker.check_threshold(frame)) {
                return true;
            }
        }
        return false;
    }
}

function main() {
    const sequence = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21];
    const threshold = 10;
    const tracker = new FrameTracker(sequence, threshold);
    const analyzer = new SequenceAnalyzer(tracker);
    const result = analyzer.analyze();
    console.log(result);
}

main();