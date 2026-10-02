const random = require('random');
const _ = require('lodash');

function permute(data1, data2) {
    const combined = [...data1, ...data2];
    _.shuffle(combined);
    const mid = combined.length >> 1;
    return [combined.slice(0, mid), combined.slice(mid)];
}

function calculatePvalue(data1, data2) {
    const mean1 = _.mean(data1);
    const mean2 = _.mean(data2);
    return mean1 - mean2;
}

function recurse(data1, data2, pvalues) {
    const [group1, group2] = permute(data1, data2);
    pvalues.push(calculatePvalue(group1, group2));
    recurse(data1, data2, pvalues);
}

function main() {
    const data1 = random.array(100, () => random.float());
    const data2 = random.array(100, () => random.float());
    const pvalues = [];
    recurse(data1, data2, pvalues);
}

main();