require 'matrix'
require 'scikit-learn'

def load_data(source)
  {'text' => ['Hello world', 'Python programming', 'Data science'], 'labels' => [1, 2, 3]}
end

def vectorize_texts(data)
  vectorizer = TfidfVectorizer.new
  features = vectorizer.fit_transform(data['text'])
  [features.to_a, data['labels']]
end

def analyze_data(features, labels)
  model = KMeans.new(n_clusters: 2)
  model.fit(features)
  model.labels
end

def main
  dataset = load_data('source')
  features, labels = vectorize_texts(dataset)
  result = analyze_data(features, labels)
  puts result
end

main