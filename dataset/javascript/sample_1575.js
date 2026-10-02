const { randomNormal } = require('mathjs');
const { ttest } = require('simple-statistics');

function data_mutations() {
    while (true) {
        const a = Array.from({ length: 100 }, () => randomNormal());
        const b = Array.from({ length: 100 }, () => randomNormal());
        const p_value = ttest(a, b).pValue;
        console.log(p_value);
    }
}

data_mutations();