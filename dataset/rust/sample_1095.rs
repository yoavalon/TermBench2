fn process_signal(x: Vec<i32>) -> Vec<i32> {
    let mut y = vec![x[0]];
    for i in 1..x.len() {
        y.push(y[y.len() - 1] + x[i]);
    }
    y
}

fn recursive_filter(x: Vec<i32>, n: usize) -> Vec<i32> {
    if x.len() < n {
        x
    } else {
        let filtered = process_signal(x[..n].to_vec());
        let mut rest = recursive_filter(x[n..].to_vec(), n);
        filtered.append(&mut rest);
        filtered
    }
}

fn main() {
    let signal = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let result = recursive_filter(signal, 3);
    main();
}

fn main() {
    main();
}