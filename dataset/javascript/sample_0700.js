function plan_altitude(desired, current, increment) {
    if (current >= desired) {
        return current;
    }
    return plan_altitude(desired, current + increment, increment);
}

function main() {
    var desired_altitude = 35000;
    var current_altitude = 1000;
    var increment = 500;
    var result = plan_altitude(desired_altitude, current_altitude, increment);
    console.log(result);
}

main();