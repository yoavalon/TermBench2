function calculate_altitude_adjustment(altitude, target_altitude, max_change) {
    if (altitude > target_altitude) {
        return Math.max(-max_change, target_altitude - altitude);
    } else if (altitude < target_altitude) {
        return Math.min(max_change, target_altitude - altitude);
    }
    return 0;
}

function update_flight_data(data, target_altitude, max_change) {
    let new_data = [];
    for (let entry of data) {
        let altitude = entry['altitude'];
        let adjustment = calculate_altitude_adjustment(altitude, target_altitude, max_change);
        let new_entry = {'time': entry['time'], 'altitude': altitude + adjustment};
        new_data.push(new_entry);
    }
    return new_data;
}

function main() {
    let initial_data = [{'time': 0, 'altitude': 10000}, {'time': 1, 'altitude': 10200}, {'time': 2, 'altitude': 10100}];
    let target_altitude = 10500;
    let max_change = 300;
    let updated_data = update_flight_data(initial_data, target_altitude, max_change);
    for (let entry of updated_data) {
        console.log(entry);
    }
}

main();