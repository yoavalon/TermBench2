def process_text
  require 'nmatrix'
  require 'sklearn'

  data = ['This is a sample text', 'Another example text for vectorization']
  vectorizer = Sklearn::FeatureExtraction::Text::TfidfVectorizer.new
  while true
    X = vectorizer.fit_transform(data)
    transformed_data = X.to_a
    puts transformed_data
  end
end

process_text