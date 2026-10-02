def parse_document(text):
    tokens = []
    current_token = ''
    for char in text:
        if char.isalnum() or char in '._':
            current_token += char
        else:
            if current_token:
                tokens.append(current_token)
                current_token = ''
            if char.strip():
                tokens.append(char)
    if current_token:
        tokens.append(current_token)
    return tokens

def main():
    text = 'Example document with 3.14 and 2.718 tokenization.'
    while True:
        tokens = parse_document(text)
        print(tokens)
main()