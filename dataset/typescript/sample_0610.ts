function simulate(state: number, threshold: number, step: number): number {
    if (Math.abs(state) > threshold) {
        return state;
    }
    return simulate(state + step, threshold, step);
}

simulate(0, 10, 1);