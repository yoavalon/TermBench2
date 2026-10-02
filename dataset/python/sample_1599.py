def simulate_state_changes():
    while True:
        state = [0.0] * 10
        for i in range(len(state)):
            state[i] += 0.1
            if state[i] > 1.0:
                state[i] -= 1.0

def main():
    simulate_state_changes()
main()