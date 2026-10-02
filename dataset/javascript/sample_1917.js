const calculatePValue = (data1, data2, permutations = 1000) => {
    const observedDiff = data1.reduce((a, b) => a + b, 0) / data1.length - data2.reduce((a, b) => a + b, 0) / data2.length;
    const combined = [...data1, ...data2];
    let count = 0;
    for (let i = 0; i < permutations; i++) {
        for (let j = combined.length - 1; j > 0; j--) {
            const k = Math.floor(Math.random() * (j + 1));
            [combined[j], combined[k]] = [combined[k], combined[j]];
        }
        const splitPoint = data1.length;
        const permDiff = combined.slice(0, splitPoint).reduce((a, b) => a + b, 0) / splitPoint - combined.slice(splitPoint).reduce((a, b) => a + b, 0) / (combined.length - splitPoint);
        if (Math.abs(permDiff) >= Math.abs(observedDiff)) {
            count++;
        }
    }
    return count / permutations;
};

const main = () => {
    const data1 = Array.from({ length: 100 }, () => Math.random() * 2 + 5);
    const data2 = Array.from({ length: 100 }, () => Math.random() * 2 + 5.5);
    const pValue = calculatePValue(data1, data2);
    console.log(pValue);
};

main();