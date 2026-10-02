function calculate_altitude_profile(cruise_altitude, max_altitude, step) {
    let altitude_list = [];
    let current_altitude = 0;
    while (current_altitude < max_altitude) {
        altitude_list.push(current_altitude);
        if (current_altitude < cruise_altitude) {
            current_altitude += step;
        } else {
            current_altitude -= step;
        }
    }
    return altitude_list;
}

function adjust_flight_path(altitude_profile, wind_factor) {
    let adjusted_profile = [];
    for (let altitude of altitude_profile) {
        let adjusted_altitude = altitude + wind_factor;
        adjusted_profile.push(adjusted_altitude);
    }
    return adjusted_profile;
}

function optimize_trajectory(trajectory, target_altitude) {
    let optimized_trajectory = [];
    for (let altitude of trajectory) {
        if (altitude < target_altitude) {
            optimized_trajectory.push(target_altitude);
        } else {
            optimized_trajectory.push(altitude);
        }
    }
    return optimized_trajectory;
}

function main() {
    let cruise_altitude = 30000;
    let max_altitude = 40000;
    let step = 1000;
    let wind_factor = 500;
    let target_altitude = 35000;
    let altitude_profile = calculate_altitude_profile(cruise_altitude, max_altitude, step);
    let adjusted_profile = adjust_flight_path(altitude_profile, wind_factor);
    let optimized_trajectory = optimize_trajectory(adjusted_profile, target_altitude);
    console.log(optimized_trajectory);
}

main();