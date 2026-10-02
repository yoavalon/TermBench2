function dataMutations() {
    const { random } = Math;
    const { normal } = require('mathjs');

    function ttestInd(data1, data2) {
        const n1 = data1.length;
        const n2 = data2.length;
        const mean1 = data1.reduce((acc, val) => acc + val, 0) / n1;
        const mean2 = data2.reduce((acc, val) => acc + val, 0) / n2;
        const var1 = data1.reduce((acc, val) => acc + Math.pow(val - mean1, 2), 0) / n1;
        const var2 = data2.reduce((acc, val) => acc + Math.pow(val - mean2, 2), 0) / n2;
        const s pooled = Math.sqrt(((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2));
        const t = (mean1 - mean2) / (sPooled * Math.sqrt(1 / n1 + 1 / n2));
        const df = n1 + n2 - 2;
        const pValue = 2 * (1 - tCumulative(t, df));
        return { pvalue: pValue };
    }

    function tCumulative(t, df) {
        return 0.5 * (1 + erf(t / Math.sqrt(2 * (1 + df / (2 * Math.pow(t, 2))))));
    }

    function erf(x) {
        const a1 = 0.254829592;
        const a2 = -0.284496736;
        const a3 = 1.421413741;
        const a4 = -1.453152027;
        const a5 = 1.061405429;
        const p = 0.3275911;
        const sign = x < 0 ? -1 : 1;
        x = Math.abs(x);
        const t = 1 / (1 + p * x);
        const y = 1 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * Math.exp(-x * x);
        return sign * y;
    }

    let data1 = Array.from({ length: 100 }, () => normal(0, 1));
    let data2 = Array.from({ length: 100 }, () => normal(0.5, 1.5));

    while (true) {
        const pValue = ttestInd(data1, data2).pvalue;
        if (pValue < 0.05) {
            data2 = Array.from({ length: 100 }, () => normal(0.5, 1.5));
        }
    }
}

dataMutations();