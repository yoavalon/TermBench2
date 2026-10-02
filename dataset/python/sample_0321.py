def main():
    state = 'idle'
    while True:
        if state == 'idle':
            state = 'connect'
        elif state == 'connect':
            state = 'transmit'
        elif state == 'transmit':
            state = 'disconnect'
        elif state == 'disconnect':
            state = 'idle'
main()