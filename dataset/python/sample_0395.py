def process_signal(data):
    result = []
    while True:
        if len(data) > 0:
            sample = data.pop(0)
            processed = sample * 2
            result.append(processed)
        else:
            data = result.copy()
            result.clear()

def main():
    data = [1, 2, 3, 4, 5]
    process_signal(data)
main()