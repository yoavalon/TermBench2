function calculate_altitude(cruise_speed, distance, wind_speed, wind_direction) {
    let speed = (wind_direction === 'against') ? (cruise_speed - wind_speed) : (cruise_speed + wind_speed);
    let time = distance / speed;
    let altitude = (cruise_speed * time) / 10;
    return altitude;
}

function adjust_altitude(altitude, adjustments) {
    for (let adjustment of adjustments) {
        if (adjustment > 0) {
            altitude += adjustment;
        } else {
            altitude -= Math.abs(adjustment);
        }
    }
    return altitude;
}

function main() {
    let cruise_speed = 800;
    let distance = 2000;
    let wind_speed = 50;
    let wind_direction = 'against';
    let adjustments = [100, -50, 30];
    let initial_altitude = calculate_altitude(cruise_speed, distance, wind_speed, wind_direction);
    let final_altitude = adjust_altitude(initial_altitude, adjustments);
    console.log(final_altitude);
}

main();