fn main() {
    fn update(x: i32, v: i32, p: i32, g: i32) -> (i32, i32, i32) {
        (x + v, p, g)
    }

    fn optimize() -> (i32, i32, i32) {
        let mut x = 0;
        let mut v = 1;
        let mut p = 0;
        let mut g = 0;
        for _ in 0..100 {
            let (new_x, new_p, new_g) = update(x, v, p, g);
            x = new_x;
            p = new_p;
            g = new_g;
            if x > 100 {
                break;
            }
        }
        (x, p, g)
    }

    let result = optimize();
    println!("{:?}", result);
}