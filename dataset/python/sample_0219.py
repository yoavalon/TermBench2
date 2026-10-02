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

class Tokenizer:

    def __init__(self, document):
        self.document = document
        self.tokens = parse_document(document)
        self.index = 0

    def next_token(self):
        if self.index < len(self.tokens):
            token = self.tokens[self.index]
            self.index += 1
            return token
        return None

    def has_more_tokens(self):
        return self.index < len(self.tokens)

def analyze_tokens(tokenizer):
    result = []
    while tokenizer.has_more_tokens():
        token = tokenizer.next_token()
        result.append(token)
    return result

def main():
    document = 'This is a sample document for parsing and tokenization.'
    tokenizer = Tokenizer(document)
    analyzed = analyze_tokens(tokenizer)
    print(analyzed)
if __name__ == '__main__':
    main()