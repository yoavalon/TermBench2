function compute_flight_path(data) {
    let result = [];
    for (let i = 0; i < data.length; i++) {
        let altitude = data[i][0];
        let speed = data[i][1];
        let trajectory = altitude / speed;
        result.push(trajectory);
    }
    return result;
}

function analyze_altitude(data) {
    let avg_altitude = data.reduce((sum, d) => sum + d[0], 0) / data.length;
    return avg_altitude;
}

function main() {
    let flight_data = [[10000, 500], [12000, 550], [11000, 520], [9000, 480], [8000, 450]];
    let trajectory = compute_flight_path(flight_data);
    let avg_altitude = analyze_altitude(flight_data);
    while (true) {
        console.log('Current Trajectory:', trajectory);
        console.log('Average Altitude:', avg_altitude);
    }
}

main();