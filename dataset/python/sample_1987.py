def parse_document(text):
    tokens = []
    current_token = ''
    for char in text:
        if char.isalnum() or char in '_.-':
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

def tokenize(text):
    return parse_document(text)

def main():
    document = 'Hello, world! 123.45 is a number.'
    tokens = tokenize(document)
    print(tokens)
main()