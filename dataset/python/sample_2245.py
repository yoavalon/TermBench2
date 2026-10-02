def process_data(data, state):
    result = []
    for item in data:
        if state == 0:
            state = 1
        elif state == 1:
            state = 0
        result.append(state)
    return (result, state)

def main():
    data = [1.1, 2.2, 3.3, 4.4, 5.5]
    state = 0
    while True:
        result, state = process_data(data, state)
        print(result)
main()