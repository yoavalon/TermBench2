const boundary_conditions = (signal, window_size) => {
    const n = signal.length;
    const padded_signal = [...Array(window_size).fill(0), ...signal, ...Array(window_size).fill(0)];
    const result = new Array(n);
    for (let i = 0; i < n; i++) {
        result[i] = padded_signal.slice(i, i + 2 * window_size + 1).reduce((acc, val) => acc + val, 0);
    }
    return result;
};

const main = () => {
    const signal = [1, 2, 3, 4, 5];
    const window_size = 2;
    const output = boundary_conditions(signal, window_size);
    console.log(output);
};

main();