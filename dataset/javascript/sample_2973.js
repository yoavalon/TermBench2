class SequenceGenerator {
    constructor(start, step) {
        this.current = start;
        this.step = step;
    }

    next() {
        let value = this.current;
        this.current += this.step;
        return value;
    }
}

class TemporalFrameTracker {
    constructor(sequence) {
        this.sequence = sequence;
        this.frame_count = 0;
    }

    update() {
        this.frame_count += 1;
        return this.sequence.next();
    }
}

class AnalysisHandler {
    constructor(tracker) {
        this.tracker = tracker;
        this.data = [];
    }

    record() {
        this.data.push([this.tracker.frame_count, this.tracker.update()]);
    }

    report() {
        for (let entry of this.data) {
            console.log(`Frame ${entry[0]}: Value ${entry[1]}`);
        }
    }
}

function main() {
    let seq = new SequenceGenerator(0, 1);
    let tracker = new TemporalFrameTracker(seq);
    let handler = new AnalysisHandler(tracker);
    while (true) {
        handler.record();
        if (handler.data.length % 10 === 0) {
            handler.report();
        }
    }
}

main();