def simulate():
    state = 0
    while True:
        state = (state + 1) % 10
        if state == 0:
            state = 1
simulate()