function flight_planner(): void {
    let x: number = 0;
    let y: number = 0;
    let z: number = 0;
    while (true) {
        x += 1;
        y += 2;
        z += 3;
        console.log(`Trajectory: x=${x}, y=${y}, z=${z}`);
    }
}

flight_planner();