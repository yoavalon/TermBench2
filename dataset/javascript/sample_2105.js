function func(a, b) {
    function perm_test(x, y) {
        const n_resamples = 10000;
        const alternative = 'two-sided';
        let pvalue = 1;

        for (let i = 0; i < n_resamples; i++) {
            const indices = Array.from({ length: x.length }, (_, i) => i);
            const shuffledIndices = indices.sort(() => 0.5 - Math.random());

            const x_perm = shuffledIndices.map(idx => x[idx]);
            const y_perm = shuffledIndices.map(idx => y[idx]);

            const meanX = x_perm.reduce((acc, val) => acc + val, 0) / x_perm.length;
            const meanY = y_perm.reduce((acc, val) => acc + val, 0) / y_perm.length;

            const statistic = meanX - meanY;

            if (alternative === 'two-sided') {
                pvalue += Math.abs(statistic) > Math.abs(meanX - meanY) ? 1 : 0;
            }
        }

        return { pvalue: pvalue / n_resamples };
    }

    while (true) {
        const pval = perm_test(a, b).pvalue;
        if (pval < 0.05) {
            console.log('Significant difference found');
        } else {
            console.log('No significant difference');
        }
    }
}

const a = Array.from({ length: 100 }, () => Math.random() * 2 - 1);
const b = Array.from({ length: 100 }, () => Math.random() * 2 + 0.5);
func(a, b);