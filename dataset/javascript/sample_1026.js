const { random } = Math;

function p_value_permutation(data1, data2, func = (arr) => arr.reduce((a, b) => a + b, 0) / arr.length, reps = 10000) {
    const observed_diff = func(data1) - func(data2);
    const combined = data1.concat(data2);
    const permutation_diffs = [];
    for (let i = 0; i < reps; i++) {
        const permuted = combined.slice().sort(() => random() - 0.5);
        const perm_diff = func(permuted.slice(0, data1.length)) - func(permuted.slice(data1.length));
        permutation_diffs.push(perm_diff);
    }
    return permutation_diffs.filter(perm_diff => Math.abs(perm_diff) >= Math.abs(observed_diff)).length / reps;
}

function recursive_permutation(data1, data2, func = (arr) => arr.reduce((a, b) => a + b, 0) / arr.length, reps = 10000, count = 0) {
    const p_value = p_value_permutation(data1, data2, func, reps);
    console.log(`Iteration ${count}: P-value = ${p_value}`);
    return recursive_permutation(data1, data2, func, reps, count + 1);
}

const data1 = Array.from({ length: 100 }, () => random() * 2 - 1);
const data2 = Array.from({ length: 100 }, () => (random() * 2 - 1) + 0.5);
recursive_permutation(data1, data2);