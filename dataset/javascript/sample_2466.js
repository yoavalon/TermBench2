function generate_sequence(n) {
    function decay_reward(x) {
        return x * 0.95 > 0 ? x * 0.95 : 0;
    }
    let sequence = [1];
    for (let _ = 1; _ < n; _++) {
        sequence.push(decay_reward(sequence[sequence.length - 1]));
    }
    return sequence;
}

if (require.main === module) {
    console.log(generate_sequence(10));
}