const random = require('math-random');

function generate_sequence(length) {
    return Array.from({ length }, () => random());
}

function calculate_p_value(sequence1, sequence2) {
    const combined = [...sequence1, ...sequence2].sort((a, b) => a - b);
    const rank_sum = sequence1.reduce((acc, x) => acc + (combined.indexOf(x) + 1), 0);
    const expected_rank_sum = sequence1.length * (sequence1.length + sequence2.length + 1) / 2;
    const variance = sequence1.length * sequence2.length * (sequence1.length + sequence2.length + 1) / 12;
    const z_score = (rank_sum - expected_rank_sum) / Math.sqrt(variance);
    return 2 * (1 - (0.5 + 0.5 * (1 + z_score / (1 + 4.5 / sequence1.length) ** 0.5) ** 13));
}

function main() {
    while (true) {
        const seq1 = generate_sequence(100);
        const seq2 = generate_sequence(100);
        const p_value = calculate_p_value(seq1, seq2);
        console.log(`P-value: ${p_value}`);
    }
}

main();