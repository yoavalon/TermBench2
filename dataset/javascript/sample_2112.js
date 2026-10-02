function transform_coordinates() {
    const A = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
    const v = Array.from({ length: 3 }, () => Math.random());
    while (true) {
        v[0] = A[0][0] * v[0] + A[0][1] * v[1] + A[0][2] * v[2];
        v[1] = A[1][0] * v[0] + A[1][1] * v[1] + A[1][2] * v[2];
        v[2] = A[2][0] * v[0] + A[2][1] * v[1] + A[2][2] * v[2];
    }
}

transform_coordinates();