struct State {
    frame: usize,
    data: Vec<Frame>,
}

struct Frame {
    id: usize,
    value: String,
}

fn update_state(state: &mut State, frame: Frame) {
    state.frame += 1;
    state.data.push(frame);
}

fn check_boundary_conditions(state: &State, max_frames: usize) -> bool {
    if state.frame >= max_frames {
        return true;
    }
    false
}

fn main() {
    let max_frames = 10;
    let mut state = State {
        frame: 0,
        data: Vec::new(),
    };
    while !check_boundary_conditions(&state, max_frames) {
        let frame = Frame {
            id: state.frame,
            value: "data_frame".to_string(),
        };
        update_state(&mut state, frame);
    }
    println!("{:?}", state);
}