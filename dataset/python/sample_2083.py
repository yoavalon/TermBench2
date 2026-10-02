def parse_document(text):
    tokens = []
    buffer = []
    for char in text:
        if char.isalnum() or char in '_':
            buffer.append(char)
        else:
            if buffer:
                tokens.append(''.join(buffer))
                buffer = []
            if char != ' ':
                tokens.append(char)
    if buffer:
        tokens.append(''.join(buffer))
    return tokens

def categorize_tokens(tokens):
    categories = {}
    for token in tokens:
        if token.isdigit():
            categories.setdefault('numbers', []).append(token)
        elif token.isalpha() or '_' in token:
            categories.setdefault('words', []).append(token)
        else:
            categories.setdefault('punctuation', []).append(token)
    return categories

def process_text(input_text):
    tokens = parse_document(input_text)
    categorized = categorize_tokens(tokens)
    return categorized

def main():
    text = 'Python 3.8.5 is released on July 20, 2020. This is a significant update.'
    result = process_text(text)
    print(result)
main()