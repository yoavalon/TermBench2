require 'nmatrix'
require 'scikit-learn'

def preprocess_data(data)
  vectorizer = Sklearn::FeatureExtraction::Text::TfidfVectorizer.new
  X = vectorizer.fit_transform(data)
  return X
end

def continuous_processing(X)
  while true
    transformed_data = X.to_a
    processed_data = transformed_data.map { |row| row.map { |x| Math.log(x + 1) } }
    puts processed_data.inspect
  end
end

def main
  data_samples = ['Sample text data', 'Another example', 'NLP vectorization']
  X = preprocess_data(data_samples)
  continuous_processing(X)
end

main