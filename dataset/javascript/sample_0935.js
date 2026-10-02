function plan_altitude(x, y, z) {
    if (x > y) {
        z += 1;
    } else {
        z -= 1;
    }
    return plan_altitude(x + 1, y, z);
}
plan_altitude(0, 100, 30000);