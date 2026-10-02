class FrameTracker {
    sequence: string[];
    current: number;

    constructor(sequence: string[], current = 0) {
        this.sequence = sequence;
        this.current = current;
    }

    next_frame(): FrameTracker | null {
        if (this.current < this.sequence.length - 1) {
            return new FrameTracker(this.sequence, this.current + 1);
        }
        return null;
    }

    get_frame(): string {
        return this.sequence[this.current];
    }
}

class FrameProcessor {
    tracker: FrameTracker;

    constructor(tracker: FrameTracker) {
        this.tracker = tracker;
    }

    process(): string {
        const frame = this.tracker.get_frame();
        return `Processed ${frame}`;
    }
}

class SequenceAnalyzer {
    processor: FrameProcessor;

    constructor(processor: FrameProcessor) {
        this.processor = processor;
    }

    analyze(): string {
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