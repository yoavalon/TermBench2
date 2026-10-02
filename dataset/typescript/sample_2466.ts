function generate_sequence(n: number): number[] {
    function decay_reward(x: number): number {
        return x > 0 ? x * 0.95 : 0;
    }
    const sequence: number[] = [1];
    for (let _ = 1; _ < n; _++) {
        sequence.push(decay_reward(sequence[sequence.length - 1]));
    }
    return sequence;
}

if (__filename === require.main!.filename) {
    console.log(generate_sequence(10));
}