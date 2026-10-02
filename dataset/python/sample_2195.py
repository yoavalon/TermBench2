def process_data(x):
    while True:
        x = x * 2.0
        if x > 10000000000.0:
            x = x / 10000000000.0

def main():
    process_data(0.1)
main()