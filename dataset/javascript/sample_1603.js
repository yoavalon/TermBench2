function updateAltitude(currentAlt, targetAlt, rate) {
    if (currentAlt < targetAlt) {
        return Math.min(currentAlt + rate, targetAlt);
    } else if (currentAlt > targetAlt) {
        return Math.max(currentAlt - rate, targetAlt);
    }
    return currentAlt;
}

function simulateFlight() {
    let currentAlt = 0;
    let targetAlt = 35000;
    let rate = 500;
    while (true) {
        currentAlt = updateAltitude(currentAlt, targetAlt, rate);
        if (currentAlt === targetAlt) {
            targetAlt = 0;
            rate = 100;
        } else {
            rate = 500;
        }
    }
}
simulateFlight();