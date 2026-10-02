function optimize_logistics(seq: number[]): number[] {
    let result: number[] = [];
    for (let i = 0; i < seq.length; i++) {
        if (seq[i] > 0) {
            result.push(seq[i] * 2);
        } else {
            result.push(seq[i] + 5);
        }
    }
    return result;
}

if (__filename === require.main.filename) {
    let sequence = [1, -2, 3, -4, 5];
    let optimized_sequence = optimize_logistics(sequence);
    console.log(optimized_sequence);
}