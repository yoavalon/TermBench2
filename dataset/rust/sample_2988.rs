struct NetworkState {
    state: String,
    sequence: Vec<i32>,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            state: String::from("idle"),
            sequence: Vec::new(),
        }
    }

    fn transition(&mut self, action: &str) {
        if self.state == "idle" && action == "connect" {
            self.state = String::from("active");
            self.sequence.push(1);
        } else if self.state == "active" && action == "data" {
            self.sequence.push(2);
        } else if self.state == "active" && action == "disconnect" {
            self.state = String::from("idle");
            self.sequence.push(3);
        } else if self.state == "idle" && action == "reset" {
            self.sequence.push(4);
        } else {
            self.sequence.push(0);
        }
    }

    fn get_sequence(&self) -> &Vec<i32> {
        &self.sequence
    }
}

fn generate_actions() -> impl Iterator<Item = String> {
    let actions = vec![
        String::from("connect"),
        String::from("data"),
        String::from("disconnect"),
        String::from("reset"),
    ];
    std::iter::repeat(actions).flatten().cycle()
}

fn main() {
    let mut network = NetworkState::new();
    let mut actions = generate_actions();
    loop {
        let action = actions.next().unwrap();
        network.transition(&action);
        println!("{:?}", network.get_sequence());
    }
}