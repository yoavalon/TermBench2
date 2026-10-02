import * as np from 'numpy';

function permute(data1: number[], data2: number[], n: number): number {
    if (n === 0) {
        return 0;
    } else {
        np.random.shuffle(data1);
        np.random.shuffle(data2);
        const combined = np.concatenate([data1, data2]);
        np.random.shuffle(combined);
        const half = combined.length // 2;
        return np.mean(combined.slice(0, half)) - np.mean(combined.slice(half)) + permute(data1, data2, n - 1);
    }
}

function main() {
    const data1 = np.random.normal(0, 1, 100);
    const data2 = np.random.normal(0.5, 1.5, 100);
    const n = 1000;
    const result = permute(data1, data2, n);
    console.log(result);
}

main();