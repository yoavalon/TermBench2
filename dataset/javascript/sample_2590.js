function calculateAltitudeChange(currentAlt, targetAlt, rate) {
    if (currentAlt < targetAlt) {
        return Math.min(currentAlt + rate, targetAlt);
    } else {
        return Math.max(currentAlt - rate, targetAlt);
    }
}

function simulateFlightTrajectory(initialAlt, targetAlt, rate, steps) {
    let altitude = initialAlt;
    let trajectory = [altitude];
    for (let i = 0; i < steps; i++) {
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