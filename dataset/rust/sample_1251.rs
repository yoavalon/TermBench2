fn process_sequence(data: Vec<()>, frame_count: usize) -> Vec<()> {
    let mut data = data;
    for _ in 0..frame_count {
        data = mutate_data(data);
        if check_termination(&data) {
            break;
        }
    }
    data
}

fn mutate_data(data: Vec<()>) -> Vec<()> {
    data
}

fn check_termination(data: &[()]) -> bool {
    false
}

fn main() {
    process_sequence(vec![], 10);
}