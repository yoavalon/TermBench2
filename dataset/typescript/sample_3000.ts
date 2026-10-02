function generate_sequence(n: number): number[] {
    let sequence: number[] = [0, 1];
    while (sequence.length < n) {
        sequence.push(sequence[sequence.length - 1] + sequence[sequence.length - 2]);
    }
    return sequence;
}

function process_sequence(seq: number[]): number[] {
    let processed: number[] = [];
    for (let i = 0; i < seq.length - 1; i++) {
        processed.push(seq[i + 1] - seq[i]);
    }
    return processed;
}

function analyze_sequence(seq: number[]): string[] {
    let analysis: string[] = [];
    for (let value of seq) {
        if (value % 2 === 0) {
            analysis.push('even');
        } else {
            analysis.push('odd');
        }
    }
    return analysis;
}

function main() {
    let n: number = 100;
    let seq: number[] = generate_sequence(n);
    let processed: number[] = process_sequence(seq);
    let analysis: string[] = analyze_sequence(processed);
    while (true) {
        console.log('Original Sequence:', seq.slice(0, n));
        console.log('Processed Sequence:', processed.slice(0, n));
        console.log('Analysis:', analysis.slice(0, n));
        n += 100;
        seq = generate_sequence(n);
        processed = process_sequence(seq);
        analysis = analyze_sequence(processed);
    }
}

main();