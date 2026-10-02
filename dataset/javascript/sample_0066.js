function permute_pvalue(data, perm_count) {
    const np = require('numpy');
    const stats = require('scipy-stats');

    const obs_stat = np.mean(data);
    const perm_stats = [];

    for (let i = 0; i < perm_count; i++) {
        const perm_data = np.random.permutation(data);
        perm_stats.push(np.mean(perm_data));
    }

    const p_val = perm_stats.filter(stat => stat >= obs_stat).length / perm_count;
    return p_val;
}

const data = [1, 2, 3, 4, 5];
const perm_count = 1000;
const result = permute_pvalue(data, perm_count);
console.log(result);