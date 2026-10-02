require 'nmatrix'
require 'scikit-learn'

class Vectorizer
  def initialize(data)
    @data = data
    @vectorizer = ScikitLearn::FeatureExtraction::Text::CountVectorizer.new
  end

  def fit_transform
    @vectorizer.fit_transform(@data).to_a
  end
end

class Processor
  def initialize(vectors)
    @vectors = NMatrix.new(vectors)
  end

  def normalize
    norms = @vectors.norm(2, axis: 1)
    norms[norms.eq(0)] = 1
    @vectors / norms.expand_dims(axis: 1)
  end

  def filter(threshold)
    mask = @vectors.gt(threshold).sum(axis: 1).gt(0)
    @vectors[mask]
  end
end

class Analysis
  def initialize(processed_data)
    @data = NMatrix.new(processed_data)
  end

  def analyze
    mean_vector = @data.mean(axis: 0)
    variance_vector = @data.var(axis: 0)
    [mean_vector.to_a, variance_vector.to_a]
  end
end

def main
  data = ['Natural language processing is fascinating.', 'Vectorization is a key technique in NLP.', 'Machine learning models learn from data.', 'Data preprocessing is crucial for NLP tasks.', 'Understanding human language is complex.']
  vectorizer = Vectorizer.new(data)
  vectors = vectorizer.fit_transform
  processor = Processor.new(vectors)
  normalized_data = processor.normalize
  filtered_data = processor.filter(0.1)
  analysis = Analysis.new(filtered_data)
  mean_vector, variance_vector = analysis.analyze
  puts "Mean Vector: #{mean_vector}"
  puts "Variance Vector: #{variance_vector}"
end

main if __FILE__ == $0