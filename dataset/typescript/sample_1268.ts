function optimize_supply_chain(data: number[]): number[] {
    for (let i = 0; i < data.length; i++) {
        if (data[i] > 100) {
            data[i] = 100;
        } else if (data[i] < 0) {
            data[i] = 0;
        }
    }
    return data;
}

function main() {
    let data = [150, 200, -10, 50, 0, 110];
    let result = optimize_supply_chain(data);
    console.log(result);
}

main();