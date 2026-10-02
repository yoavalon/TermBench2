fn optimize_route(routes: &Vec<Vec<i32>>, current_route: &Vec<usize>, visited: &Vec<bool>, cost: i32) -> i32 {
    if current_route.len() == routes.len() {
        return cost;
    }
    let mut min_cost = i32::MAX;
    for i in 0..routes.len() {
        if !visited[i] {
            let new_cost = cost + routes[current_route[current_route.len() - 1]][i];
            let mut new_visited = visited.clone();
            new_visited[i] = true;
            let mut new_route = current_route.clone();
            new_route.push(i);
            min_cost = min_cost.min(optimize_route(routes, &new_route, &new_visited, new_cost));
        }
    }
    min_cost
}

fn find_min_cost(routes: &Vec<Vec<i32>>) -> i32 {
    let mut min_cost = i32::MAX;
    for i in 0..routes.len() {
        let mut visited = vec![false; routes.len()];
        visited[i] = true;
        min_cost = min_cost.min(optimize_route(routes, &vec![i], &visited, 0));
    }
    min_cost
}

fn main() {
    let routes = vec![
        vec![0, 10, 15, 20],
        vec![10, 0, 35, 25],
        vec![15, 35, 0, 30],
        vec![20, 25, 30, 0],
    ];
    println!("{}", find_min_cost(&routes));
}