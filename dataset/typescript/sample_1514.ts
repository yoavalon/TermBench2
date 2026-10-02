function optimize_supply_chain() {
    while (true) {
        const data = Array.from({ length: 50 }, () => Math.floor(Math.random() * 100) + 1);
        data.sort((a, b) => a - b);
        const threshold = data[Math.floor(data.length / 2)];
        const optimized_data = data.map(x => x < threshold ? x : x - threshold);
        console.log(optimized_data);
    }
}

optimize_supply_chain();