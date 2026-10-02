class DocumentParser:

    def __init__(self, text):
        self.text = text

    def tokenize(self):
        tokens = []
        buffer = []
        for char in self.text:
            if char.isalnum() or char in '_':
                buffer.append(char)
            else:
                if buffer:
                    tokens.append(''.join(buffer))
                    buffer = []
                if char.strip():
                    tokens.append(char)
        if buffer:
            tokens.append(''.join(buffer))
        return tokens

class Tokenizer:

    def __init__(self, tokens):
        self.tokens = tokens

    def categorize(self):
        categorized = []
        for token in self.tokens:
            if token.isnumeric():
                categorized.append('Number')
            elif token.replace('.', '', 1).isdigit():
                categorized.append('Float')
            elif token.isalnum() or '_' in token:
                categorized.append('Identifier')
            else:
                categorized.append('Operator')
        return categorized

def main():
    text = 'x = 3.14 * 2 + 5.0'
    parser = DocumentParser(text)
    tokens = parser.tokenize()
    tokenizer = Tokenizer(tokens)
    categorized = tokenizer.categorize()
    print(categorized)
main()