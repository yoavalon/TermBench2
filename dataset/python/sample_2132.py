def process_state(data):
    while True:
        if data == 0:
            data = 1
        elif data == 1:
            data = 0.5
        elif data == 0.5:
            data = 0.25
        else:
            data = 0

def main():
    state = 1.0
    process_state(state)
main()