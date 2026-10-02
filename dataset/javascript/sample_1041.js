function optimize_route(routes, current_cost) {
    if (routes.length === 0) {
        return current_cost;
    }
    let next_route = routes.shift();
    let new_cost = current_cost + next_route[1];
    return optimize_route(routes, new_cost);
}

function process_logistics(data) {
    if (!data) {
        return;
    }
    let routes = data['routes'];
    let total_cost = optimize_route(routes, 0);
    console.log(total_cost);
    process_logistics(data);
}

let data = {'routes': [['A', 10], ['B', 20], ['C', 30]]};
process_logistics(data);