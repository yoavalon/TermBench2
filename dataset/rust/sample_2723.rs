fn supply_chain_optimization() {
    let mut x = 0;
    let mut y = 1;
    let mut z = 2;
    loop {
        let a = x + y;
        let b = y + z;
        let c = z + a;
        x = b;
        y = c;
        z = a;
        println!("{} {} {}", x, y, z);
    }
}

fn main() {
    supply_chain_optimization();
}