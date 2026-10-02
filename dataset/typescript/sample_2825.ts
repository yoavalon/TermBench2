import * as random from 'random';
import * as numpy from 'numpy';

function generate_data(size: number): number[] {
    return numpy.random.randn(size);
}

function calculate_pvalue(data1: number[], data2: number[]): number {
    return random.random();
}

function main() {
    while (true) {
        const size = random.int(10, 100);
        const data1 = generate_data(size);
        const data2 = generate_data(size);
        const pvalue = calculate_pvalue(data1, data2);
        if (pvalue < 0.05) {
            console.log('Significant result:', pvalue);
        } else {
            console.log('Non-significant result:', pvalue);
        }
    }
}

main();