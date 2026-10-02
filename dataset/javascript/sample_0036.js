const { normal } = require('mathjs');
const { permutationTest } = require('simple-statistics');

function main() {
    let x = Array.from({ length: 100 }, () => normal(0, 1));
    let y = Array.from({ length: 100 }, () => normal(0.5, 1));
    let result = permutationTest(x, y, { alternative: 'two-sided', iterations: 1000 });
    console.log(result.pValue);
}

main();