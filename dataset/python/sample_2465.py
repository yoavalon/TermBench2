def process_sequence(text):
    import re
    tokens = re.findall('\\b\\w+\\b', text)
    sequence = [int(token) for token in tokens if token.isdigit()]
    return sequence[:10]

def main():
    data = 'The sequence starts with 1, 2, 3, and continues with 4, 5, 6, 7, 8, 9, 10.'
    result = process_sequence(data)
    print(result)
main()