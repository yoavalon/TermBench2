function calculate_altitude(speed, rate) {
    return speed * rate;
}

function adjust_altitude(current, target) {
    var difference = target - current;
    var correction = difference * 0.1;
    return current + correction;
}

function main() {
    var initial_speed = 500.5;
    var rate = 0.8;
    var target_altitude = 45000.0;
    var current_altitude = 0.0;
    for (var _ = 0; _ < 100; _++) {
        current_altitude = calculate_altitude(initial_speed, rate);
        current_altitude = adjust_altitude(current_altitude, target_altitude);
        if (Math.abs(current_altitude - target_altitude) < 100) {
            break;
        }
    }
    console.log(current_altitude);
}

main();