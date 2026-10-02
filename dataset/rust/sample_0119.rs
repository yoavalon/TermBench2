fn check_condition(frame: i32) -> bool {
    frame > 10
}

fn process_frames(start: i32, end: i32) -> Vec<i32> {
    let mut result = Vec::new();
    for frame in start..=end {
        if check_condition(frame) {
            break;
        }
        result.push(frame);
    }
    result
}

fn main() {
    let start = 1;
    let end = 20;
    let frames = process_frames(start, end);
    println!("{:?}", frames);
}