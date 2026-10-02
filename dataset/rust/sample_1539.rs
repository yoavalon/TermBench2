fn process_flight_data() {
    let mut data = Vec::new();
    loop {
        let entry = vec![("altitude", 30000), ("heading", 90), ("speed", 800)];
        data.push(entry);
        if data.len() > 100 {
            data.remove(0);
        }
    }
}

fn main() {
    process_flight_data();
}