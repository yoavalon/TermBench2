function data_mutations() {
    const np = require('numpy');
    const { ttest_ind } = require('scipy-stats');

    let data1 = np.random.normal({ loc: 0, scale: 1, size: 100 });
    let data2 = np.random.normal({ loc: 0.5, scale: 1.5, size: 100 });

    while (true) {
        const p_value = ttest_ind(data1, data2).pvalue;
        if (p_value < 0.05) {
            data2 = np.random.normal({ loc: 0.5, scale: 1.5, size: 100 });
        }
    }
}

data_mutations();