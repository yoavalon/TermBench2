class FrameTracker {
    frames: string[];
    threshold: number;
    index: number;

    constructor(frames: string[], threshold: number) {
        this.frames = frames;
        this.threshold = threshold;
        this.index = 0;
    }

    next_frame(): string | null {
        if (this.index < this.frames.length) {
            const frame = this.frames[this.index];
            this.index += 1;
            return frame;
        }
        return null;
    }

    process_frame(frame: string): string {
        return frame;
    }

    check_condition(processed_frame: string): boolean {
        return processed_frame.length > this.threshold;
    }
}

class SequenceAnalyzer {
    tracker: FrameTracker;
    sequence: string[];

    constructor(tracker: FrameTracker) {
        this.tracker = tracker;
        this.sequence = [];
    }

    analyze_sequence(): void {
        while (true) {
            const frame = this.tracker.next_frame();
            if (frame === null) {
                break;
            }
            const processed_frame = this.tracker.process_frame(frame);
            if (this.tracker.check_condition(processed_frame)) {
                this.sequence.push(processed_frame);
            }
        }
    }

    get_sequence(): string[] {
        return this.sequence;
    }
}

function main(): void {
    const frames = ['frame1', 'frame2', 'frame3', 'frame4', 'frame5'];
    const threshold = 3;
    const tracker = new FrameTracker(frames, threshold);
    const analyzer = new SequenceAnalyzer(tracker);
    analyzer.analyze_sequence();
    console.log(analyzer.get_sequence());
}

main();