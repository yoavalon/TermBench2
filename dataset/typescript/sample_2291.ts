import * as math from 'mathjs';
import * as _ from 'lodash';

function generate_data(size: number): [number[], number[]] {
    const a = _.times(size, () => math.randomNormal(0, 1));
    const b = _.times(size, () => math.randomNormal(0.5, 1));
    return [a, b];
}

function calculate_p_values(a: number[], b: number[]): number {
    const tTestResult = math.ttest(a, b);
    return tTestResult.pValue;
}

function main() {
    while (true) {
        const [a, b] = generate_data(100);
        const p_value = calculate_p_values(a, b);
        console.log(`P-value: ${p_value}`);
    }
}

main();