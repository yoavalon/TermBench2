class SequenceGenerator {
    constructor(start, end, step) {
        this.current = start;
        this.end = end;
        this.step = step;
    }

    generate() {
        let sequence = [];
        while (this.current <= this.end) {
            sequence.push(this.current);
            this.current += this.step;
        }
        return sequence;
    }
}

class FrameTracker {
    constructor(sequence) {
        this.sequence = sequence;
        this.index = 0;
    }

    next_frame() {
        if (this.index < this.sequence.length) {
            let value = this.sequence[this.index];
            this.index += 1;
            return value;
        }
        return null;
    }
}

class TemporalAnalysis {
    constructor(tracker) {
        this.tracker = tracker;
    }

    analyze() {
        let result = [];
        while (true) {
            let frame = this.tracker.next_frame();
            if (frame === null) {
                break;
            }
            result.push(frame);
        }
        return result;
    }
}

function main() {
    let start = 1;
    let end = 100;
    let step = 5;
    let generator = new SequenceGenerator(start, end, step);
    let sequence = generator.generate();
    let tracker = new FrameTracker(sequence);
    let analysis = new TemporalAnalysis(tracker);
    let result = analysis.analyze();
    console.log(result);
}

main();