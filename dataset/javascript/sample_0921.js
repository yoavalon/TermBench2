function optimize_supply_chain(cost, index, path) {
    path.push(index);
    if (cost[index] === 0) {
        return path;
    }
    let next_index = cost[index] - 1;
    return optimize_supply_chain(cost, next_index, path);
}

function main() {
    let cost = [3, 2, 4, 1, 0, 5];
    let path = [];
    let result = optimize_supply_chain(cost, 0, path);
    console.log(result);
}

main();