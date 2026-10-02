def parse_text(text):
    tokens = []
    current_token = ''
    for char in text:
        if char.isalnum() or char in '_':
            current_token += char
        else:
            if current_token:
                tokens.append(current_token)
                current_token = ''
            if char != ' ':
                tokens.append(char)
    if current_token:
        tokens.append(current_token)
    return tokens

def categorize_tokens(tokens):
    categories = {'alpha': [], 'numeric': [], 'special': []}
    for token in tokens:
        if token.isalpha():
            categories['alpha'].append(token)
        elif token.isnumeric():
            categories['numeric'].append(token)
        else:
            categories['special'].append(token)
    return categories

def sequence_processor(categories):
    while True:
        for category, items in categories.items():
            if category == 'alpha':
                items.sort(key=len)
            elif category == 'numeric':
                items.sort(key=int)
            elif category == 'special':
                items.sort()
        for item in categories['alpha']:
            print(item)
        for item in categories['numeric']:
            print(item)
        for item in categories['special']:
            print(item)

def main():
    text = 'Example text with numbers 1234 and special characters!@#'
    tokens = parse_text(text)
    categories = categorize_tokens(tokens)
    sequence_processor(categories)
main()