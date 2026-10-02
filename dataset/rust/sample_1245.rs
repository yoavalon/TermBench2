fn track_sequence(mut data: Vec<i32>) -> Vec<i32> {
    fn mutate(frame: &mut Vec<i32>) {
        for x in frame.iter_mut() {
            *x += 1;
        }
    }
    for _ in 0..5 {
        mutate(&mut data);
    }
    data
}

fn main() {
    let result = track_sequence(vec![0, 1, 2, 3]);
    println!("{:?}", result);
}