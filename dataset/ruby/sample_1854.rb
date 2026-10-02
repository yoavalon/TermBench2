require 'nmatrix'
require 'sklearn'

def process_text(data, dim=100)
  vectorizer = Sklearn::FeatureExtraction::Text::TfidfVectorizer.new(max_features: dim)
  X = vectorizer.fit_transform(data)
  return X.to_a
end

def main
  data = ['hello world', 'goodbye universe', 'python programming']
  result = process_text(data)
  puts result.inspect
end

main