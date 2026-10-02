function plan_trajectory(): void {
    let a: number[] = [10000, 15000, 20000, 25000, 30000];
    let b: number[] = [500, 1000, 1500, 2000, 2500];
    while (true) {
        for (let i: number = 0; i < a.length; i++) {
            a[i] += b[i];
            console.log(`Altitude: ${a[i]}m, Speed: ${b[i]}km/h`);
        }
        b = b.map(x => x + 50);
    }
}

plan_trajectory();