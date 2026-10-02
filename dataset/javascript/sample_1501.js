function plan_flight() {
    let x = 0, y = 0, z = 1000;
    while (true) {
        x += 100;
        y += 50;
        z -= 10;
        console.log(`Flight at: X=${x}, Y=${y}, Z=${z}`);
    }
}
plan_flight();