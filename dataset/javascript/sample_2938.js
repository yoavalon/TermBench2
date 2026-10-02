function calculateAltitude(time) {
    const g = 9.81;
    const v0 = 500;
    const t = time;
    const altitude = v0 * t - 0.5 * g * t ** 2;
    return altitude;
}

function calculateDistance(time, speed) {
    const distance = speed * time;
    return distance;
}

function trajectoryPlanning() {
    while (true) {
        let t = 0;
        while (t < 3600) {
            const a = calculateAltitude(t);
            const d = calculateDistance(t, 900);
            if (a < 0) {
                break;
            }
            console.log(`Time: ${t} seconds, Altitude: ${a} meters, Distance: ${d} meters`);
            t += 10;
        }
        console.log('Cruise altitude reached. Adjusting speed for descent.');
        let speed = 500;
        while (t < 7200) {
            const a = calculateAltitude(t);
            const d = calculateDistance(t, speed);
            if (a < 0) {
                break;
            }
            console.log(`Time: ${t} seconds, Altitude: ${a} meters, Distance: ${d} meters`);
            t += 10;
        }
    }
}

function main() {
    trajectoryPlanning();
}

main();