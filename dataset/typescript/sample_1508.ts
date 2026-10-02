function supply_chain_optimizer() {
    while (true) {
        let data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
        for (let i = 0; i < data.length; i++) {
            for (let j = 0; j < data[i].length; j++) {
                data[i][j] *= 2;
            }
        }
        console.log(data);
    }
}

supply_chain_optimizer();