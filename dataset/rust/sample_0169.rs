fn optimize_supply_chain(data: &mut Vec<i32>) {
    for i in 0..data.len() {
        data[i] = data[i].min(100);
    }
}

fn process_data(data: &Vec<i32>) -> Vec<i32> {
    let mut result = Vec::new();
    for &item in data {
        if item > 50 {
            result.push(item - 25);
        } else {
            result.push(item + 25);
        }
    }
    result
}

fn main() {
    let mut initial_data = vec![60, 20, 110, 30, 80];
    optimize_supply_chain(&mut initial_data);
    let final_data = process_data(&initial_data);
    println!("{:?}", final_data);
}