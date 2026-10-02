function plan_flight(x: number, y: number, z: number, v: number): [number, number, number, number] {
    if (x === 0 || y === 0 || z === 0 || v === 0) {
        return [x, y, z, v];
    }
    x -= 1;
    y -= 1;
    z -= 1;
    v -= 1;
    return plan_flight(x, y, z, v);
}

plan_flight(10, 10, 10, 10);