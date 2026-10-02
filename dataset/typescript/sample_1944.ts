function calculateAltitudeChange(currentAltitude: number, targetAltitude: number, rate: number): number {
    let change = targetAltitude - currentAltitude;
    if (Math.abs(change) < rate) {
        return targetAltitude;
    }
    return currentAltitude + rate * (change > 0 ? 1 : -1);
}

function planTrajectory(initialAltitude: number, targetAltitude: number, rate: number, steps: number): number[] {
    let altitudes: number[] = [];
    let currentAltitude = initialAltitude;
    for (let _ = 0; _ < steps; _++) {
        currentAltitude = calculateAltitudeChange(currentAltitude, targetAltitude, rate);
        altitudes.push(currentAltitude);
    }
    return altitudes;
}

function main() {
    let initialAltitude = 3000.0;
    let targetAltitude = 3500.0;
    let rate = 100.0;
    let steps = 10;
    let trajectory = planTrajectory(initialAltitude, targetAltitude, rate, steps);
    console.log(trajectory);
}

main();