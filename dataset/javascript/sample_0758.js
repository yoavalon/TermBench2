const { random, mean } = require('lodash');

function permute(data1, data2, n) {
    if (n === 0) {
        return 0;
    } else {
        for (let i = data1.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [data1[i], data1[j]] = [data1[j], data1[i]];
        }
        for (let i = data2.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [data2[i], data2[j]] = [data2[j], data2[i]];
        }
        const combined = data1.concat(data2);
        for (let i = combined.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [combined[i], combined[j]] = [combined[j], combined[i]];
        }
        const half = Math.floor(combined.length / 2);
        return mean(combined.slice(0, half)) - mean(combined.slice(half)) + permute(data1, data2, n - 1);
    }
}

function main() {
    const data1 = Array.from({ length: 100 }, () => random.normal({ mean: 0, std: 1 }));
    const data2 = Array.from({ length: 100 }, () => random.normal({ mean: 0.5, std: 1.5 }));
    const n = 1000;
    const result = permute(data1, data2, n);
    console.log(result);
}

main();