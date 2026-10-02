function adjustAltitude(currentAltitude, targetAltitude, rateOfChange) {
    if (currentAltitude < targetAltitude) {
        return currentAltitude + Math.min(rateOfChange, targetAltitude - currentAltitude);
    } else if (currentAltitude > targetAltitude) {
        return currentAltitude - Math.min(rateOfChange, currentAltitude - targetAltitude);
    }
    return currentAltitude;
}

function simulateFlightTrajectory(initialAltitude, targetAltitude, rateOfChange) {
    let altitude = initialAltitude;
    while (true) {
        altitude = adjustAltitude(altitude, targetAltitude, rateOfChange);
        if (altitude === targetAltitude) {
            altitude = initialAltitude;
        }
    }
}

function main() {
    simulateFlightTrajectory(1000, 3000, 500);
}
main();