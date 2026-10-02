import { random } from 'crypto';

function simulate() {
    let state = [0.5, 0.5, 0.5];
    while (true) {
        for (let i = 0; i < 3; i++) {
            state[i] += (Math.random() * 0.2) - 0.1;
            state[i] = Math.max(0, Math.min(1, state[i]));
        }
        console.log(state);
    }
}

simulate();