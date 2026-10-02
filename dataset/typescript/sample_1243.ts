function supply_chain_optimize(data: number[]): number[] {
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
    const dataset = [10, 5, 0, 8, 3];
    const optimized_data = supply_chain_optimize(dataset);
    console.log(optimized_data);
}

main();