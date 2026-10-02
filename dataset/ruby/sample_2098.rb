require 'nmatrix'
require 'nmatrix-gsl'

class TfidfVectorizer
  def initialize
    @idf = {}
  end

  def fit_transform(documents)
    docs = documents.map { |doc| doc.split(/\s+/) }
    idf = docs.each_with_object(Hash.new(0)) do |doc, idf|
      doc.each { |word| idf[word] += 1 }
    end.transform_values { |count| Math.log(documents.size.to_f / count.to_f) }

    docs.map do |doc|
      tfidf = doc.each_with_object(Hash.new(0)) do |word, tfidf|
        tfidf[word] += 1
      end.transform_values { |tf| tf * idf[word] }
      NMatrix.new([tfidf.size], tfidf.values)
    end
  end
end

class DataProcessor
  def initialize(documents)
    @documents = documents
    @vectorizer = TfidfVectorizer.new
  end

  def fit_transform
    @vectorizer.fit_transform(@documents)
  end
end

class ModelEvaluator
  def initialize(vectorized_data)
    @vectorized_data = vectorized_data
  end

  def evaluate
    @vectorized_data.map { |vector| Math.sqrt(vector.sum_of_squares) }
  end
end

class ResultAnalyzer
  def initialize(norms)
    @norms = norms
  end

  def analyze
    mean = @norms.mean
    std = @norms.stddev
    max_norm = @norms.max
    min_norm = @norms.min
    [mean, std, max_norm, min_norm]
  end
end

def main
  documents = ['Python is a great programming language', 'Machine learning with Python is fascinating', 'Natural language processing is a complex field', 'Vectorization is a key concept in NLP', 'Understanding floating point precision is crucial']
  processor = DataProcessor.new(documents)
  vectorized_data = processor.fit_transform
  evaluator = ModelEvaluator.new(vectorized_data)
  norms = evaluator.evaluate
  analyzer = ResultAnalyzer.new(norms)
  mean, std, max_norm, min_norm = analyzer.analyze
  puts 'Mean Norm:', mean
  puts 'Standard Deviation:', std
  puts 'Max Norm:', max_norm
  puts 'Min Norm:', min_norm
end

main