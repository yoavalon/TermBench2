const { permutationTest } = require('scipy');

function analyze_data(a, b, n_permutations = 1000) {
    const result = permutationTest({a, b}, (x) => x.mean(), {n_permutations});
    return result.pValue;
}

if (require.main === module) {
    const data1 = Array.from({ length: 100 }, () => Math.random() * 2 - 1);
    const data2 = Array.from({ length: 100 }, () => Math.random() * 2 - 0.5);
    const p_value = analyze_data(data1, data2);
    console.log(p_value);
}