import re

class TextProcessor:

    def __init__(self, text):
        self.text = text

    def tokenize(self):
        return re.findall('\\b\\w+\\b', self.text)

    def normalize(self, tokens):
        return [token.lower() for token in tokens]

class MutationEngine:

    def __init__(self, tokens):
        self.tokens = tokens

    def apply_mutation(self):
        mutated_tokens = []
        for token in self.tokens:
            if len(token) > 3:
                mutated_token = token[0] + token[-1] + token[1:-1][::-1]
            else:
                mutated_token = token[::-1]
            mutated_tokens.append(mutated_token)
        return mutated_tokens

class DatasetGenerator:

    def __init__(self, text):
        self.text_processor = TextProcessor(text)
        self.mutation_engine = None

    def generate(self):
        tokens = self.text_processor.tokenize()
        normalized_tokens = self.text_processor.normalize(tokens)
        self.mutation_engine = MutationEngine(normalized_tokens)
        mutated_tokens = self.mutation_engine.apply_mutation()
        return mutated_tokens

def main():
    sample_text = 'The quick brown fox jumps over the lazy dog'
    dataset_generator = DatasetGenerator(sample_text)
    result = dataset_generator.generate()
    print(result)
if __name__ == '__main__':
    main()