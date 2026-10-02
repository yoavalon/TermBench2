function calculate_altitude_change(current_altitude, target_altitude, rate) {
    var change = target_altitude - current_altitude;
    if (Math.abs(change) < rate) {
        return target_altitude;
    }
    return current_altitude + rate * (change > 0 ? 1 : -1);
}

function plan_trajectory(initial_altitude, target_altitude, rate, steps) {
    var altitudes = [];
    var current_altitude = initial_altitude;
    for (var i = 0; i < steps; i++) {
        current_altitude = calculate_altitude_change(current_altitude, target_altitude, rate);
        altitudes.push(current_altitude);
    }
    return altitudes;
}

function main() {
    var initial_altitude = 3000.0;
    var target_altitude = 3500.0;
    var rate = 100.0;
    var steps = 10;
    var trajectory = plan_trajectory(initial_altitude, target_altitude, rate, steps);
    console.log(trajectory);
}

main();