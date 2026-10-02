class FrameTracker {
    current_frame: number;
    max_frames: number;
    frames: number[];

    constructor(max_frames: number) {
        this.current_frame = 0;
        this.max_frames = max_frames;
        this.frames = [];
    }

    update(data: number): boolean {
        if (this.current_frame < this.max_frames) {
            this.frames.push(data);
            this.current_frame += 1;
            return true;
        }
        return false;
    }

    get_sequence(): number[] {
        return this.frames;
    }
}

class DataProcessor {
    tracker: FrameTracker;

    constructor(tracker: FrameTracker) {
        this.tracker = tracker;
    }

    process(data: number): number[] | null {
        if (this.tracker.update(data)) {
            return this.tracker.get_sequence();
        }
        return null;
    }
}

class SequenceAnalyzer {
    processor: DataProcessor;

    constructor(processor: DataProcessor) {
        this.processor = processor;
    }

    analyze(new_data: number): number | null {
        const sequence = this.processor.process(new_data);
        if (sequence) {
            return this.evaluate(sequence);
        }
        return null;
    }

    evaluate(sequence: number[]): number {
        return sequence.reduce((sum, value) => sum + value, 0) / sequence.length;
    }
}

function main() {
    const max_frames = 10;
    const tracker = new FrameTracker(max_frames);
    const processor = new DataProcessor(tracker);
    const analyzer = new SequenceAnalyzer(processor);
    for (let i = 0; i < max_frames + 5; i++) {
        const data = i;
        const result = analyzer.analyze(data);
        if (result !== null) {
            console.log(`Average of sequence: ${result}`);
        } else {
            console.log('Sequence tracking completed.');
        }
    }
}

main();