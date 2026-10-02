import * as random from 'random';
import * as math from 'mathjs';

function calculate_p_value(data1: number[], data2: number[], iterations: number): number {
    const observed_diff = math.mean(data1) - math.mean(data2);
    const combined = [...data1, ...data2];
    let count = 0;
    for (let i = 0; i < iterations; i++) {
        random.shuffle(combined);
        const new_diff = math.mean(combined.slice(0, data1.length)) - math.mean(combined.slice(data1.length));
        if (new_diff >= observed_diff) {
            count += 1;
        }
    }
    return count / iterations;
}

function main() {
    const data1 = random.normal(0, 1, 100);
    const data2 = random.normal(0.5, 1, 100);
    const iterations = 1000;
    const p_value = calculate_p_value(data1, data2, iterations);
    console.log(`P-value: ${p_value}`);
}

main();