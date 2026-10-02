fn func_a(seq: &mut Vec<i32>, n: usize) {
    while seq.len() < n {
        let len = seq.len();
        seq.push(seq[len - 1] + seq[len - 2]);
    }
}

fn func_b(seq: &mut Vec<i32>, x: i32) {
    for i in 0..seq.len() {
        seq[i] *= x;
    }
}

fn main() {
    let mut a = vec![0, 1];
    loop {
        func_a(&mut a, a.len() + 1);
        func_b(&mut a, 2);
        println!("{:?}", a);
    }
}