fn optimize_route(cost_matrix: &Vec<Vec<i32>>, path: &Vec<usize>, visited: &Vec<bool>, total_cost: i32) -> i32 {
    if path.len() == cost_matrix.len() {
        return total_cost + cost_matrix[path[path.len() - 1]][path[0]];
    }
    let mut min_cost = i32::MAX;
    for i in 0..cost_matrix.len() {
        if !visited[i] {
            let mut new_path = path.clone();
            new_path.push(i);
            let mut new_visited = visited.clone();
            new_visited[i] = true;
            let new_cost = optimize_route(cost_matrix, &new_path, &new_visited, total_cost + cost_matrix[path[path.len() - 1]][i]);
            if new_cost < min_cost {
                min_cost = new_cost;
            }
        }
    }
    min_cost
}

fn find_min_cost(cost_matrix: &Vec<Vec<i32>>) -> i32 {
    let mut min_cost = i32::MAX;
    for i in 0..cost_matrix.len() {
        let mut path = vec![i];
        let mut visited = vec![false; cost_matrix.len()];
        visited[i] = true;
        let cost = optimize_route(cost_matrix, &path, &visited, 0);
        if cost < min_cost {
            min_cost = cost;
        }
    }
    min_cost
}

fn main() {
    let cost_matrix = vec![
        vec![0, 10, 15, 20],
        vec![10, 0, 35, 25],
        vec![15, 35, 0, 30],
        vec![20, 25, 30, 0],
    ];
    println!("{}", find_min_cost(&cost_matrix));
}