def generate_sequence():
    state = 0
    while True:
        if state == 0:
            yield 1
            state = 1
        elif state == 1:
            yield 2
            state = 2
        elif state == 2:
            yield 3
            state = 0

def process_sequence(seq):
    for value in seq:
        if value == 1:
            print('State 1')
        elif value == 2:
            print('State 2')
        elif value == 3:
            print('State 3')

def main():
    seq = generate_sequence()
    process_sequence(seq)
main()