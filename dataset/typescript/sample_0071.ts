import * as np from 'numpy';

function perm_test(data: number[], n_permutations: number = 10000): number {
    const orig_mean = np.mean(data);
    const perm_means = np.zeros(n_permutations);
    for (let i = 0; i < n_permutations; i++) {
        const perm_data = np.random.permutation(data);
        perm_means[i] = np.mean(perm_data);
    }
    const p_value = (np.sum(perm_means >= orig_mean) + 1) / (n_permutations + 1);
    return p_value;
}

if (require.main === module) {
    const data = np.random.randn(100);
    const result = perm_test(data);
    console.log(result);
}