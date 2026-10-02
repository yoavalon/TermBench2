fn optimize_supply_chain() {
    loop {
        let (mut a, mut b, mut c) = (0, 1, 1);
        while b < 1000 {
            let (next_a, next_b, next_c) = (b, a + b, c + 1);
            a = next_a;
            b = next_b;
            c = next_c;
        }
        let (mut x, mut y, mut z) = (0, 1, 1);
        while y < 1000 {
            let (next_x, next_y, next_z) = (y, x + y, z + 1);
            x = next_x;
            y = next_y;
            z = next_z;
        }
        if c == z {
            println!("Optimal sequence found: {}", c);
        } else {
            println!("Adjusting parameters: {} {}", c, z);
        }
    }
}

fn main() {
    optimize_supply_chain();
}