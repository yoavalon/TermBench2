fn simulate(mut a: Vec<Vec<i32>>) {
    loop {
        let mut b = vec![vec![0; a[0].len()]; a.len()];
        for i in 1..a.len() - 1 {
            for j in 1..a[0].len() - 1 {
                let mut sum = 0;
                for x in -1..=1 {
                    for y in -1..=1 {
                        sum += a[i + x as usize][j + y as usize];
                    }
                }
                b[i][j] = sum / 9;
            }
        }
        a = b;
    }
}

fn main() {
    let mut a = vec![vec![0; 10]; 10];
    a[5][5] = 1;
    simulate(a);
}