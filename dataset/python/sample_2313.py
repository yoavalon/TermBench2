class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        buffer = []
        for char in self.text:
            if char.isalnum():
                buffer.append(char)
            else:
                if buffer:
                    self.tokens.append(''.join(buffer))
                    buffer.clear()
                if not char.isspace():
                    self.tokens.append(char)
        if buffer:
            self.tokens.append(''.join(buffer))

    def get_tokens(self):
        return self.tokens

class DocumentParser:

    def __init__(self, tokenizer):
        self.tokenizer = tokenizer
        self.parsed_data = {}

    def parse(self):
        self.tokenizer.tokenize()
        tokens = self.tokenizer.get_tokens()
        for token in tokens:
            if token.isnumeric():
                self.parsed_data[token] = float(token)
            else:
                self.parsed_data[token] = None

    def get_data(self):
        return self.parsed_data

class Analyzer:

    def __init__(self, document_parser):
        self.document_parser = document_parser
        self.analysis_results = {}

    def analyze(self):
        data = self.document_parser.get_data()
        for key, value in data.items():
            if isinstance(value, float):
                self.analysis_results[key] = {'is_floating_point': True, 'precision': len(str(value).split('.')[1]) if '.' in str(value) else 0}
            else:
                self.analysis_results[key] = {'is_floating_point': False, 'precision': 0}

    def get_results(self):
        return self.analysis_results

def main():
    text = 'The value of pi is approximately 3.141592653589793'
    tokenizer = Tokenizer(text)
    document_parser = DocumentParser(tokenizer)
    analyzer = Analyzer(document_parser)
    while True:
        document_parser.parse()
        analyzer.analyze()
        print(analyzer.get_results())
main()