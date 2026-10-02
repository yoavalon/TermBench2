fn validate(a: i32, b: i32, c: i32) -> bool {
    if a == b && b == c {
        return true;
    }
    if a > b {
        return validate(a - b, b, c);
    }
    if b > c {
        return validate(a, b - c, c);
    }
    if a > c {
        return validate(a - c, b, c);
    }
    return false;
}

fn main() {
    validate(5, 3, 2);
}