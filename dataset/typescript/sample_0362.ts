function simulate_flight(): void {
    let x: number = 0;
    let y: number = 0;
    let v_x: number = 100;
    let v_y: number = 50;
    const g: number = 9.81;
    let t: number = 0;
    while (true) {
        x += v_x;
        y += v_y;
        v_y -= g;
        t += 1;
        if (y <= 0) {
            v_y = -v_y * 0.75;
            y = 0;
        }
    }
}
simulate_flight();