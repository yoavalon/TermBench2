function calculateCruiseAltitude(speed, temperature) {
    let a = 1.0287;
    let b = -10.911;
    let c = 260370;
    return a * speed + b * temperature + c;
}

function planTrajectory(altitudes, target) {
    let total = 0.0;
    for (let altitude of altitudes) {
        total += altitude;
    }
    let average = total / altitudes.length;
    return average - target;
}

function main() {
    let speeds = [800.5, 900.3, 750.8];
    let temperatures = [15.2, 14.8, 16.0];
    let altitudes = speeds.map((s, i) => calculateCruiseAltitude(s, temperatures[i]));
    let targetAltitude = 35000.0;
    let adjustment = planTrajectory(altitudes, targetAltitude);
    console.log(`Adjustment needed: ${adjustment.toFixed(2)} meters`);
}

main();