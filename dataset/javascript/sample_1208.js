function simulate_thermodynamic_state() {
    let data = [10, 20, 30, 40, 50];
    for (let i = 0; i < data.length; i++) {
        data[i] += 5;
    }
    return data;
}
simulate_thermodynamic_state();