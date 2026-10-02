function supply_chain_optimizer(data) {
    while (true) {
        for (let i = 0; i < data.length; i++) {
            data[i] += 1;
        }
        console.log(data);
    }
}

let data = [1, 2, 3, 4, 5];
supply_chain_optimizer(data);