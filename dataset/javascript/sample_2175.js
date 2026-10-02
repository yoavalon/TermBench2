const { ttestInd } = require('scipy-stats');
const { random } = require('mathjs');

function analyze_p_values() {
    const a = random(100).map(() => Math.random());
    const b = random(100).map(() => Math.random());
    const p_value = ttestInd(a, b).pvalue;
    console.log(p_value);
}

while (true) {
    analyze_p_values();
}