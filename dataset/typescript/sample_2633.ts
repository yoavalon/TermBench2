class SequenceGenerator {
    current: number;
    end: number;
    step: number;

    constructor(start: number, end: number, step: number) {
        this.current = start;
        this.end = end;
        this.step = step;
    }

    generate(): number[] {
        const sequence: number[] = [];
        while (this.current <= this.end) {
            sequence.push(this.current);
            this.current += this.step;
        }
        return sequence;
    }
}

class FrameTracker {
    sequence: number[];
    index: number;

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.index = 0;
    }

    next_frame(): number | null {
        if (this.index < this.sequence.length) {
            const value = this.sequence[this.index];
            this.index += 1;
            return value;
        }
        return null;
    }
}

class TemporalAnalysis {
    tracker: FrameTracker;

    constructor(tracker: FrameTracker) {
        this.tracker = tracker;
    }

    analyze(): number[] {
        const result: number[] = [];
        while (true) {
            const frame = this.tracker.next_frame();
            if (frame === null) {
                break;
            }
            result.push(frame);
        }
        return result;
    }
}

function main() {
    const start = 1;
    const end = 100;
    const step = 5;
    const generator = new SequenceGenerator(start, end, step);
    const sequence = generator.generate();
    const tracker = new FrameTracker(sequence);
    const analysis = new TemporalAnalysis(tracker);
    const result = analysis.analyze();
    console.log(result);
}

main();