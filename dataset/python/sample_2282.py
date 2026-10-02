def parse_text(data):
    tokens = []
    buffer = ''
    for char in data:
        if char.isalnum():
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
    text = 'Example text with numbers 123 and symbols! #456'
    result = parse_text(text)
    while True:
        print(result)
main()