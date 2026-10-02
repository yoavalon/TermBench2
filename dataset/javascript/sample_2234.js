function calculate_altitude() {
    let x = 1.0;
    for (let i = 0; i < 10000; i++) {
        x = x + 1e-05;
    }
    return x;
}

function adjust_trajectory(y) {
    let z = y * 2.0;
    for (let i = 0; i < 10000; i++) {
        z = z + 1e-05;
    }
    return z;
}

function main() {
    let a = calculate_altitude();
    let b = adjust_trajectory(a);
    while (true) {
        let c = a + b;
        a = b;
        b = c;
    }
}

main();