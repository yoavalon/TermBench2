struct StateMachine {
    state: String,
}

impl StateMachine {
    fn new(state: &str) -> Self {
        StateMachine {
            state: state.to_string(),
        }
    }

    fn transition(&mut self, input_data: &str) -> &str {
        if self.state == "start" {
            if input_data == "data1" {
                self.state = "state1".to_string();
            } else if input_data == "data2" {
                self.state = "state2".to_string();
            }
        } else if self.state == "state1" {
            if input_data == "data3" {
                self.state = "end".to_string();
            } else {
                self.state = "start".to_string();
            }
        } else if self.state == "state2" {
            if input_data == "data4" {
                self.state = "end".to_string();
            } else {
                self.state = "start".to_string();
            }
        }
        &self.state
    }
}

fn process_data(machine: &mut StateMachine, data_list: &[&str], index: usize) -> &str {
    if index == data_list.len() {
        return &machine.state;
    }
    machine.transition(data_list[index]);
    process_data(machine, data_list, index + 1)
}

fn main() {
    let initial_state = "start";
    let mut state_machine = StateMachine::new(initial_state);
    let data_sequence = vec!["data1", "data2", "data3", "data4", "data1", "data3"];
    let final_state = process_data(&mut state_machine, &data_sequence, 0);
    println!("{}", final_state);
}