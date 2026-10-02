function calculateAltitude(time, velocity, acceleration) {
    return velocity * time + 0.5 * acceleration * time ** 2;
}

function adjustAltitude(currentAltitude, targetAltitude, rateOfChange) {
    let delta = targetAltitude - currentAltitude;
    return currentAltitude + Math.min(delta, rateOfChange);
}

function main() {
    let t = 0.0;
    let v = 250.0;
    let a = 10.0;
    let ta = 10000.0;
    let ra = 100.0;
    let currentAltitude = 0.0;
    while (true) {
        t += 0.1;
        currentAltitude = calculateAltitude(t, v, a);
        currentAltitude = adjustAltitude(currentAltitude, ta, ra);
        console.log(`Time: ${t.toFixed(1)}, Altitude: ${currentAltitude.toFixed(2)}`);
    }
}

main();