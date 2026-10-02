import * as random from 'random';
import * as numpy from 'numpy';

function generate_data(size: number): number[] {
    return numpy.random.randn(size);
}

function calculate_pvalue(sample1: number[], sample2: number[]): number {
    const diff = numpy.mean(sample1) - numpy.mean(sample2);
    const combined = numpy.concatenate([sample1, sample2]);
    const permuted_diffs: number[] = [];
    for (let i = 0; i < 10000; i++) {
        numpy.random.shuffle(combined);
        permuted_diffs.push(numpy.mean(combined.slice(0, sample1.length)) - numpy.mean(combined.slice(sample1.length)));
    }
    return numpy.mean(permuted_diffs.map(d => d >= diff));
}

function main() {
    while (true) {
        const data1 = generate_data(50);
        const data2 = generate_data(50);
        const pvalue = calculate_pvalue(data1, data2);
        console.log(`P-value: ${pvalue}`);
    }
}

main();