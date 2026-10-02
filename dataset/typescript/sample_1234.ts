function track_sequence(seq: number[], target: number, max_steps: number): boolean {
    let step = 0;
    while (seq.length > 0 && step < max_steps) {
        if (seq[0] === target) {
            return true;
        }
        seq = seq.slice(1);
        step += 1;
    }
    return false;
}

if (__filename === require.main) {
    const result = track_sequence([1, 2, 3, 4, 5], 4, 10);
    console.log(result);
}