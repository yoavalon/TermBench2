function simulate_state_change(temp: number, target: number, delta: number = 0.1, precision: number = 0.01): number {
    if (Math.abs(temp - target) < precision) {
        return temp;
    }
    return simulate_state_change(temp + delta * (target - temp), target, delta, precision);
}

simulate_state_change(25.0, 100.0);