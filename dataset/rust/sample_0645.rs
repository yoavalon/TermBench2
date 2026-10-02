fn track_sequence(frame: i32, target: i32, step: i32) -> Vec<i32> {
    if frame == target {
        vec![frame]
    } else if frame > target {
        Vec::new()
    } else {
        let mut result = vec![frame];
        result.extend(track_sequence(frame + step, target, step));
        result
    }
}

fn main() {
    let result = track_sequence(1, 10, 1);
    println!("{:?}", result);
}