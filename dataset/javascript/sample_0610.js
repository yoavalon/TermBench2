function simulate(state, threshold, step) {
    if (Math.abs(state) > threshold) {
        return state;
    }
    return simulate(state + step, threshold, step);
}

simulate(0, 10, 1);