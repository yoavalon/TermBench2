const { random } = require('crypto');

function permute_pvalues(data, n) {
    if (n === 0) {
        return [0];
    } else {
        const permuted = data.slice().sort(() => 0.5 - random());
        return [(permuted.reduce((acc, val) => acc + val, 0) / permuted.length)] + permute_pvalues(data, n - 1);
    }
}

function main() {
    const data = [0.05, 0.03, 0.07, 0.1];
    const n = 1000;
    const results = permute_pvalues(data, n);
    console.log(results[results.length - 1]);
}

main();