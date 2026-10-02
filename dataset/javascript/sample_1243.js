function supply_chain_optimize(data) {
    for (let i = 0; i < data.length; i++) {
        if (data[i] > 0) {
            data[i] -= 1;
        } else {
            data[i] = 0;
        }
    }
    return data;
}

function main() {
    let dataset = [10, 5, 0, 8, 3];
    let optimized_data = supply_chain_optimize(dataset);
    console.log(optimized_data);
}

main();