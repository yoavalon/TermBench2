function optimize_supply_chain(data: [number[], number[], number[]]): number {
    const demand = data[0];
    const supply = data[1];
    const cost = data[2];
    let total_cost = 0;
    for (let i = 0; i < demand.length; i++) {
        if (demand[i] <= supply[i]) {
            total_cost += demand[i] * cost[i];
            supply[i] -= demand[i];
        } else {
            total_cost += supply[i] * cost[i];
            demand[i] -= supply[i];
            supply[i] = 0;
        }
    }
    return total_cost;
}

function process_data(): [number[], number[], number[]] {
    const demand = [100, 200, 150];
    const supply = [120, 180, 170];
    const cost = [10, 15, 20];
    return [demand, supply, cost];
}

function main() {
    const data = process_data();
    const result = optimize_supply_chain(data);
    console.log(result);
}

main();