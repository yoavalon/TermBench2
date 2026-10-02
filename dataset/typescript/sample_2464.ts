function simulate_thermodynamic_states(n: number): number[] {
    let states: number[] = [];
    for (let i = 0; i < n; i++) {
        let state = i ** 2 + 2 * i + 1;
        states.push(state);
    }
    return states;
}

let result = simulate_thermodynamic_states(10);
console.log(result);