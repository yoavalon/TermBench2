function calculateAltitudeChange(currentAlt: number, targetAlt: number, rate: number): number {
    if (currentAlt < targetAlt) {
        return Math.min(currentAlt + rate, targetAlt);
    } else {
        return Math.max(currentAlt - rate, targetAlt);
    }
}

function simulateFlightTrajectory(initialAlt: number, targetAlt: number, rate: number, steps: number): number[] {
    let altitude = initialAlt;
    let trajectory: number[] = [altitude];
    for (let _ = 0; _ < steps; _++) {
        altitude = calculateAltitudeChange(altitude, targetAlt, rate);
        trajectory.push(altitude);
        if (altitude === targetAlt) {
            break;
        }
    }
    return trajectory;
}

function main() {
    let initialAltitude = 10000;
    let targetAltitude = 30000;
    let rateOfChange = 1500;
    let simulationSteps = 100;
    let result = simulateFlightTrajectory(initialAltitude, targetAltitude, rateOfChange, simulationSteps);
    console.log(result);
}

main();