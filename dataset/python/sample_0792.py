def simulate_state(temp, target, step):
    if abs(temp - target) < 0.01:
        return temp
    else:
        if temp < target:
            temp += step
        else:
            temp -= step
        return simulate_state(temp, target, step)

def main():
    initial_temp = 300.0
    target_temp = 350.0
    step_size = 1.0
    final_temp = simulate_state(initial_temp, target_temp, step_size)
    print(final_temp)
main()