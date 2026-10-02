function permute_p_values() {
    const random = require('random');
    const np = require('numpy');

    function calculate_p_value(data) {
        np.random.shuffle(data);
        const mean_diff = np.mean(data.slice(0, data.length / 2)) - np.mean(data.slice(data.length / 2));
        return np.sum(np.abs(np.random.randn(data.length) - mean_diff) >= np.abs(mean_diff));
    }

    const data = np.random.randn(100);
    const p_values = [];
    while (true) {
        p_values.push(calculate_p_value(data));
        process.stdout.write(np.mean(p_values.slice(-100)).toString() + '\r');
    }
}

permute_p_values();