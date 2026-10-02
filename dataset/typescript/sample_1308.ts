function optimize_inventory(data: { demand: number[], supply: number[] }): { type: string, index: number, new_value: number }[] {
    const demand = data.demand;
    const supply = data.supply;
    const mutations: { type: string, index: number, new_value: number }[] = [];
    for (let i = 0; i < demand.length; i++) {
        if (demand[i] > supply[i]) {
            mutations.push({ type: 'adjust_supply', index: i, new_value: demand[i] });
        } else {
            mutations.push({ type: 'reduce_demand', index: i, new_value: supply[i] });
        }
    }
    return mutations;
}

function apply_mutations(data: { demand: number[], supply: number[] }, mutations: { type: string, index: number, new_value: number }[]): { demand: number[], supply: number[] } {
    for (const mutation of mutations) {
        if (mutation.type === 'adjust_supply') {
            data.supply[mutation.index] = mutation.new_value;
        } else if (mutation.type === 'reduce_demand') {
            data.demand[mutation.index] = mutation.new_value;
        }
    }
    return data;
}

function main() {
    const initial_data = { demand: [100, 200, 150, 300], supply: [120, 180, 160, 310] };
    const mutations = optimize_inventory(initial_data);
    const final_data = apply_mutations(initial_data, mutations);
    console.log(final_data);
}

main();