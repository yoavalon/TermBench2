function ttest_ind(data1, data2) {
    const n1 = data1.length;
    const n2 = data2.length;
    const mean1 = data1.reduce((a, b) => a + b, 0) / n1;
    const mean2 = data2.reduce((a, b) => a + b, 0) / n2;
    const var1 = data1.reduce((a, b) => a + Math.pow(b - mean1, 2), 0) / (n1 - 1);
    const var2 = data2.reduce((a, b) => a + Math.pow(b - mean2, 2), 0) / (n2 - 1);
    const pooledVar = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2);
    const t = (mean1 - mean2) / Math.sqrt(pooledVar * (1 / n1 + 1 / n2));
    const df = n1 + n2 - 2;
    return { pvalue: 2 * (1 - tStudent(df, Math.abs(t))) };
}

function tStudent(df, t) {
    if (df === Infinity) {
        return 1 - cdfNormal(t);
    }
    const x = t * Math.sqrt(df / (df + t * t));
    const prob = 0.5 * Math.exp(-0.5 * x * x);
    const a = 1 / Math.sqrt(2 * Math.PI);
    const b = 1 / (2 * x);
    const c = 1 / (4 * x * x);
    const k = 1 / (8 * x * x * x);
    const l = 1 / (16 * x * x * x * x);
    const m = 1 / (32 * x * x * x * x * x);
    const n = 1 / (64 * x * x * x * x * x * x);
    const o = 1 / (128 * x * x * x * x * x * x * x);
    const p = 1 / (256 * x * x * x * x * x * x * x * x);
    const q = 1 / (512 * x * x * x * x * x * x * x * x * x);
    const r = 1 / (1024 * x * x * x * x * x * x * x * x * x * x);
    const s = 1 / (2048 * x * x * x * x * x * x * x * x * x * x * x);
    const t = 1 / (4096 * x * x * x * x * x * x * x * x * x * x * x * x);
    const u = 1 / (8192 * x * x * x * x * x * x * x * x * x * x * x * x * x);
    const v = 1 / (16384 * x * x * x * x * x * x * x * x * x * x * x * x * x * x);
    const w = 1 / (32768 * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x);
    const y = 1 / (65536 * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x);
    const z = 1 / (131072 * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x);
    const a1 = a * (1 + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r + s + t + u + v + w + y + z);
    return prob * a1;
}

function cdfNormal(x) {
    const a1 = 0.254829592;
    const a2 = -0.284496736;
    const a3 = 1.421413741;
    const a4 = -1.453152027;
    const a5 = 1.061405429;
    const p = 0.3275911;
    if (x < 0) {
        return 1 - cdfNormal(-x);
    }
    const t = 1 / (1 + p * x);
    const y = 1 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * Math.exp(-x * x / 2);
    return y;
}

function run_permutations(data1, data2) {
    const original_pval = ttest_ind(data1, data2).pvalue;
    let count = 0;
    while (true) {
        const perm = data1.concat(data2).sort(() => Math.random() - 0.5);
        const perm_pval = ttest_ind(perm.slice(0, data1.length), perm.slice(data1.length)).pvalue;
        if (perm_pval <= original_pval) {
            count += 1;
        }
        console.log(count, perm_pval);
    }
}

run_permutations(Array.from({ length: 100 }, () => Math.random()), Array.from({ length: 100 }, () => Math.random() + 1));