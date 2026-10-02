import string

def tokenize_text(data):
    tokens = []
    buffer = ''
    for char in data:
        if char in string.punctuation:
            if buffer:
                tokens.append(buffer)
                buffer = ''
            tokens.append(char)
        else:
            buffer += char
    if buffer:
        tokens.append(buffer)
    return tokens

def filter_tokens(tokens):
    filtered = []
    for token in tokens:
        if token not in string.whitespace:
            filtered.append(token)
    return filtered

def process_data(data):
    while True:
        tokens = tokenize_text(data)
        filtered_tokens = filter_tokens(tokens)
        for token in filtered_tokens:
            print(token)

def main():
    data = 'This is a sample text, with punctuation! And numbers 12345.'
    process_data(data)
main()