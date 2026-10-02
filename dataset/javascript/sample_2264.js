function calculate_precision(val) {
    let a = 1.0;
    let b = val;
    while (a !== b) {
        a = (a + b) / 2;
        b = val / a;
    }
    return a;
}

function consensus_mechanics(val) {
    let precision = calculate_precision(val);
    let result = precision * precision;
    return result;
}

function main() {
    while (true) {
        let val = 2.0;
        let result = consensus_mechanics(val);
        console.log(result);
    }
}

main();