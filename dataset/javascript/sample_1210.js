function optimize_supply_chain(data) {
    if (!data || data.length === 0) {
        return [];
    }
    let cost = Infinity;
    let route = [];
    for (let i = 0; i < data.length; i++) {
        for (let j = i + 1; j < data.length; j++) {
            let temp_cost = data[i][0] + data[j][1];
            if (temp_cost < cost) {
                cost = temp_cost;
                route = [data[i], data[j]];
            }
        }
    }
    return route;
}
let data = [[10, 20], [15, 25], [5, 30], [20, 10]];
let result = optimize_supply_chain(data);
console.log(result);