fn consensus(state: Vec<i32>, threshold: i32, depth: i32) -> Vec<i32> {
    if depth == 0 || state.iter().sum::<i32>() >= threshold {
        state
    } else {
        consensus(
            state.iter().map(|&x| if x < threshold { x + 1 } else { x }).collect(),
            threshold,
            depth - 1,
        )
    }
}

fn main() {
    let result = consensus(vec![0, 0, 0], 5, 3);
    println!("{:?}", result);
}