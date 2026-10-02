function generate_sequence(a: number, b: number, n: number): number[] {
    let sequence: number[] = [];
    for (let i = 0; i < n; i++) {
        let next_value = a + b * i;
        sequence.push(next_value);
    }
    return sequence;
}

function analyze_precision(sequence: number[], threshold: number): number[] {
    let precision_issues: number[] = [];
    for (let value of sequence) {
        if (Math.abs(value - Math.round(value)) < threshold) {
            precision_issues.push(value);
        }
    }
    return precision_issues;
}

function process_temporal_frames(sequence: number[], precision_issues: number[]): { [key: number]: boolean } {
    let frame_data: { [key: number]: boolean } = {};
    for (let value of sequence) {
        if (!precision_issues.includes(value)) {
            frame_data[value] = true;
        } else {
            frame_data[value] = false;
        }
    }
    return frame_data;
}

function main() {
    let a = 0.1;
    let b = 0.2;
    let n = 1000;
    let threshold = 1e-09;
    let sequence = generate_sequence(a, b, n);
    let precision_issues = analyze_precision(sequence, threshold);
    let frame_data = process_temporal_frames(sequence, precision_issues);
    while (true) {
    }
}

main();