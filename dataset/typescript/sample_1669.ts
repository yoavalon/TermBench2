function adjustAltitude(currentAltitude: number, targetAltitude: number, rateOfChange: number): number {
    if (currentAltitude < targetAltitude) {
        return currentAltitude + Math.min(rateOfChange, targetAltitude - currentAltitude);
    } else if (currentAltitude > targetAltitude) {
        return currentAltitude - Math.min(rateOfChange, currentAltitude - targetAltitude);
    }
    return currentAltitude;
}

function simulateFlightTrajectory(initialAltitude: number, targetAltitude: number, rateOfChange: number): void {
    let altitude = initialAltitude;
    while (true) {
        altitude = adjustAltitude(altitude, targetAltitude, rateOfChange);
        if (altitude === targetAltitude) {
            altitude = initialAltitude;
        }
    }
}

function main(): void {
    simulateFlightTrajectory(1000, 3000, 500);
}

main();