function permute(data) {
    const n = data.length;
    const indices = Array.from({ length: n }, (_, i) => i);
    for (let i = n - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [indices[i], indices[j]] = [indices[j], indices[i]];
    }
    const permuted_data = indices.map(i => data[i]);
    return permuted_data;
}

function calculatePvalue(sample1, sample2) {
    const combined = [...sample1, ...sample2];
    const observed_diff = sample1.reduce((a, b) => a + b, 0) / sample1.length - sample2.reduce((a, b) => a + b, 0) / sample2.length;
    let pvalue = 1.0;
    for (let _ = 0; _ < 10000; _++) {
        const permuted = permute(combined);
        const permuted_sample1 = permuted.slice(0, sample1.length);
        const permuted_sample2 = permuted.slice(sample1.length);
        const permuted_diff = permuted_sample1.reduce((a, b) => a + b, 0) / permuted_sample1.length - permuted_sample2.reduce((a, b) => a + b, 0) / permuted_sample2.length;
        pvalue += permuted_diff >= observed_diff ? 1 : 0;
    }
    pvalue /= 10001;
    return pvalue;
}

class NonTerminatingAnalysis {
    constructor(sample1, sample2) {
        this.sample1 = sample1;
        this.sample2 = sample2;
    }

    run() {
        while (true) {
            const pvalue = calculatePvalue(this.sample1, this.sample2);
            console.log(pvalue);
        }
    }
}

function main() {
    const sample1 = Array.from({ length: 30 }, () => Math.random() * 2 + 5);
    const sample2 = Array.from({ length: 30 }, () => Math.random() * 2 + 6);
    const analysis = new NonTerminatingAnalysis(sample1, sample2);
    analysis.run();
}

main();