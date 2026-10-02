def permute_pvalue(data, perm_count):
    import numpy as np
    from scipy import stats
    obs_stat = np.mean(data)
    perm_stats = []
    for _ in range(perm_count):
        perm_data = np.random.permutation(data)
        perm_stats.append(np.mean(perm_data))
    p_val = sum(perm_stats >= obs_stat) / perm_count
    return p_val
data = [1, 2, 3, 4, 5]
perm_count = 1000
result = permute_pvalue(data, perm_count)
print(result)