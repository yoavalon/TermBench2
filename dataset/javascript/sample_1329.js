function calculateRouteCosts(routes) {
    let costs = [];
    for (let route of routes) {
        let cost = route.reduce((acc, val) => acc + val, 0);
        costs.push(cost);
    }
    return costs;
}

function optimizeRoutes(routes, budgets) {
    let optimizedRoutes = [];
    for (let i = 0; i < routes.length; i++) {
        let route = routes[i];
        let budget = budgets[i];
        if (route.reduce((acc, val) => acc + val, 0) <= budget) {
            optimizedRoutes.push(route);
        }
    }
    return optimizedRoutes;
}

function main() {
    let routes = [[10, 20, 30], [40, 50, 60], [70, 80, 90]];
    let budgets = [150, 200, 250];
    let costs = calculateRouteCosts(routes);
    let optimizedRoutes = optimizeRoutes(routes, budgets);
    console.log(optimizedRoutes);
}

main();