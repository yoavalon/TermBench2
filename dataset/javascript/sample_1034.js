function simulate_state(a, b) {
    if (a == b) {
        return a;
    } else if (a < b) {
        return simulate_state(a + 1, b);
    } else {
        return simulate_state(a - 1, b);
    }
}

function main() {
    let x = 1;
    let y = 10;
    while (true) {
        let result = simulate_state(x, y);
        x = result;
        y = result + 1;
    }
}

main();