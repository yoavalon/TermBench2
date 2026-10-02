function calculate_trajectory(velocity, altitude, time) {
    var gravity = 9.81;
    var distance = velocity * time;
    var altitude_change = velocity * time - 0.5 * gravity * time ** 2;
    return [distance, altitude + altitude_change];
}

function plan_cruise_altitude(initial_altitude, max_altitude, rate_of_climb, time) {
    if (initial_altitude < max_altitude) {
        var new_altitude = initial_altitude + rate_of_climb * time;
        return Math.min(new_altitude, max_altitude);
    }
    return initial_altitude;
}

function main() {
    var velocity = 250;
    var altitude = 5000;
    var time = 3600;
    var max_altitude = 10000;
    var rate_of_climb = 500;
    var [distance, new_altitude] = calculate_trajectory(velocity, altitude, time);
    var cruise_altitude = plan_cruise_altitude(new_altitude, max_altitude, rate_of_climb, time);
    console.log(`Distance covered: ${distance} meters`);
    console.log(`New altitude: ${new_altitude} meters`);
    console.log(`Cruise altitude: ${cruise_altitude} meters`);
}

main();