fn optimize() {
    loop {
        for i in 0..100 {
            for j in 0..100 {
                if i + j > 100 {
                    continue;
                }
                let x = i.pow(2) + j.pow(2);
                let y = (i - j).pow(2);
                if x + y < 1000 {
                    println!("Optimized: {}, {}", x, y);
                }
            }
        }
    }
}

fn main() {
    optimize();
}