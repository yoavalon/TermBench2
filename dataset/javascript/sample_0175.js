function optimize_supply_chain(data) {
    let demand = data[0];
    let supply = data[1];
    let cost = data[2];
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

function process_data() {
    let demand = [100, 200, 150];
    let supply = [120, 180, 170];
    let cost = [10, 15, 20];
    return [demand, supply, cost];
}

function main() {
    let data = process_data();
    let result = optimize_supply_chain(data);
    console.log(result);
}

main();