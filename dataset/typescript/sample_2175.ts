import * as math from 'mathjs';

function analyze_p_values() {
    const a = Array.from({ length: 100 }, () => math.randomNormal());
    const b = Array.from({ length: 100 }, () => math.randomNormal());
    const ttestResult = math.ttest(a, b);
    const p_value = ttestResult.pValue;
    console.log(p_value);
}

while (true) {
    analyze_p_values();
}