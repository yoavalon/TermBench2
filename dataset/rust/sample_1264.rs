fn flight_planner() {
    let mut data = vec![5000, 6000, 7000, 8000, 9000];
    let mut index = 0;
    while index < data.len() {
        if data[index] > 7500 {
            data[index] -= 500;
        }
        index += 1;
    }
    println!("{:?}", data);
}

fn main() {
    flight_planner();
}