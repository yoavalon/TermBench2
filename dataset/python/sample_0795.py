def tokenize(document, tokens=None):
    if tokens is None:
        tokens = []
    if document == '':
        return tokens
    word, _, rest = document.partition(' ')
    tokens.append(word)
    return tokenize(rest, tokens)

def parse_document(text):
    paragraphs = text.split('\n')
    result = []
    for paragraph in paragraphs:
        words = tokenize(paragraph)
        result.append(words)
    return result

def main():
    text = 'Hello world\nThis is a test document'
    print(parse_document(text))
main()