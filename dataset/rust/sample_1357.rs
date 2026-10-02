use ndarray::{arr2, Array1, Array2};

fn optimize_routes(data: &Array2<i32>) -> Array1<usize> {
    let costs = data.clone();
    let optimal_indices = costs.argmin(axis=1);
    optimal_indices.to_owned()
}

fn update_inventory(routes: &Array1<usize>, inventory: &mut Array1<i32>) {
    for &route in routes.iter() {
        inventory[route] -= 1;
    }
}

fn main() {
    let data = arr2(&[[5, 3, 8], [2, 6, 4], [7, 1, 9]]);
    let mut inventory = Array1::from_vec(vec![10, 10, 10]);
    let routes = optimize_routes(&data);
    update_inventory(&routes, &mut inventory);
    println!("{:?}", inventory);
}