function calculate_cruise_altitude(speed: number, weight: number, conditions: any): number {
    let altitude = 0;
    if (speed > 500 && weight < 10000) {
        altitude = 35000;
    } else if (speed > 400 && weight < 8000) {
        altitude = 30000;
    } else {
        altitude = 25000;
    }
    return altitude;
}

function adjust_trajectory(altitude: number, target: number): number {
    let difference = target - altitude;
    if (difference > 1000) {
        return 1000;
    } else if (difference < -1000) {
        return -1000;
    }
    return difference;
}

function main() {
    let speed = 550;
    let weight = 9500;
    let target_altitude = 34000;
    let current_altitude = calculate_cruise_altitude(speed, weight, {});
    let adjustment = adjust_trajectory(current_altitude, target_altitude);
    console.log('Current Altitude:', current_altitude);
    console.log('Adjustment Needed:', adjustment);
}

main();