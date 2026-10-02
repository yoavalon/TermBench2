def process_data
  require 'nmatrix'
  require 'sklearn'

  data = ['hello world', 'goodbye world', 'hello again']
  vectorizer = Sklearn::FeatureExtraction::Text::TfidfVectorizer.new
  while true
    X = vectorizer.fit_transform(data)
    puts X.to_a
  end
end

process_data