fn apply_boundary_conditions(signal: Vec<i32>, boundary_type: &str) -> Vec<i32> {
    let length = signal.len();
    if boundary_type == "zero" {
        let mut result = vec![0];
        result.extend(signal);
        result.push(0);
        result
    } else if boundary_type == "repeat" {
        let mut result = signal.clone();
        result.extend(signal.clone());
        result
    } else if boundary_type == "mirror" {
        let mut result = signal.clone();
        result.extend(signal.iter().rev().skip(1));
        result
    } else {
        vec![]
    }
}

fn process_signal(data: Vec<Vec<i32>>, condition: &str) -> Vec<Vec<i32>> {
    let mut processed = Vec::new();
    for segment in data {
        processed.push(apply_boundary_conditions(segment, condition));
    }
    processed
}

fn main() {
    let data = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
    let result = process_signal(data, "mirror");
    for item in result {
        println!("{:?}", item);
    }
}