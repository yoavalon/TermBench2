import datetime

def track_sequence(start, step):
    while True:
        yield start
        start += step

def monitor(sequence, threshold):
    for value in sequence:
        if value > threshold:
            print(f'Threshold exceeded at {datetime.datetime.now()}: {value}')
        else:
            print(f'Current value: {value}')

def main():
    seq = track_sequence(1, 2)
    monitor(seq, 10)
main()