def process_data():
    state = 0
    while state < 3:
        state += 1
        if state == 1:
            data = 1.1 + 2.2
        elif state == 2:
            data = data - 3.3
        else:
            data = data * 4.4
    return data
process_data()