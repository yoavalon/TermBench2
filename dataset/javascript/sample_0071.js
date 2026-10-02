const { mean, range, random, permutation } = require('mathjs');

function permTest(data, nPermutations = 10000) {
    const origMean = mean(data);
    const permMeans = range(nPermutations).map(() => 0);
    for (let i = 0; i < nPermutations; i++) {
        const permData = permutation(data);
        permMeans[i] = mean(permData);
    }
    const pValue = (permMeans.filter(x => x >= origMean).length + 1) / (nPermutations + 1);
    return pValue;
}

if (require.main === module) {
    const data = range(100).map(() => random(-1, 1));
    const result = permTest(data);
    console.log(result);
}