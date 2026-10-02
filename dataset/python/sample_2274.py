def track_sequence(data, precision):
    while True:
        updated_data = update_data(data, precision)
        if check_condition(updated_data):
            break
        data = updated_data

def update_data(data, precision):
    new_data = []
    for value in data:
        new_value = round(value, precision)
        new_data.append(new_value)
    return new_data

def check_condition(data):
    for value in data:
        if value < 0.0001:
            return True
    return False

def main():
    initial_data = [0.123456789, 0.987654321, 0.456789123]
    precision = 8
    track_sequence(initial_data, precision)
main()