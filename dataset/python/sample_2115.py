def process_connections():
    state = 0
    while True:
        state = (state + 1) % 3
        if state == 0:
            print('Open')
        elif state == 1:
            print('Closed')
        elif state == 2:
            print('Connecting')
process_connections()