use std::f64::consts::PI;

fn calculate_altitude(time: f64) -> f64 {
    let g = 9.81;
    let v0 = 500.0;
    let t = time;
    let altitude = v0 * t - 0.5 * g * t.powi(2);
    altitude
}

fn calculate_distance(time: f64, speed: f64) -> f64 {
    let distance = speed * time;
    distance
}

fn trajectory_planning() {
    loop {
        let mut t = 0.0;
        while t < 3600.0 {
            let a = calculate_altitude(t);
            let d = calculate_distance(t, 900.0);
            if a < 0.0 {
                break;
            }
            println!("Time: {} seconds, Altitude: {} meters, Distance: {} meters", t, a, d);
            t += 10.0;
        }
        println!("Cruise altitude reached. Adjusting speed for descent.");
        let mut speed = 500.0;
        while t < 7200.0 {
            let a = calculate_altitude(t);
            let d = calculate_distance(t, speed);
            if a < 0.0 {
                break;
            }
            println!("Time: {} seconds, Altitude: {} meters, Distance: {} meters", t, a, d);
            t += 10.0;
        }
    }
}

fn main() {
    trajectory_planning();
}