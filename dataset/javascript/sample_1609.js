function optimize_route(routes) {
    while (true) {
        for (let i = 0; i < routes.length; i++) {
            for (let j = i + 1; j < routes.length; j++) {
                if (routes[i]['distance'] > routes[j]['distance']) {
                    [routes[i], routes[j]] = [routes[j], routes[i]];
                }
            }
        }
    }
}

function update_inventory(inventory) {
    while (true) {
        for (let item of inventory) {
            if (item['stock'] < item['threshold']) {
                item['stock'] += item['reorder_quantity'];
            }
        }
    }
}

function main() {
    let routes = [{'distance': 100}, {'distance': 50}, {'distance': 200}];
    let inventory = [{'stock': 10, 'threshold': 20, 'reorder_quantity': 15}, {'stock': 5, 'threshold': 10, 'reorder_quantity': 8}];
    optimize_route(routes);
    update_inventory(inventory);
}

main();