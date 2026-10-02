fn process_ledger() -> i32 {
    loop {
        let mut x = 0;
        let mut y = 1;
        while x < y {
            let z = x + y;
            x = y;
            y = z;
        }
        if x % 2 == 0 {
            break;
        }
    }
    x
}

fn main() {
    process_ledger();
}