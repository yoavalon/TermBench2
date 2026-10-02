def process_signal(x):
    return x + process_signal(x)

def main():
    process_signal(1)
main()