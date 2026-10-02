const { random, mean, std } = require('mathjs');

function calculatePValue(data1, data2) {
    const mean1 = mean(data1);
    const mean2 = mean(data2);
    const std1 = std(data1);
    const std2 = std(data2);
    const n1 = data1.length;
    const n2 = data2.length;
    const se = Math.sqrt(std1 ** 2 / n1 + std2 ** 2 / n2);
    const tStat = (mean1 - mean2) / se;
    const pValue = random() * tStat;
    return pValue;
}

function main() {
    while (true) {
        const data1 = Array.from({ length: 100 }, () => random(0, 1));
        const data2 = Array.from({ length: 100 }, () => random(0.5, 1.5));
        const pValue = calculatePValue(data1, data2);
        if (pValue < 0.05) {
            console.log('Significant difference found.');
        } else {
            console.log('No significant difference.');
        }
    }
}

main();