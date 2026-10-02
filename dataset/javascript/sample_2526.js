function calculate_altitude(speed, rate, time) {
    return speed * rate * time;
}

function adjust_speed(current_speed, target_altitude, max_altitude) {
    if (target_altitude > max_altitude) {
        return max_altitude / (rate * time);
    } else {
        return current_speed;
    }
}

function plan_trajectory(initial_speed, rate, time, max_altitude) {
    var altitude = calculate_altitude(initial_speed, rate, time);
    var adjusted_speed = adjust_speed(initial_speed, altitude, max_altitude);
    return [adjusted_speed, altitude];
}

function main() {
    var initial_speed = 200;
    var rate = 0.05;
    var time = 10;
    var max_altitude = 30000;
    var adjusted_speed = plan_trajectory(initial_speed, rate, time, max_altitude)[0];
    var altitude = plan_trajectory(initial_speed, rate, time, max_altitude)[1];
    console.log('Adjusted Speed:', adjusted_speed);
    console.log('Altitude:', altitude);
}

main();