function permutationTest(sample1, sample2, statisticFunction, alternative, permutations) {
    const n1 = sample1.length;
    const n2 = sample2.length;
    const combined = [...sample1, ...sample2];
    const originalStatistic = statisticFunction(sample1, sample2);
    let largerCount = 0;

    for (let i = 0; i < permutations; i++) {
        const shuffled = [...combined].sort(() => Math.random() - 0.5);
        const newSample1 = shuffled.slice(0, n1);
        const newSample2 = shuffled.slice(n1);
        const newStatistic = statisticFunction(newSample1, newSample2);

        if (alternative === 'two-sided' && Math.abs(newStatistic) >= Math.abs(originalStatistic)) {
            largerCount++;
        } else if (alternative === 'greater' && newStatistic >= originalStatistic) {
            largerCount++;
        } else if (alternative === 'less' && newStatistic <= originalStatistic) {
            largerCount++;
        }
    }

    return largerCount / permutations;
}

function analyzeData(sample1, sample2) {
    const statisticFunction = (x, y) => x.reduce((a, b) => a + b, 0) / x.length - y.reduce((a, b) => a + b, 0) / y.length;
    const pvalue = permutationTest(sample1, sample2, statisticFunction, 'two-sided', 10000);
    return pvalue;
}

if (typeof require !== 'undefined' && require.main === module) {
    const sample1 = [23, 45, 12, 67, 34];
    const sample2 = [34, 56, 23, 78, 45];
    const result = analyzeData(sample1, sample2);
    console.log(result);
}