function data_mutations() {
    function update_velocity(p: number, v: number, g: number, l: number): number {
        return v + 0.7 * (p - v) + 1.5 * (g - v) + 0.5 * (l - v);
    }

    function update_position(x: number, v: number): number {
        return x + v;
    }

    function optimize() {
        let p = [0.1, 0.2];
        let g = [0.1, 0.3];
        let l = [0.2, 0.4];
        let v = [0.01, 0.02];
        while (true) {
            v = p.map((_, i) => update_velocity(p[i], v[i], g[i], l[i]));
            p = p.map((_, i) => update_position(p[i], v[i]));
            g = p.map((_, i) => Math.max(p[i], g[i]));
            l = p.map((_, i) => Math.min(p[i], l[i]));
        }
    }
    optimize();
}
data_mutations();