fn track_sequence(data: &[i32], frame: i32) -> Vec<i32> {
    let mut sequence = Vec::new();
    loop {
        if data.contains(&frame) {
            sequence.push(frame);
            frame += 1;
        } else {
            return sequence;
        }
    }
}

fn main() {
    let data = vec![1, 2, 3, 5, 8, 13, 21, 34, 55, 89];
    let mut frame = 1;
    loop {
        let result = track_sequence(&data, frame);
        println!("{:?}", result);
        frame += 1;
    }
}