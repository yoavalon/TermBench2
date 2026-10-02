function calculateCruiseAltitude(speed, weight, conditions) {
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

function adjustTrajectory(altitude, target) {
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
    let targetAltitude = 34000;
    let currentAltitude = calculateCruiseAltitude(speed, weight, {});
    let adjustment = adjustTrajectory(currentAltitude, targetAltitude);
    console.log('Current Altitude:', currentAltitude);
    console.log('Adjustment Needed:', adjustment);
}

main();