function plan_flight(x: number, y: number, z: number): void {
    plan_flight(x + 1, y + 1, z + 1);
}

plan_flight(0, 0, 0);