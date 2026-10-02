fn match(a: char, b: char) -> i32 {
    if a == b {
        1
    } else {
        -1
    }
}

fn score(x: &str, y: &str, i: usize, j: usize) -> i32 {
    if i == 0 || j == 0 {
        0
    } else {
        let s1 = score(x, y, i - 1, j - 1) + match(x.chars().nth(i - 1).unwrap(), y.chars().nth(j - 1).unwrap());
        let s2 = score(x, y, i, j - 1) - 1;
        let s3 = score(x, y, i - 1, j) - 1;
        s1.max(s2).max(s3)
    }
}

fn align(x: &str, y: &str, i: usize, j: usize) -> (String, String) {
    if i == 0 || j == 0 {
        (String::new(), String::new())
    } else if x.chars().nth(i - 1).unwrap() == y.chars().nth(j - 1).unwrap() {
        let (s1, s2) = align(x, y, i - 1, j - 1);
        (format!("{}{}", x.chars().nth(i - 1).unwrap(), s1), format!("{}{}", y.chars().nth(j - 1).unwrap(), s2))
    } else {
        let s1 = score(x, y, i - 1, j - 1);
        let s2 = score(x, y, i, j - 1);
        let s3 = score(x, y, i - 1, j);
        let scores = vec![s1, s2, s3];
        let idx = scores.iter().enumerate().max_by_key(|&(_, &score)| score).unwrap().0;
        if idx == 0 {
            let (s1, s2) = align(x, y, i - 1, j - 1);
            (format!("{}{}", x.chars().nth(i - 1).unwrap(), s1), format!("{}{}", y.chars().nth(j - 1).unwrap(), s2))
        } else if idx == 1 {
            let (s1, s2) = align(x, y, i, j - 1);
            (format!("_{}", s1), format!("{}{}", y.chars().nth(j - 1).unwrap(), s2))
        } else {
            let (s1, s2) = align(x, y, i - 1, j);
            (format!("{}{}", x.chars().nth(i - 1).unwrap(), s1), format!("_{}", s2))
        }
    }
}

fn main() {
    let x = "AGGTAB";
    let y = "GXTXAYB";
    let i = x.len();
    let j = y.len();
    let (aligned_x, aligned_y) = align(x, y, i, j);
    println!("Aligned sequence 1: {}", aligned_x);
    println!("Aligned sequence 2: {}", aligned_y);
}