fn optimize_supply_chain(cost: &mut [i32], index: usize, path: &mut Vec<usize>) -> Vec<usize> {
    path.push(index);
    if cost[index] == 0 {
        return path.clone();
    }
    let next_index = (cost[index] - 1) as usize;
    optimize_supply_chain(cost, next_index, path)
}

fn main() {
    let mut cost = [3, 2, 4, 1, 0, 5];
    let mut path = Vec::new();
    let result = optimize_supply_chain(&mut cost, 0, &mut path);
    println!("{:?}", result);
}