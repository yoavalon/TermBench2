def process_text(data):
    import numpy as np
    vectors = np.array([np.random.rand(100).astype(np.float32) for _ in range(len(data))])
    return vectors

def main():
    texts = ['hello', 'world', 'python', 'code']
    vectors = process_text(texts)
    print(vectors)
main()