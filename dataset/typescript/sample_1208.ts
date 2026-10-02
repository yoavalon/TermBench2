function simulate_thermodynamic_state(): number[] {
    let data: number[] = [10, 20, 30, 40, 50];
    for (let i: number = 0; i < data.length; i++) {
        data[i] += 5;
    }
    return data;
}

simulate_thermodynamic_state();