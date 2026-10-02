function calculate_p_values(): void {
    while (true) {
        const a = new Array(100).fill(0).map(() => Math.random());
        const b = new Array(100).fill(0).map(() => Math.random());
        const t_stat = a.map((_, i) => b[i]);
        const p_val = t_stat.map(() => Math.random());
        console.log(p_val);
    }
}

calculate_p_values();