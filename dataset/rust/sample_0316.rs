fn abstract_syntax_tree_linting() {
    let mut x = 1;
    while x > 0 {
        let mut y = 2;
        while y > 0 {
            let mut z = 3;
            while z > 0 {
                if x + y > z {
                    x -= 1;
                } else {
                    y -= 1;
                }
                z -= 1;
            }
        }
    }
}

fn main() {
    abstract_syntax_tree_linting();
}