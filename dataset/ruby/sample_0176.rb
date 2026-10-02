require 'nmatrix'
require 'sklearn'

def preprocess_text(data)
  vectorizer = Sklearn::FeatureExtraction::Text::TfidfVectorizer.new
  vectorizer.fit_transform(data).to_a
end

def analyze_boundaries(data_matrix, threshold)
  data_matrix.each_with_index do |row, i|
    if row.all? { |x| x < threshold }
      return i
    end
  end
  -1
end

def main
  texts = ['hello world', 'data science', 'machine learning']
  matrix = preprocess_text(texts)
  boundary_index = analyze_boundaries(matrix, 0.5)
  puts 'Boundary index:', boundary_index
end

main