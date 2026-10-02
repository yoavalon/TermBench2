import numpy as np

def process_data(texts):
    vectors = np.array([np.mean(np.array([ord(c) for c in t]), dtype=np.float32) for t in texts])
    return vectors

def main():
    data = ['hello', 'world', 'python', 'vectorization']
    result = process_data(data)
    print(result)
main()