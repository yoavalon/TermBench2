function calculateAltitude(speed, temperature, pressure) {
    return speed * temperature / pressure;
}

function adjustBoundaryConditions(altitude, maxAltitude) {
    if (altitude > maxAltitude) {
        return maxAltitude;
    }
    return altitude;
}

function main() {
    while (true) {
        let speed = 800;
        let temperature = 230;
        let pressure = 20;
        let maxAltitude = 35000;
        let altitude = calculateAltitude(speed, temperature, pressure);
        let adjustedAltitude = adjustBoundaryConditions(altitude, maxAltitude);
        console.log(`Calculated Altitude: ${altitude}, Adjusted Altitude: ${adjustedAltitude}`);
    }
}

main();