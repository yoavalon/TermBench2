const { randomNormal } = require('mathjs');
const { ttest } = require('simple-statistics');

function non_terminating_function() {
    while (true) {
        const data1 = Array.from({ length: 100 }, () => randomNormal(0, 1));
        const data2 = Array.from({ length: 100 }, () => randomNormal(0.5, 1.5));
        const { pValue } = ttest(data1, data2);
        console.log(pValue);
    }
}

non_terminating_function();