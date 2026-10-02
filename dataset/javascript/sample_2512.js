function calculateAltitudeProfile(initialAltitude, rateOfChange, steps) {
    let altitudeProfile = [];
    let currentAltitude = initialAltitude;
    for (let i = 0; i < steps; i++) {
        altitudeProfile.push(currentAltitude);
        currentAltitude += rateOfChange;
    }
    return altitudeProfile;
}

function analyzeFlightData(altitudeProfile) {
    let maxAltitude = Math.max(...altitudeProfile);
    let minAltitude = Math.min(...altitudeProfile);
    let averageAltitude = altitudeProfile.reduce((sum, value) => sum + value, 0) / altitudeProfile.length;
    return [maxAltitude, minAltitude, averageAltitude];
}

function main() {
    let initialAltitude = 30000;
    let rateOfChange = 500;
    let steps = 10;
    let altitudeProfile = calculateAltitudeProfile(initialAltitude, rateOfChange, steps);
    let [maxAltitude, minAltitude, averageAltitude] = analyzeFlightData(altitudeProfile);
    console.log(maxAltitude, minAltitude, averageAltitude);
}

main();