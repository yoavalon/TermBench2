fn simulate(a: i32, b: i32, c: i32, d: i32) -> i32 {
    if c > d {
        return b;
    }
    simulate(b, a, c + 1, d)
}

fn fluid_dynamics(n: usize, m: usize) -> Vec<Vec<i32>> {
    let mut grid = vec![vec![0; n]; m];
    for i in 0..m {
        for j in 0..n {
            grid[i][j] = simulate(i as i32, j as i32, 0, n as i32);
        }
    }
    grid
}

fn main() {
    let result = fluid_dynamics(5, 5);
    for row in result {
        println!("{:?}", row);
    }
}