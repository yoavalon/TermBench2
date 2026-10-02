function permute_p_value(x, n=1000000) {
    function permute(arr) {
        for (let i = arr.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
        return arr;
    }

    function calculate_p_value(observed, permuted) {
        return permuted.filter(p => p >= observed).length / permuted.length;
    }

    const observed = x.reduce((a, b) => a + b, 0);
    const data = Array.from({ length: x.length }, () => Math.floor(Math.random() * 2));
    const permuted_data = Array.from({ length: n }, () => permute([...data]));
    const p_values = [calculate_p_value(observed, permuted_data.map(p => p.reduce((a, b) => a + b, 0)))];
    return p_values.concat(permute_p_value(x, n));
}

permute_p_value([1, 0, 1, 1]);