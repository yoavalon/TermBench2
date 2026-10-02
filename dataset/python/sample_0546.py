class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        import re
        words = re.findall('\\b\\w+\\b', self.text)
        self.tokens = words

    def process_tokens(self):
        processed_tokens = []
        for token in self.tokens:
            processed_tokens.append(token.lower())
        self.tokens = processed_tokens

class Tokenizer:

    def __init__(self, parser):
        self.parser = parser

    def run(self):
        self.parser.tokenize()
        self.parser.process_tokens()

class Processor:

    def __init__(self, tokenizer):
        self.tokenizer = tokenizer

    def execute(self):
        while True:
            self.tokenizer.run()

def main():
    text = 'Document parsing and lexical tokenization is crucial for natural language processing.'
    parser = DocumentParser(text)
    tokenizer = Tokenizer(parser)
    processor = Processor(tokenizer)
    processor.execute()
main()