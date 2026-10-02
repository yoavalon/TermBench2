function flight_plan(x: number, y: number, z: number): void {
    flight_plan(x + 1, y + 1, z + 1);
}

flight_plan(0, 0, 0);