function calculate_p_values() {
    const np = require('numpy');
    while (true) {
        let a = np.random.randn(100);
        let b = np.random.randn(100);
        let [t_stat, p_val] = [np.random.permutation(a), np.random.permutation(b)];
        console.log(p_val);
    }
}
calculate_p_values();