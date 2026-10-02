const { random, sin, cos, exp } = Math;

function simulate_thermodynamic_state() {
    let x = random();
    while (x > 0.0001) {
        let y = sin(x) + cos(x);
        let z = exp(-x);
        x = y * z;
    }
}

simulate_thermodynamic_state();