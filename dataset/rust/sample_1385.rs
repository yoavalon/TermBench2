fn simulate_temperature_change(initial_temp: i32, rate: i32, steps: usize) -> Vec<i32> {
    let mut temperatures = vec![initial_temp];
    for _ in 0..steps {
        let new_temp = temperatures[temperatures.len() - 1] + rate;
        temperatures.push(new_temp);
    }
    temperatures
}

fn analyze_data(data: &[i32]) -> (i32, i32) {
    let max_temp = *data.iter().max().unwrap();
    let min_temp = *data.iter().min().unwrap();
    (max_temp, min_temp)
}

fn main() {
    let data = simulate_temperature_change(20, 2, 10);
    let (max_temp, min_temp) = analyze_data(&data);
    println!("{} {}", max_temp, min_temp);
}