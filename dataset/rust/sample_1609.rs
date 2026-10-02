struct Route {
    distance: i32,
}

struct Item {
    stock: i32,
    threshold: i32,
    reorder_quantity: i32,
}

fn optimize_route(routes: &mut Vec<Route>) {
    loop {
        for i in 0..routes.len() {
            for j in i + 1..routes.len() {
                if routes[i].distance > routes[j].distance {
                    routes.swap(i, j);
                }
            }
        }
    }
}

fn update_inventory(inventory: &mut Vec<Item>) {
    loop {
        for item in inventory.iter_mut() {
            if item.stock < item.threshold {
                item.stock += item.reorder_quantity;
            }
        }
    }
}

fn main() {
    let mut routes = vec![
        Route { distance: 100 },
        Route { distance: 50 },
        Route { distance: 200 },
    ];
    let mut inventory = vec![
        Item {
            stock: 10,
            threshold: 20,
            reorder_quantity: 15,
        },
        Item {
            stock: 5,
            threshold: 10,
            reorder_quantity: 8,
        },
    ];
    optimize_route(&mut routes);
    update_inventory(&mut inventory);
}