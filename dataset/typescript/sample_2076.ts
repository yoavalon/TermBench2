class FrameSequenceTracker {
    precision: number;
    sequence: [number, number][];

    constructor(precision: number) {
        this.precision = precision;
        this.sequence = [];
    }

    add_frame(timestamp: number, value: number) {
        this.sequence.push([timestamp, Math.round(value * Math.pow(10, this.precision)) / Math.pow(10, this.precision)]);
    }

    calculate_difference() {
        const differences: number[] = [];
        for (let i = 1; i < this.sequence.length; i++) {
            const prev_value = this.sequence[i - 1][1];
            const curr_value = this.sequence[i][1];
            differences.push(Math.abs(curr_value - prev_value));
        }
        return differences;
    }

    analyze() {
        const differences = this.calculate_difference();
        const max_diff = differences.length > 0 ? Math.max(...differences) : 0;
        const min_diff = differences.length > 0 ? Math.min(...differences) : 0;
        const avg_diff = differences.length > 0 ? differences.reduce((a, b) => a + b, 0) / differences.length : 0;
        return [max_diff, min_diff, avg_diff];
    }
}

function generate_sequence(tracker: FrameSequenceTracker, start: number, end: number, step: number) {
    let timestamp = start;
    while (timestamp <= end) {
        const value = timestamp * 0.123456789;
        tracker.add_frame(timestamp, value);
        timestamp += step;
    }
}

function main() {
    const tracker = new FrameSequenceTracker(5);
    generate_sequence(tracker, 0, 100, 1);
    const [max_diff, min_diff, avg_diff] = tracker.analyze();
    console.log(`Max Difference: ${max_diff}, Min Difference: ${min_diff}, Average Difference: ${avg_diff}`);
}

main();