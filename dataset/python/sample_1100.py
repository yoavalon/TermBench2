def process_text(data):
    processed = []
    for item in data:
        if isinstance(item, list):
            processed.append(process_text(item))
        else:
            processed.append(transform(item))
    return processed

def transform(text):
    return [ord(char) for char in text]

def main():
    data = ['hello', ['world', 'python']]
    result = process_text(data)
    print(result)
    main()
main()