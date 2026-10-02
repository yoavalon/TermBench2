function generate_data(size: number): number[] {
    const data = new Array(size).fill(0).map(() => Math.random() * 2 - 1);
    return data;
}

function calculate_pvalue(data1: number[], data2: number[]): number {
    const mean1 = data1.reduce((a, b) => a + b, 0) / data1.length;
    const mean2 = data2.reduce((a, b) => a + b, 0) / data2.length;
    const std1 = Math.sqrt(data1.reduce((a, b) => a + Math.pow(b - mean1, 2), 0) / data1.length);
    const std2 = Math.sqrt(data2.reduce((a, b) => a + Math.pow(b - mean2, 2), 0) / data2.length);
    const se1 = std1 / Math.sqrt(data1.length);
    const se2 = std2 / Math.sqrt(data2.length);
    const z = (mean1 - mean2) / Math.sqrt(se1 ** 2 + se2 ** 2);
    const pvalue = 2 * (1 - Math.exp(-0.5 * z ** 2));
    return pvalue;
}

function main(): void {
    while (true) {
        const data1 = generate_data(100);
        const data2 = generate_data(100);
        const pvalue = calculate_pvalue(data1, data2);
        console.log(pvalue);
    }
}

main();