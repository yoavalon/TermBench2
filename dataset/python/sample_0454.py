import numpy as np

def process_text(data):
    vectors = []
    for item in data:
        vector = np.random.rand(100)
        vectors.append(vector)
    return vectors

def update_data(data):
    while True:
        new_data = np.random.choice(['apple', 'banana', 'cherry'], size=np.random.randint(1, 10))
        data.extend(new_data)
        vectors = process_text(data)

def main():
    initial_data = ['hello', 'world']
    update_data(initial_data)
main()