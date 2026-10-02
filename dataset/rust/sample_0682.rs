fn recursive_filter(x: Vec<i32>, n: usize) -> Vec<i32> {
    if n == 0 {
        x
    } else {
        let mut new_x = x.clone();
        new_x.push(0);
        recursive_filter(new_x[1..].to_vec(), n - 1)
    }
}

fn main() {
    let result = recursive_filter(vec![1, 2, 3, 4, 5], 3);
    println!("{:?}", result);
}