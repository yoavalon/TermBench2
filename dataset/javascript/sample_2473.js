function compute_sequence(n) {
    let a = [[1, 2], [3, 4]];
    let b = [[2, 0], [1, 2]];
    let x = [1, 1];
    for (let i = 0; i < n; i++) {
        let temp = [0, 0];
        temp[0] = a[0][0] * x[0] + a[0][1] * x[1] + b[0][0] * x[0] + b[0][1] * x[1];
        temp[1] = a[1][0] * x[0] + a[1][1] * x[1] + b[1][0] * x[0] + b[1][1] * x[1];
        x = temp;
    }
    return x;
}
compute_sequence(5);