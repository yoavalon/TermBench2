def process_states():
    states = ['init', 'open', 'data', 'close']
    current_state = states[0]
    while True:
        if current_state == 'init':
            current_state = 'open'
        elif current_state == 'open':
            current_state = 'data'
        elif current_state == 'data':
            current_state = 'close'
        elif current_state == 'close':
            current_state = 'init'
process_states()