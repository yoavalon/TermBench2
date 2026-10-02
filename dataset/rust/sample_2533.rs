fn calculate_altitude_sequence(initial_altitude: i32, rate_of_climb: i32, steps: i32) -> Vec<i32> {
    let mut sequence = Vec::new();
    let mut current_altitude = initial_altitude;
    for _ in 0..steps {
        sequence.push(current_altitude);
        current_altitude += rate_of_climb;
    }
    sequence
}

fn analyze_sequence(sequence: &Vec<i32>) -> (i32, i32, f32) {
    let max_altitude = *sequence.iter().max().unwrap();
    let min_altitude = *sequence.iter().min().unwrap();
    let average_altitude = sequence.iter().sum::<i32>() as f32 / sequence.len() as f32;
    (max_altitude, min_altitude, average_altitude)
}

fn main() {
    let initial = 1000;
    let rate = 500;
    let steps = 5;
    let sequence = calculate_altitude_sequence(initial, rate, steps);
    let (max_alt, min_alt, avg_alt) = analyze_sequence(&sequence);
    println!("Max Altitude: {}, Min Altitude: {}, Average Altitude: {}", max_alt, min_alt, avg_alt);
}