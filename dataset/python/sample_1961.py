def parse_document(text):
    tokens = []
    buffer = ''
    for char in text:
        if char.isalnum() or char == '.':
            buffer += char
        else:
            if buffer:
                tokens.append(buffer)
                buffer = ''
            if char != ' ':
                tokens.append(char)
    if buffer:
        tokens.append(buffer)
    return tokens

def main():
    document = 'Example 1.23 and 4.567.'
    tokens = parse_document(document)
    print(tokens)
main()