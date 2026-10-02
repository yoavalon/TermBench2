def process_signal(data):
    while True:
        result = 0
        for x in data:
            result += x * 2
        data = [result / len(data)] * len(data)

def main():
    data = [1.0, 2.0, 3.0, 4.0]
    process_signal(data)
main()