function permutePvalue(data: number[], permCount: number): number {
    const np = require('numjs');
    const stats = require('scipy');

    const obsStat = np.mean(data).tolist();
    const permStats: number[] = [];

    for (let i = 0; i < permCount; i++) {
        const permData = np.random.permutation(data).tolist();
        permStats.push(np.mean(permData).tolist());
    }

    const pVal = permStats.filter(stat => stat >= obsStat).length / permCount;
    return pVal;
}

const data = [1, 2, 3, 4, 5];
const permCount = 1000;
const result = permutePvalue(data, permCount);
console.log(result);