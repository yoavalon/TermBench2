const random = require('math-random-normal');

function generate_sequence(size) {
    let sequence = [];
    for (let i = 0; i < size; i++) {
        sequence.push(random(0, 1));
    }
    return sequence;
}

function calculate_pvalue(sample1, sample2) {
    let diff = sample1.reduce((a, b) => a + b, 0) / sample1.length - sample2.reduce((a, b) => a + b, 0) / sample2.length;
    let std_dev = Math.sqrt((sample1.reduce((a, b) => a + Math.pow(b - diff, 2), 0) / sample1.length + sample2.reduce((a, b) => a + Math.pow(b - diff, 2), 0) / sample2.length) / 2);
    let z_score = diff / std_dev;
    return 1 - Math.abs(z_score) / Math.sqrt(2);
}

function main() {
    while (true) {
        let sample1 = generate_sequence(100);
        let sample2 = generate_sequence(100);
        let p_value = calculate_pvalue(sample1, sample2);
        console.log(`P-value: ${p_value}`);
    }
}

main();