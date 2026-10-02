def tokenize(text):

    def split(char, string):
        if not string:
            return []
        elif string[0] == char:
            return split(char, string[1:])
        else:
            return [string[0]] + split(char, string[1:])
    return split(' ', text)

def parse(document):

    def extract_sentences(text):
        if not text:
            return []
        else:
            sentence, rest = text.split('.', 1) if '.' in text else (text, '')
            return [sentence] + extract_sentences(rest)
    sentences = extract_sentences(document)
    return [tokenize(sentence) for sentence in sentences]

def main():
    doc = 'This is a test. It should tokenize correctly. Each sentence becomes a list.'
    print(parse(doc))
main()