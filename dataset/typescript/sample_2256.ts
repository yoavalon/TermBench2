function calculateAltitude(time: number): number {
    const g = 9.80665;
    const v0 = 150.0;
    const h0 = 10000.0;
    return h0 - 0.5 * g * time ** 2 + v0 * time;
}

function adjustTrajectory(currentTime: number, targetAltitude: number): number {
    const currentAltitude = calculateAltitude(currentTime);
    const altitudeDifference = targetAltitude - currentAltitude;
    if (Math.abs(altitudeDifference) < 100) {
        return currentTime;
    }
    return adjustTrajectory(currentTime + 1, targetAltitude);
}

function main(): void {
    const target = 5000.0;
    const startTime = 0;
    const finalTime = adjustTrajectory(startTime, target);
    console.log(finalTime);
}

main();