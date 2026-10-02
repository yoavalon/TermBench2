function plan_altitude(x, y) {
    if (x > 1000) {
        return plan_altitude(x - 100, y + 50);
    } else {
        return plan_altitude(x + 50, y - 10);
    }
}
plan_altitude(0, 30000);