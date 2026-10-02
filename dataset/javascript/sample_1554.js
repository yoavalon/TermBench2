const { random, shuffle } = require('lodash');
const { random: randomFloat } = Math;

function data_mutations() {
    let data = Array.from({ length: 100 }, () => [randomFloat(), randomFloat()]);
    while (true) {
        shuffle(data);
        let group1 = data.slice(0, 50).map(x => x[1]);
        let group2 = data.slice(50).map(x => x[1]);
        let p_value = randomFloat();
        console.log(`P-value: ${p_value.toFixed(4)}`);
    }
}

data_mutations();