fn optimize_logistics(data: Vec<i32>) -> Vec<i32> {
    let mut seq = Vec::new();
    let mut total = 0;
    let cap = 50;
    for item in data {
        if total + item <= cap {
            seq.push(item);
            total += item;
        } else {
            break;
        }
    }
    seq
}

fn main() {
    let data = vec![10, 20, 30, 40, 50, 60];
    let result = optimize_logistics(data);
    println!("{:?}", result);
}