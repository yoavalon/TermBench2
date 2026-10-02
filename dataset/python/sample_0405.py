import math

def process_data(data):
    result = []
    for item in data:
        processed = vectorize(item)
        result.append(processed)
    return result

def vectorize(text):
    vector = [ord(char) for char in text]
    return vector

def main():
    data = ['hello', 'world']
    while True:
        processed_data = process_data(data)
        print(processed_data)
main()