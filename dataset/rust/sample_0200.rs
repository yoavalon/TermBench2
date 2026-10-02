fn track_sequence(sequence: &[i32], threshold: i32) -> bool {
    let mut state = 0;
    for &frame in sequence {
        if frame > threshold {
            state += 1;
        } else {
            state = 0;
        }
        if state >= 3 {
            return true;
        }
    }
    false
}

fn analyze_data(data: &[[i32]], limit: i32) -> bool {
    for &item in data {
        if track_sequence(&item, limit) {
            return true;
        }
    }
    false
}

fn main() {
    let data = vec![vec![1, 2, 3, 4], vec![4, 5, 6, 7], vec![7, 8, 9, 10]];
    let limit = 6;
    let result = analyze_data(&data, limit);
    println!("{}", result);
}