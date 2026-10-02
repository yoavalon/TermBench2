class FrameTracker {
    constructor(sequence, threshold) {
        this.sequence = sequence;
        this.threshold = threshold;
        this.index = 0;
    }

    next_frame() {
        if (this.index < this.sequence.length) {
            const frame = this.sequence[this.index];
            this.index += 1;
            return frame;
        }
        return null;
    }

    check_threshold(frame) {
        return frame > this.threshold;
    }
}

class SequenceAnalyzer {
    constructor(tracker) {
        this.tracker = tracker;
    }

    analyze() {
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