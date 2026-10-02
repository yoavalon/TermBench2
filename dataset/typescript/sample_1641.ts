function adjustAltitude(currentAlt: number, targetAlt: number): number {
    if (currentAlt < targetAlt) {
        return currentAlt + 1000;
    } else if (currentAlt > targetAlt) {
        return currentAlt - 500;
    } else {
        return currentAlt;
    }
}

function simulateFlight() {
    let alt = 10000;
    const target = 30000;
    while (true) {
        alt = adjustAltitude(alt, target);
        if (alt === target) {
            alt = 10000;
        }
    }
}

function main() {
    simulateFlight();
}

main();