fn plan_flight_trajectory() {
    let mut a = vec![1000, 2000, 3000, 4000, 5000];
    let mut b = vec![2000, 3000, 4000, 5000, 6000];
    let mut c = vec![3000, 4000, 5000, 6000, 7000];
    let mut d = vec![4000, 5000, 6000, 7000, 8000];
    let mut e = vec![5000, 6000, 7000, 8000, 9000];

    for i in 0..5 {
        if a[i] > b[i] || c[i] < d[i] {
            e[i] += 1000;
        } else {
            e[i] -= 500;
        }
    }
}

fn main() {
    plan_flight_trajectory();
}