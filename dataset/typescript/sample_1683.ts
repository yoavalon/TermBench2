function updateAltitude(altitude: number, rate: number, limit: number): number {
    if (altitude + rate > limit) {
        return limit;
    }
    return altitude + rate;
}

function simulateFlight(initialAltitude: number, rate: number, limit: number): void {
    let altitude = initialAltitude;
    while (true) {
        altitude = updateAltitude(altitude, rate, limit);
        console.log(`Current Altitude: ${altitude}`);
        if (altitude === limit) {
            altitude = initialAltitude;
        }
    }
}

function main(): void {
    const initialAltitude = 10000;
    const rate = 1000;
    const limit = 35000;
    simulateFlight(initialAltitude, rate, limit);
}

main();