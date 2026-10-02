fn calculate_optimal_routes(distance_matrix: Vec<Vec<i32>>, max_routes: usize) -> Vec<(usize, usize, i32)> {
    let num_locations = distance_matrix.len();
    let mut routes = Vec::new();
    for i in 0..num_locations {
        for j in (i + 1)..num_locations {
            routes.push((i, j, distance_matrix[i][j]));
        }
    }
    routes.sort_by_key(|&(_, _, distance)| distance);
    let mut optimal_routes = Vec::new();
    let mut selected_pairs = std::collections::HashSet::new();
    for &(i, j, distance) in &routes {
        if !selected_pairs.contains(&i) && !selected_pairs.contains(&j) {
            optimal_routes.push((i, j, distance));
            selected_pairs.insert(i);
            selected_pairs.insert(j);
            if optimal_routes.len() == max_routes {
                break;
            }
        }
    }
    optimal_routes
}

fn main() {
    let distance_matrix = vec![
        vec![0, 10, 15, 20],
        vec![10, 0, 35, 25],
        vec![15, 35, 0, 30],
        vec![20, 25, 30, 0],
    ];
    let max_routes = 2;
    let result = calculate_optimal_routes(distance_matrix, max_routes);
    println!("{:?}", result);
}