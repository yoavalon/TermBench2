class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.vectorized_data = []

    def process(self):
        for item in self.data:
            vector = self.transform(item)
            self.vectorized_data.append(vector)

    def transform(self, item):
        tokens = self.tokenize(item)
        vector = self.embed(tokens)
        return vector

    def tokenize(self, item):
        return item.split()

    def embed(self, tokens):
        return [self.embed_token(token) for token in tokens]

    def embed_token(self, token):
        return sum((ord(char) for char in token)) / len(token)

class Dataset:

    def __init__(self, raw_data):
        self.raw_data = raw_data

    def clean(self):
        cleaned_data = [self.preprocess(item) for item in self.raw_data]
        return cleaned_data

    def preprocess(self, item):
        item = item.lower()
        item = self.remove_punctuation(item)
        return item

    def remove_punctuation(self, item):
        punctuation = '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'
        return ''.join((char for char in item if char not in punctuation))

def main():
    raw_data = ['Hello, world!', 'Natural language processing is fascinating.', 'Recursion can be tricky.']
    dataset = Dataset(raw_data)
    cleaned_data = dataset.clean()
    vectorizer = Vectorizer(cleaned_data)
    vectorizer.process()
    print(vectorizer.vectorized_data)
if __name__ == '__main__':
    main()