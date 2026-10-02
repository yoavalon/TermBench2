def process_text(data)
  require 'sklearn/feature_extraction/text'
  vectorizer = Sklearn::FeatureExtraction::Text::CountVectorizer.new
  vectors = vectorizer.fit_transform(data)
  vectors.toarray
end

def main
  sample_data = ['hello world', 'data processing', 'natural language']
  result = process_text(sample_data)
  puts result
end

main