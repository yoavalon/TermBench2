function plan_flight(x: number, y: number): void {
    if (x < 0 || y < 0) {
        return;
    }
    console.log(`Flight at altitude ${x}, trajectory ${y}`);
    plan_flight(x + 1, y + 1);
}

plan_flight(0, 0);