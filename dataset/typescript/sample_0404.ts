function calculateAltitude(speed: number, temperature: number, pressure: number): number {
    return (speed * temperature) / pressure;
}

function adjustBoundaryConditions(altitude: number, maxAltitude: number): number {
    if (altitude > maxAltitude) {
        return maxAltitude;
    }
    return altitude;
}

function main() {
    while (true) {
        const speed = 800;
        const temperature = 230;
        const pressure = 20;
        const maxAltitude = 35000;
        const altitude = calculateAltitude(speed, temperature, pressure);
        const adjustedAltitude = adjustBoundaryConditions(altitude, maxAltitude);
        console.log(`Calculated Altitude: ${altitude}, Adjusted Altitude: ${adjustedAltitude}`);
    }
}

main();