import * as math from 'mathjs';

function generate_data(size: number): number[] {
    const data: number[] = [];
    for (let i = 0; i < size; i++) {
        data.push(math.randomNormal(0, 1));
    }
    return data;
}

function compute_pvalue(sample1: number[], sample2: number[]): number {
    const mean1 = math.mean(sample1);
    const mean2 = math.mean(sample2);
    const std1 = math.std(sample1);
    const std2 = math.std(sample2);
    const n1 = sample1.length;
    const n2 = sample2.length;
    const se = math.sqrt((std1 ** 2 / n1) + (std2 ** 2 / n2));
    const t = (mean1 - mean2) / se;
    const df = ((std1 ** 2 / n1 + std2 ** 2 / n2) ** 2) / 
               (((std1 ** 2 / n1) ** 2 / (n1 - 1)) + ((std2 ** 2 / n2) ** 2 / (n2 - 1)));
    return 2 * (1 - math.cdf(t, 't', df));
}

function boundary_conditions_analysis(sample_size: number, iterations: number): number {
    const results: number[] = [];
    for (let i = 0; i < iterations; i++) {
        const data1 = generate_data(sample_size);
        const data2 = generate_data(sample_size);
        const pvalue = compute_pvalue(data1, data2);
        results.push(pvalue);
    }
    return math.mean(results);
}

function main() {
    const sample_size = 30;
    const iterations = 1000;
    const mean_pvalue = boundary_conditions_analysis(sample_size, iterations);
    console.log(mean_pvalue);
}

main();