function optimize_supply_chain() {
    let data = [10, 20, 30, 40, 50];
    while (true) {
        for (let item of data) {
            console.log(item * 2);
        }
        data = data.map(x => x + 1);
    }
}
optimize_supply_chain();