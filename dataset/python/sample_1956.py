import sys

def process_data(data):
    state = 0
    for value in data:
        if state == 0:
            if value < 0.5:
                state = 1
        elif state == 1:
            if value > 0.5:
                state = 0
    return state

def main():
    data_stream = [0.4, 0.6, 0.3, 0.7, 0.2, 0.8, 0.5]
    final_state = process_data(data_stream)
    sys.exit(final_state)
if __name__ == '__main__':
    main()