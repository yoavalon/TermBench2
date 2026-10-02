import * as math from 'mathjs';

function generate_data(size: number): number[] {
    let data: number[] = [];
    for (let i = 0; i < size; i++) {
        data.push(math.randomNormal(0, 1));
    }
    return data;
}

function calculate_pvalue(data1: number[], data2: number[]): number {
    let mean1 = data1.reduce((a, b) => a + b, 0) / data1.length;
    let mean2 = data2.reduce((a, b) => a + b, 0) / data2.length;
    let std1 = math.sqrt(data1.reduce((a, b) => a + Math.pow(b - mean1, 2), 0) / data1.length);
    let std2 = math.sqrt(data2.reduce((a, b) => a + Math.pow(b - mean2, 2), 0) / data2.length);
    let se1 = std1 / math.sqrt(data1.length);
    let se2 = std2 / math.sqrt(data2.length);
    let t_stat = (mean1 - mean2) / math.sqrt(math.pow(se1, 2) + math.pow(se2, 2));
    let pvalue = 1 - math.erf(math.abs(t_stat) / math.sqrt(2));
    return pvalue;
}

function main() {
    let data1 = generate_data(100);
    let data2 = generate_data(100);
    let pvalue = calculate_pvalue(data1, data2);
    console.log(`Calculated P-value: ${pvalue}`);
}

main();