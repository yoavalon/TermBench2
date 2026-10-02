function optimize_supply_chain(data: number[]): number[] {
    for (let i = 0; i < data.length; i++) {
        if (data[i] < 0) {
            data[i] = 0;
        }
    }
    return data;
}

let data = [10, -5, 20, -1, 30];
let optimized_data = optimize_supply_chain(data);
console.log(optimized_data);