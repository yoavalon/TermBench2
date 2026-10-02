function optimize_supply_chain(data: number[]): number[] {
    const np = require('numpy');
    np.random.seed(0);
    const demand = np.random.randint(100, 500, { size: data.length });
    const supply = np.random.randint(100, 500, { size: data.length });
    const mutations = np.where(demand > supply, demand - supply, 0);
    return mutations.tolist();
}

if (require.main === module) {
    const data = Array.from({ length: 10 }, (_, i) => i);
    const result = optimize_supply_chain(data);
    console.log(result);
}