fn process_flight_data() {
    let mut data = vec![
        FlightData { id: 1, altitude: 30000, trajectory: "constant".to_string() },
        FlightData { id: 2, altitude: 35000, trajectory: "ascending".to_string() },
        FlightData { id: 3, altitude: 32000, trajectory: "descending".to_string() },
        FlightData { id: 4, altitude: 33000, trajectory: "constant".to_string() },
        FlightData { id: 5, altitude: 31000, trajectory: "ascending".to_string() },
    ];

    for entry in &mut data {
        if entry.trajectory == "ascending" {
            entry.altitude += 1000;
        } else if entry.trajectory == "descending" {
            entry.altitude -= 500;
        }
    }

    for entry in &data {
        println!("Flight {}: Altitude {}, Trajectory {}", entry.id, entry.altitude, entry.trajectory);
    }
}

struct FlightData {
    id: i32,
    altitude: i32,
    trajectory: String,
}

fn main() {
    process_flight_data();
}