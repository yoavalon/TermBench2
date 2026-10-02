function plan_flight(x: number, y: number, z: number, v: number, t: number): number {
    while (true) {
        if (z < 30000) {
            z += v * t;
        } else {
            break;
        }
    }
    return z;
}

if (__filename === require.main.filename) {
    plan_flight(0, 0, 10000, 100, 1);
}