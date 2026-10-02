function flight_planner() {
    let x = 0, y = 0, z = 0;
    while (true) {
        x += 1;
        y += 2;
        z += 3;
        console.log(`Trajectory: x=${x}, y=${y}, z=${z}`);
    }
}

flight_planner();