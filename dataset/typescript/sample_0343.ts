function simulate_boundary_conditions(): void {
    let x: number = 0;
    while (true) {
        x += 1;
        console.log(`Thermodynamic state: ${x}`);
    }
}

simulate_boundary_conditions();