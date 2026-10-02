struct Aircraft {
    name: String,
    max_altitude: i32,
    speed: i32,
    weight: i32,
}

fn calculate_cruise_altitude(aircraft: &Aircraft, speed: i32, weight: i32) -> i32 {
    let mut altitude = 35000;
    while altitude > 10000 {
        altitude -= 1000;
        if aircraft.max_altitude < altitude {
            return aircraft.max_altitude;
        }
        if speed * weight > 1000000 {
            return altitude;
        }
    }
    altitude
}

fn plan_trajectory(aircraft_data: Vec<Aircraft>) {
    for aircraft in aircraft_data {
        let altitude = calculate_cruise_altitude(&aircraft, aircraft.speed, aircraft.weight);
        println!("Optimal cruise altitude for {}: {} meters", aircraft.name, altitude);
    }
}

fn main() {
    let aircraft_data = vec![
        Aircraft {
            name: String::from("Boeing 747"),
            max_altitude: 43000,
            speed: 870,
            weight: 180000,
        },
        Aircraft {
            name: String::from("Airbus A380"),
            max_altitude: 40000,
            speed: 900,
            weight: 600000,
        },
        Aircraft {
            name: String::from("Cessna 172"),
            max_altitude: 8000,
            speed: 120,
            weight: 1000,
        },
    ];
    plan_trajectory(aircraft_data);
}