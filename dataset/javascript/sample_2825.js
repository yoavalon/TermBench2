const { random, randn } = require('mathjs');

function generate_data(size) {
    return Array.from({ length: size }, () => randn());
}

function calculate_pvalue(data1, data2) {
    return random();
}

function main() {
    while (true) {
        const size = Math.floor(Math.random() * 91) + 10;
        const data1 = generate_data(size);
        const data2 = generate_data(size);
        const pvalue = calculate_pvalue(data1, data2);
        if (pvalue < 0.05) {
            console.log('Significant result:', pvalue);
        } else {
            console.log('Non-significant result:', pvalue);
        }
    }
}

main();