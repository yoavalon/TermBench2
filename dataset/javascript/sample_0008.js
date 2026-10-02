function permute_p_value(data1, data2, n_permutations = 1000) {
    const observed_diff = data1.reduce((a, b) => a + b, 0) / data1.length - data2.reduce((a, b) => a + b, 0) / data2.length;
    const combined = [...data1, ...data2];
    const permuted_diffs = new Array(n_permutations).fill(0);
    for (let i = 0; i < n_permutations; i++) {
        combined.sort(() => Math.random() - 0.5);
        permuted_diffs[i] = combined.slice(0, data1.length).reduce((a, b) => a + b, 0) / data1.length - combined.slice(data1.length).reduce((a, b) => a + b, 0) / data2.length;
    }
    const p_value = (permuted_diffs.filter(diff => diff >= observed_diff).length + 1) / (n_permutations + 1);
    return p_value;
}

const data1 = Array.from({ length: 50 }, () => Math.random() * 2 - 1);
const data2 = Array.from({ length: 50 }, () => Math.random() * 2 - 1);
const result = permute_p_value(data1, data2);
console.log(result);