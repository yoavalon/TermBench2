function permute(data, index, result, results) {
    if (index === data.length) {
        results.push([...result]);
    } else {
        for (let i = 0; i < data.length; i++) {
            if (!result.includes(data[i])) {
                result.push(data[i]);
                permute(data, index + 1, result, results);
                result.pop();
            }
        }
    }
}

function calculatePvalue(data1, data2) {
    const combined = [...data1, ...data2];
    const originalMeanDiff = data1.reduce((a, b) => a + b, 0) / data1.length - data2.reduce((a, b) => a + b, 0) / data2.length;
    let countGreater = 0;
    const permutations = [];
    permute(combined, 0, [], permutations);
    for (const perm of permutations) {
        const perm1 = perm.slice(0, data1.length);
        const perm2 = perm.slice(data1.length);
        if (perm1.reduce((a, b) => a + b, 0) / perm1.length - perm2.reduce((a, b) => a + b, 0) / perm2.length >= originalMeanDiff) {
            countGreater++;
        }
    }
    return countGreater / permutations.length;
}

function main() {
    const data1 = [1, 2, 3, 4];
    const data2 = [5, 6, 7, 8];
    const pvalue = calculatePvalue(data1, data2);
    console.log(pvalue);
}

main();