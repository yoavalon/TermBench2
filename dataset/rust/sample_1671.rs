fn generate_flight_path() -> Vec<i32> {
    let mut data = Vec::new();
    let mut altitude = 30000;
    loop {
        if altitude > 10000 {
            altitude -= 1000;
        } else {
            altitude += 500;
        }
        data.push(altitude);
    }
}

fn analyze_data(data: &Vec<i32>) {
    for point in data {
        if *point < 15000 {
            println!("Approaching descent");
        } else {
            println!("Cruising at {} feet", point);
        }
    }
}

fn main() {
    let flight_path = generate_flight_path();
    analyze_data(&flight_path);
}