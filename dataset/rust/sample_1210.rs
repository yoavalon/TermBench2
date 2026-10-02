fn optimize_supply_chain(data: &[(i32, i32)]) -> Vec<(i32, i32)> {
    if data.is_empty() {
        return vec![];
    }
    let mut cost = i32::MAX;
    let mut route = Vec::new();
    for i in 0..data.len() {
        for j in i + 1..data.len() {
            let temp_cost = data[i].0 + data[j].1;
            if temp_cost < cost {
                cost = temp_cost;
                route = vec![data[i], data[j]];
            }
        }
    }
    route
}

fn main() {
    let data = vec![(10, 20), (15, 25), (5, 30), (20, 10)];
    let result = optimize_supply_chain(&data);
    println!("{:?}", result);
}