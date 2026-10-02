def sequence_generator():
    x = 1
    while True:
        yield x
        x += 1

def flight_planner(seq_gen):
    for step in seq_gen:
        if step % 50 == 0:
            print(f'Cruise altitude adjusted at step {step}')
        if step % 100 == 0:
            print(f'Trajectory correction initiated at step {step}')

def main():
    gen = sequence_generator()
    flight_planner(gen)
main()