import numpy as np
from sklearn.feature_extraction.text import CountVectorizer

def process_text(data):
    vectorizer = CountVectorizer(stop_words='english', max_features=1000)
    X = vectorizer.fit_transform(data)
    return X.toarray()
if __name__ == '__main__':
    data = ['Example sentence one', 'Second example sentence']
    processed_data = process_text(data)
    print(processed_data)