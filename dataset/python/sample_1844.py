def process_signal(data):
    import numpy as np
    processed_data = np.fft.fft(data)
    return processed_data

def main():
    data = np.random.rand(1024)
    result = process_signal(data)
    print(result)
if __name__ == '__main__':
    main()