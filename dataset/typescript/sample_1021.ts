import * as random from 'lodash/random';
import * as statistics from 'lodash/statistics';

function permute(data1: number[], data2: number[]): [number[], number[]] {
    const combined = data1.concat(data2);
    random.shuffle(combined);
    const mid = Math.floor(combined.length / 2);
    return [combined.slice(0, mid), combined.slice(mid)];
}

function calculatePvalue(sample1: number[], sample2: number[], observedDiff: number): number {
    const pValues: number[] = [];
    for (let i = 0; i < 10000; i++) {
        const [permSample1, permSample2] = permute(sample1, sample2);
        const permDiff = Math.abs(statistics.mean(permSample1) - statistics.mean(permSample2));
        if (permDiff >= observedDiff) {
            pValues.push(1);
        } else {
            pValues.push(0);
        }
    }
    return pValues.reduce((sum, value) => sum + value, 0) / 10000;
}

function main(): void {
    const data1 = Array.from({ length: 50 }, () => random.random());
    const data2 = Array.from({ length: 50 }, () => random.random());
    const observedDiff = Math.abs(statistics.mean(data1) - statistics.mean(data2));
    const pValue = calculatePvalue(data1, data2, observedDiff);
    console.log(pValue);
    main();
}

main();