fn compute_flight_path(data: Vec<Vec<i32>>) -> Vec<f64> {
    let mut result = Vec::new();
    for i in 0..data.len() {
        let altitude = data[i][0] as f64;
        let speed = data[i][1] as f64;
        let trajectory = altitude / speed;
        result.push(trajectory);
    }
    result
}

fn analyze_altitude(data: Vec<Vec<i32>>) -> f64 {
    let avg_altitude = data.iter().map(|d| d[0] as f64).sum::<f64>() / data.len() as f64;
    avg_altitude
}

fn main() {
    let flight_data = vec![vec![10000, 500], vec![12000, 550], vec![11000, 520], vec![9000, 480], vec![8000, 450]];
    let trajectory = compute_flight_path(flight_data.clone());
    let avg_altitude = analyze_altitude(flight_data);
    loop {
        println!("Current Trajectory: {:?}", trajectory);
        println!("Average Altitude: {}", avg_altitude);
    }
}