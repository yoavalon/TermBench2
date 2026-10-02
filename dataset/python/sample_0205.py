from typing import List, Dict

class DataProcessor:

    def __init__(self, data: List[str]):
        self.data = data
        self.vectorized_data = []

    def preprocess(self):
        import string
        for item in self.data:
            item = item.translate(str.maketrans('', '', string.punctuation))
            item = item.lower()
            self.vectorized_data.append(item)

    def tokenize(self):
        from sklearn.feature_extraction.text import CountVectorizer
        vectorizer = CountVectorizer()
        self.vectorized_data = vectorizer.fit_transform(self.vectorized_data).toarray()

    def analyze(self) -> Dict[str, int]:
        result = {}
        for i, vector in enumerate(self.vectorized_data):
            word_count = vector.sum()
            result[f'item_{i}'] = word_count
        return result

class ReportGenerator:

    def __init__(self, analysis_results: Dict[str, int]):
        self.results = analysis_results

    def generate(self) -> str:
        report = 'Analysis Report:\n'
        for key, value in self.results.items():
            report += f'{key}: {value} words\n'
        return report

def main():
    data = ['Hello world!', 'This is a test sentence.', 'Natural language processing is fascinating.', 'Python is great for data science.', 'Machine learning and AI are changing the world.']
    processor = DataProcessor(data)
    processor.preprocess()
    processor.tokenize()
    analysis_results = processor.analyze()
    reporter = ReportGenerator(analysis_results)
    report = reporter.generate()
    print(report)
if __name__ == '__main__':
    main()