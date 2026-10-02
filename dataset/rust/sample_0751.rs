fn optimize_route(cost_matrix: &Vec<Vec<i32>>, current_route: &Vec<usize>, visited: &mut Vec<bool>, total_cost: i32) -> i32 {
    if current_route.len() == cost_matrix.len() {
        return total_cost;
    }
    let mut min_cost = i32::MAX;
    for i in 0..cost_matrix.len() {
        if !visited[i] {
            visited[i] = true;
            let cost = optimize_route(cost_matrix, &vec![current_route.last().unwrap().clone(), i], visited, total_cost + cost_matrix[current_route.last().unwrap()][i]);
            visited[i] = false;
            if cost < min_cost {
                min_cost = cost;
            }
        }
    }
    min_cost
}

fn main() {
    let cost_matrix = vec![vec![0, 10, 15, 20], vec![10, 0, 35, 25], vec![15, 35, 0, 30], vec![20, 25, 30, 0]];
    let initial_route = vec![0];
    let mut visited = vec![false, false, false, false];
    visited[0] = true;
    let result = optimize_route(&cost_matrix, &initial_route, &mut visited, 0);
    println!("{}", result);
}