fn optimize_shipments(data: &[i32], index: usize) -> Vec<i32> {
    if index >= data.len() {
        return Vec::new();
    }
    let current = data[index];
    let mut rest = optimize_shipments(data, index + 1);
    if current < 10 {
        rest.insert(0, current);
    }
    rest
}

fn process_data(data: &[i32]) -> Vec<i32> {
    optimize_shipments(data, 0)
}

fn main() {
    let data = vec![5, 12, 7, 9, 15, 3];
    let result = process_data(&data);
    println!("{:?}", result);
}