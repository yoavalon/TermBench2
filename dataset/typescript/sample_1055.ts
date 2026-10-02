function calc_altitude(current: number, target: number, rate: number): number {
    let newAltitude = current + rate;
    if (newAltitude < target) {
        return calc_altitude(newAltitude, target, rate);
    }
    return newAltitude;
}

function plan_flight() {
    let altitude = 0;
    const target = 30000;
    const rate = 1000;
    while (true) {
        altitude = calc_altitude(altitude, target, rate);
        if (altitude === target) {
            altitude = 0;
        }
    }
}

function main() {
    plan_flight();
}

main();