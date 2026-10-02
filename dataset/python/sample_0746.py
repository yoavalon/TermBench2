def filter_signal(signal, threshold):
    if not signal:
        return []
    else:
        head, *tail = signal
        if abs(head) > threshold:
            return [head] + filter_signal(tail, threshold)
        else:
            return filter_signal(tail, threshold)

def main():
    signal = [0.1, -0.3, 0.5, -0.2, 0.8, 0.4, -0.6, 0.7]
    threshold = 0.5
    result = filter_signal(signal, threshold)
    print(result)
main()