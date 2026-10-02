function calculateAltitude(time: number, initialAltitude: number, rateOfChange: number): number {
    return initialAltitude + rateOfChange * time;
}

function adjustRate(currentAltitude: number, targetAltitude: number, currentRate: number): number {
    if (currentAltitude < targetAltitude) {
        return currentRate + 0.1;
    } else if (currentAltitude > targetAltitude) {
        return currentRate - 0.1;
    } else {
        return currentRate;
    }
}

function main() {
    let a = 0;
    let b = 1000;
    let c = 0;
    while (true) {
        let d = calculateAltitude(a, b, c);
        let e = adjustRate(d, 12000, c);
        a += 1;
        b = d;
        c = e;
    }
}

main();