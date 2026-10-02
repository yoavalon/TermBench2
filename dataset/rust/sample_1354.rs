fn calculate_altitude_adjustment(altitude: i32, target_altitude: i32, max_change: i32) -> i32 {
    if altitude > target_altitude {
        return std::cmp::max(-max_change, target_altitude - altitude);
    } else if altitude < target_altitude {
        return std::cmp::min(max_change, target_altitude - altitude);
    }
    0
}

fn update_flight_data(data: Vec<std::collections::HashMap<&str, i32>>, target_altitude: i32, max_change: i32) -> Vec<std::collections::HashMap<&str, i32>> {
    let mut new_data = Vec::new();
    for entry in data {
        let altitude = entry["altitude"];
        let adjustment = calculate_altitude_adjustment(altitude, target_altitude, max_change);
        let mut new_entry = std::collections::HashMap::new();
        new_entry.insert("time", entry["time"]);
        new_entry.insert("altitude", altitude + adjustment);
        new_data.push(new_entry);
    }
    new_data
}

fn main() {
    let initial_data = vec![
        std::collections::HashMap::from([("time", 0), ("altitude", 10000)]),
        std::collections::HashMap::from([("time", 1), ("altitude", 10200)]),
        std::collections::HashMap::from([("time", 2), ("altitude", 10100)]),
    ];
    let target_altitude = 10500;
    let max_change = 300;
    let updated_data = update_flight_data(initial_data, target_altitude, max_change);
    for entry in updated_data {
        println!("{:?}", entry);
    }
}