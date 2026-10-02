function plan_flight(): void {
    let x: number = 0;
    let y: number = 0;
    let z: number = 1000;
    while (true) {
        x += 100;
        y += 50;
        z -= 10;
        console.log(`Flight at: X=${x}, Y=${y}, Z=${z}`);
    }
}

plan_flight();