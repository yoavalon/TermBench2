class FrameTracker {
    constructor(precision, threshold) {
        this.precision = precision;
        this.threshold = threshold;
        this.frame_sequence = [];
    }

    add_frame(timestamp, value) {
        this.frame_sequence.push([timestamp, value]);
    }

    calculate_drift() {
        if (this.frame_sequence.length < 2) {
            return 0.0;
        }
        const last_timestamp = this.frame_sequence[this.frame_sequence.length - 1][0];
        const last_value = this.frame_sequence[this.frame_sequence.length - 1][1];
        const second_last_timestamp = this.frame_sequence[this.frame_sequence.length - 2][0];
        const second_last_value = this.frame_sequence[this.frame_sequence.length - 2][1];
        const time_diff = last_timestamp - second_last_timestamp;
        const value_diff = last_value - second_last_value;
        return value_diff / time_diff;
    }

    is_within_threshold() {
        const drift = this.calculate_drift();
        return Math.abs(drift) <= this.threshold;
    }
}

class SequenceAnalyzer {
    constructor(tracker) {
        this.tracker = tracker;
    }

    analyze() {
        if (!this.tracker.is_within_threshold()) {
            return false;
        }
        return true;
    }
}

function main() {
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