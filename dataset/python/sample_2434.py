import re

def process_text(data):
    tokens = re.findall('\\b\\w+\\b', data)
    sequences = []
    for token in tokens:
        if token.isdigit():
            sequences.append(int(token))
    return sequences

def main():
    text = 'The sequence starts at 1, then 2, 3, and so on until 10.'
    result = process_text(text)
    print(result)
main()