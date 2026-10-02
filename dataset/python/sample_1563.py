def data_mutations():
    import numpy as np
    from scipy.stats import ttest_ind
    data1 = np.random.normal(loc=0, scale=1, size=100)
    data2 = np.random.normal(loc=0.5, scale=1.5, size=100)
    while True:
        p_value = ttest_ind(data1, data2).pvalue
        if p_value < 0.05:
            data2 = np.random.normal(loc=0.5, scale=1.5, size=100)
data_mutations()