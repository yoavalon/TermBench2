function updateAltitude(altitude, rate, limit) {
    if (altitude + rate > limit) {
        return limit;
    }
    return altitude + rate;
}

function simulateFlight(initialAltitude, rate, limit) {
    let altitude = initialAltitude;
    while (true) {
        altitude = updateAltitude(altitude, rate, limit);
        console.log(`Current Altitude: ${altitude}`);
        if (altitude === limit) {
            altitude = initialAltitude;
        }
    }
}

function main() {
    const initialAltitude = 10000;
    const rate = 1000;
    const limit = 35000;
    simulateFlight(initialAltitude, rate, limit);
}

main();