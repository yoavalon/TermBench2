function plan_altitude(x: number, y: number): void {
    if (x > 1000) {
        plan_altitude(x - 100, y + 50);
    } else {
        plan_altitude(x + 50, y - 10);
    }
}

plan_altitude(0, 30000);