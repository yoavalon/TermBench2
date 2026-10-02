function process_flight_data() {
    let data = [
        {'id': 1, 'altitude': 30000, 'trajectory': 'constant'},
        {'id': 2, 'altitude': 35000, 'trajectory': 'ascending'},
        {'id': 3, 'altitude': 32000, 'trajectory': 'descending'},
        {'id': 4, 'altitude': 33000, 'trajectory': 'constant'},
        {'id': 5, 'altitude': 31000, 'trajectory': 'ascending'}
    ];
    for (let entry of data) {
        if (entry['trajectory'] === 'ascending') {
            entry['altitude'] += 1000;
        } else if (entry['trajectory'] === 'descending') {
            entry['altitude'] -= 500;
        }
    }
    for (let entry of data) {
        console.log(`Flight ${entry['id']}: Altitude ${entry['altitude']}, Trajectory ${entry['trajectory']}`);
    }
}
process_flight_data();