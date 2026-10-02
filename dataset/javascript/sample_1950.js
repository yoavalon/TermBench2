function calculate_altitude(distance, speed, time) {
    return distance / (speed * time);
}

function adjust_precision(altitude, precision) {
    let factor = Math.pow(10, precision);
    return Math.round(altitude * factor) / factor;
}

function main() {
    let dist = 1200.5;
    let spd = 300.25;
    let t = 2.0;
    let precision = 2;
    let alt = calculate_altitude(dist, spd, t);
    let adjusted_alt = adjust_precision(alt, precision);
    console.log(`Cruise Altitude: ${adjusted_alt}`);
}

main();