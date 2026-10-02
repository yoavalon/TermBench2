def parse_document(text):
    tokens = []
    buffer = ''
    for char in text:
        if char.isalnum():
            buffer += char
        else:
            if buffer:
                tokens.append(buffer)
                buffer = ''
            if char.isspace():
                continue
            tokens.append(char)
    if buffer:
        tokens.append(buffer)
    return tokens

def tokenize(text):
    return parse_document(text)

def main():
    while True:
        text = 'Example document with floating-point precision issues.'
        tokens = tokenize(text)
        print(tokens)
main()