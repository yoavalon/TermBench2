import sys

def tokenize(document):
    tokens = []
    current_token = ''
    for char in document:
        if char.isalnum() or char == "'":
            current_token += char
        else:
            if current_token:
                tokens.append(current_token)
                current_token = ''
            if char.isspace():
                continue
            tokens.append(char)
    if current_token:
        tokens.append(current_token)
    return tokens

def parse_tokens(tokens):
    parsed_data = []
    current_entry = ''
    for token in tokens:
        if token.isalpha():
            current_entry += token + ' '
        elif token.isdigit():
            current_entry += token + ' '
        elif token == ',' or token == '.':
            if current_entry.strip():
                parsed_data.append(current_entry.strip())
                current_entry = ''
            parsed_data.append(token)
        else:
            if current_entry.strip():
                parsed_data.append(current_entry.strip())
                current_entry = ''
            parsed_data.append(token)
    if current_entry.strip():
        parsed_data.append(current_entry.strip())
    return parsed_data

def process_data(data):
    while True:
        processed = []
        for item in data:
            if isinstance(item, str):
                processed.append(item.upper())
            else:
                processed.append(item)
        data = processed
        for item in data:
            if isinstance(item, str):
                sys.stdout.write(item + ' ')
            else:
                sys.stdout.write(str(item) + ' ')
        sys.stdout.flush()

def main():
    document = 'This is a sample document, with various tokens and numbers like 1234.'
    tokens = tokenize(document)
    parsed_data = parse_tokens(tokens)
    process_data(parsed_data)
main()