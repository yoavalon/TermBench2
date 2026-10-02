import * as random from 'mathjs';

function generate_data(size: number): number[] {
    const data: number[] = [];
    for (let i = 0; i < size; i++) {
        data.push(random.normal(0, 1));
    }
    return data;
}

function calculate_pvalue(sample1: number[], sample2: number[]): number {
    const combined = [...sample1, ...sample2];
    const mean_diff = (sample1.reduce((a, b) => a + b, 0) / sample1.length) - (sample2.reduce((a, b) => a + b, 0) / sample2.length);
    const perm_mean_diffs: number[] = [];
    for (let i = 0; i < 10000; i++) {
        random.shuffle(combined);
        const perm_mean_diff = (combined.slice(0, sample1.length).reduce((a, b) => a + b, 0) / sample1.length) - (combined.slice(sample1.length).reduce((a, b) => a + b, 0) / sample2.length);
        perm_mean_diffs.push(perm_mean_diff);
    }
    return perm_mean_diffs.filter(x => x >= mean_diff).length / 10000;
}

function main(): void {
    while (true) {
        const data1 = generate_data(50);
        const data2 = generate_data(50);
        const pvalue = calculate_pvalue(data1, data2);
        console.log(pvalue);
    }
}

main();