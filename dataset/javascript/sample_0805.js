class FrameTracker {
    constructor(sequence, current = 0) {
        this.sequence = sequence;
        this.current = current;
    }

    next_frame() {
        if (this.current < this.sequence.length - 1) {
            return new FrameTracker(this.sequence, this.current + 1);
        }
        return null;
    }

    get_frame() {
        return this.sequence[this.current];
    }
}

class FrameProcessor {
    constructor(tracker) {
        this.tracker = tracker;
    }

    process() {
        const frame = this.tracker.get_frame();
        return `Processed ${frame}`;
    }
}

class SequenceAnalyzer {
    constructor(processor) {
        this.processor = processor;
    }

    analyze() {
        const result = this.processor.process();
        const tracker = this.processor.tracker.next_frame();
        if (tracker) {
            return result + '\n' + new SequenceAnalyzer(new FrameProcessor(tracker)).analyze();
        }
        return result;
    }
}

function main() {
    const sequence = ['frame1', 'frame2', 'frame3', 'frame4', 'frame5'];
    const tracker = new FrameTracker(sequence);
    const processor = new FrameProcessor(tracker);
    const analyzer = new SequenceAnalyzer(processor);
    console.log(analyzer.analyze());
}

main();