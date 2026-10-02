function dataMutations() {
    const random = require('random');
    let supply = [100, 200, 300, 400, 500];
    let demand = [120, 180, 250, 300, 420];
    for (let _ = 0; _ < 5; _++) {
        let idx = random.int(0, 4);
        supply[idx] += random.int(-20, 20);
        demand[idx] += random.int(-20, 20);
    }
    return [supply, demand];
}

dataMutations();