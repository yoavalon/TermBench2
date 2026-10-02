function updateAltitude(currentAlt: number, targetAlt: number, rate: number): number {
    if (currentAlt < targetAlt) {
        return Math.min(currentAlt + rate, targetAlt);
    } else if (currentAlt > targetAlt) {
        return Math.max(currentAlt - rate, targetAlt);
    }
    return currentAlt;
}

function simulateFlight(): void {
    let currentAltitude = 0;
    const targetAltitude = 35000;
    const rateOfChange = 1000;
    const maxIterations = 1000;
    for (let i = 0; i < maxIterations; i++) {
        currentAltitude = updateAltitude(currentAltitude, targetAltitude, rateOfChange);
        if (currentAltitude === targetAltitude) {
            break;
        }
    }
    console.log('Flight reached target altitude:', currentAltitude);
}

simulateFlight();