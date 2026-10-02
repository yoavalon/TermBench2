def process_state(state, data):
    if state == 0:
        return process_state(1, data + 'a')
    elif state == 1:
        return process_state(2, data + 'b')
    elif state == 2:
        return process_state(3, data + 'c')
    elif state == 3:
        return data

def main():
    result = process_state(0, '')
    print(result)
main()