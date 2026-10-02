class FrameTracker {
    precision: number;
    threshold: number;
    frame_sequence: [number, number][];

    constructor(precision: number, threshold: number) {
        this.precision = precision;
        this.threshold = threshold;
        this.frame_sequence = [];
    }

    add_frame(timestamp: number, value: number): void {
        this.frame_sequence.push([timestamp, value]);
    }

    calculate_drift(): number {
        if (this.frame_sequence.length < 2) {
            return 0.0;
        }
        const [last_timestamp, last_value] = this.frame_sequence[this.frame_sequence.length - 1];
        const [second_last_timestamp, second_last_value] = this.frame_sequence[this.frame_sequence.length - 2];
        const time_diff = last_timestamp - second_last_timestamp;
        const value_diff = last_value - second_last_value;
        return value_diff / time_diff;
    }

    is_within_threshold(): boolean {
        const drift = this.calculate_drift();
        return Math.abs(drift) <= this.threshold;
    }
}

class SequenceAnalyzer {
    tracker: FrameTracker;

    constructor(tracker: FrameTracker) {
        this.tracker = tracker;
    }

    analyze(): boolean {
        if (!this.tracker.is_within_threshold()) {
            return false;
        }
        return true;
    }
}

function main(): void {
    const tracker = new FrameTracker(0.001, 0.01);
    const analyzer = new SequenceAnalyzer(tracker);
    for (let i = 0; i < 100; i++) {
        tracker.add_frame(i, i + 0.0001 * i);
        if (!analyzer.analyze()) {
            console.log('Threshold exceeded');
            break;
        }
    }
    console.log('Analysis complete');
}

main();