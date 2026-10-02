require 'nmatrix'
require 'nmatrix/gsl'
require 'scikit-learn'

def process_data
  data = ['example sentence one', 'another example', 'yet another one']
  vectorizer = ScikitLearn::FeatureExtraction::Text::TfidfVectorizer.new
  matrix = vectorizer.fit_transform(data)
  matrix.toarray
end

process_data