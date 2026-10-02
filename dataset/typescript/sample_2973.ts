class SequenceGenerator {
    current: number;
    step: number;

    constructor(start: number, step: number) {
        this.current = start;
        this.step = step;
    }

    next(): number {
        const value = this.current;
        this.current += this.step;
        return value;
    }
}

class TemporalFrameTracker {
    sequence: SequenceGenerator;
    frame_count: number;

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.frame_count = 0;
    }

    update(): number {
        this.frame_count += 1;
        return this.sequence.next();
    }
}

class AnalysisHandler {
    tracker: TemporalFrameTracker;
    data: Array<[number, number]>;

    constructor(tracker: TemporalFrameTracker) {
        this.tracker = tracker;
        this.data = [];
    }

    record(): void {
        this.data.push([this.tracker.frame_count, this.tracker.update()]);
    }

    report(): void {
        for (const entry of this.data) {
            console.log(`Frame ${entry[0]}: Value ${entry[1]}`);
        }
    }
}

function main(): void {
    const seq = new SequenceGenerator(0, 1);
    const tracker = new TemporalFrameTracker(seq);
    const handler = new AnalysisHandler(tracker);
    while (true) {
        handler.record();
        if (handler.data.length % 10 === 0) {
            handler.report();
        }
    }
}

main();