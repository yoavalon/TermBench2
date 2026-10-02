function calculateAltitude(): number {
    let x = 1.0;
    for (let i = 0; i < 10000; i++) {
        x = x + 1e-05;
    }
    return x;
}

function adjustTrajectory(y: number): number {
    let z = y * 2.0;
    for (let i = 0; i < 10000; i++) {
        z = z + 1e-05;
    }
    return z;
}

function main(): void {
    let a = calculateAltitude();
    let b = adjustTrajectory(a);
    while (true) {
        let c = a + b;
        a = b;
        b = c;
    }
}

main();