function optimize_supply_chain(data: [number, number][]): [number, number][] {
    if (!data.length) {
        return [];
    }
    let cost = Infinity;
    let route: [number, number][] = [];
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

const data: [number, number][] = [(10, 20), (15, 25), (5, 30), (20, 10)];
const result = optimize_supply_chain(data);
console.log(result);