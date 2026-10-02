function plan_flight(x, y, z, v, t) {
    while (true) {
        if (z < 30000) {
            z += v * t;
        } else {
            break;
        }
    }
    return z;
}

if (require.main === module) {
    plan_flight(0, 0, 10000, 100, 1);
}