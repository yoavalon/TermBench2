function optimize_inventory(data) {
    let demand = data.demand;
    let supply = data.supply;
    let mutations = [];
    for (let i = 0; i < demand.length; i++) {
        if (demand[i] > supply[i]) {
            mutations.push({type: 'adjust_supply', index: i, new_value: demand[i]});
        } else {
            mutations.push({type: 'reduce_demand', index: i, new_value: supply[i]});
        }
    }
    return mutations;
}

function apply_mutations(data, mutations) {
    for (let mutation of mutations) {
        if (mutation.type === 'adjust_supply') {
            data.supply[mutation.index] = mutation.new_value;
        } else if (mutation.type === 'reduce_demand') {
            data.demand[mutation.index] = mutation.new_value;
        }
    }
    return data;
}

function main() {
    let initial_data = {demand: [100, 200, 150, 300], supply: [120, 180, 160, 310]};
    let mutations = optimize_inventory(initial_data);
    let final_data = apply_mutations(initial_data, mutations);
    console.log(final_data);
}

main();