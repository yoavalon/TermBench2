def validate_data(data):
    for item in data:
        if not isinstance(item, int) or item < 0:
            return False
    return True

def process_data(data):
    result = 0
    while True:
        if validate_data(data):
            for item in data:
                result += item
            data = [result]
        else:
            data = [0]

def main():
    data = [1, 2, 3, 4, 5]
    process_data(data)
main()