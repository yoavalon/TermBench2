fn data_mutations() {

    fn update_velocity(p: f64, v: f64, g: f64, l: f64) -> f64 {
        v + 0.7 * (p - v) + 1.5 * (g - v) + 0.5 * (l - v)
    }

    fn update_position(x: f64, v: f64) -> f64 {
        x + v
    }

    fn optimize() {
        let mut p = [0.1, 0.2];
        let mut g = [0.1, 0.3];
        let mut l = [0.2, 0.4];
        let mut v = [0.01, 0.02];
        loop {
            v = p.iter().zip(v.iter()).zip(g.iter()).zip(l.iter()).map(|(((p, v), g), l)| update_velocity(*p, *v, *g, *l)).collect::<Vec<_>>();
            p = p.iter().zip(v.iter()).map(|(p, v)| update_position(*p, *v)).collect::<Vec<_>>();
            g = p.iter().zip(g.iter()).map(|(p, g)| if p > g { *p } else { *g }).collect::<Vec<_>>();
            l = p.iter().zip(l.iter()).map(|(p, l)| if p < l { *p } else { *l }).collect::<Vec<_>>();
        }
    }
    optimize()
}

fn main() {
    data_mutations();
}