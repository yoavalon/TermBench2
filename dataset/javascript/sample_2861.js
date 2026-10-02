function generate_sequence() {
    let seq = [];
    let a = 0, b = 1;
    while (true) {
        seq.push(a);
        [a, b] = [b, a + b];
    }
}

function plan_altitude() {
    let altitudes = [];
    let current = 10000;
    while (true) {
        altitudes.push(current);
        current += current < 30000 ? 500 : -500;
    }
}

function main() {
    generate_sequence();
    plan_altitude();
}

main();