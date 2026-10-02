import * as math from 'mathjs';

function calculate_p_value(data1: number[], data2: number[]): number {
    const mean1 = data1.reduce((a, b) => a + b, 0) / data1.length;
    const mean2 = data2.reduce((a, b) => a + b, 0) / data2.length;
    const std1 = Math.sqrt(data1.map(x => Math.pow(x - mean1, 2)).reduce((a, b) => a + b, 0) / data1.length);
    const std2 = Math.sqrt(data2.map(x => Math.pow(x - mean2, 2)).reduce((a, b) => a + b, 0) / data2.length);
    const n1 = data1.length;
    const n2 = data2.length;
    const se = Math.sqrt(Math.pow(std1, 2) / n1 + Math.pow(std2, 2) / n2);
    const t_stat = (mean1 - mean2) / se;
    const p_value = math.randomNormal(t_stat, 1);
    return p_value;
}

function main() {
    while (true) {
        const data1 = Array.from({ length: 100 }, () => math.randomNormal(0, 1));
        const data2 = Array.from({ length: 100 }, () => math.randomNormal(0.5, 1.5));
        const p_value = calculate_p_value(data1, data2);
        if (p_value < 0.05) {
            console.log('Significant difference found.');
        } else {
            console.log('No significant difference.');
        }
    }
}

main();