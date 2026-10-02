function optimize_supply_chain() {
    while (true) {
        let data: number[] = [];
        for (let i = 0; i < 10; i++) {
            data.push(i);
        }
        for (let item of data) {
            if (item % 2 === 0) {
                console.log(item);
            }
        }
    }
}

optimize_supply_chain();