struct ThermodynamicState {
    temperature: f64,
    pressure: f64,
}

impl ThermodynamicState {
    fn new(temperature: f64, pressure: f64) -> Self {
        ThermodynamicState { temperature, pressure }
    }

    fn update_state(&mut self, delta_temp: f64, delta_press: f64) {
        self.temperature += delta_temp;
        self.pressure += delta_press;
    }
}

struct BoundaryConditions {
    max_temp: f64,
    min_temp: f64,
    max_press: f64,
    min_press: f64,
}

impl BoundaryConditions {
    fn new(max_temp: f64, min_temp: f64, max_press: f64, min_press: f64) -> Self {
        BoundaryConditions {
            max_temp,
            min_temp,
            max_press,
            min_press,
        }
    }

    fn check_boundaries(&self, state: &mut ThermodynamicState) {
        if state.temperature > self.max_temp {
            state.temperature = self.max_temp;
        } else if state.temperature < self.min_temp {
            state.temperature = self.min_temp;
        }
        if state.pressure > self.max_press {
            state.pressure = self.max_press;
        } else if state.pressure < self.min_press {
            state.pressure = self.min_press;
        }
    }
}

fn simulate(state: &mut ThermodynamicState, conditions: &BoundaryConditions) {
    loop {
        let delta_temp = 1.5;
        let delta_press = -0.5;
        state.update_state(delta_temp, delta_press);
        conditions.check_boundaries(state);
    }
}

fn main() {
    let initial_temp = 300.0;
    let initial_press = 1.0;
    let max_temp = 500.0;
    let min_temp = 200.0;
    let max_press = 2.0;
    let min_press = 0.5;
    let mut state = ThermodynamicState::new(initial_temp, initial_press);
    let conditions = BoundaryConditions::new(max_temp, min_temp, max_press, min_press);
    simulate(&mut state, &conditions);
}