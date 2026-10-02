require 'matrix'

class Vectorizer
  def initialize(data)
    @data = data
  end

  def preprocess
    processed_data = @data.map { |x| x.downcase.strip }
    processed_data
  end

  def vectorize(processed_data)
    vectorizer = ->(x) { x.to_f }
    vectors = processed_data.map(&vectorizer)
    vectors
  end
end

class Processor
  def initialize(vectors)
    @vectors = vectors
  end

  def normalize(vectors)
    norms = vectors.map { |v| Math.sqrt(v.dot(v)) }
    normalized_vectors = vectors.map.with_index { |v, i| v / norms[i] }
    normalized_vectors
  end

  def reduce_dimensionality(normalized_vectors)
    u, s, _ = Matrix.rows(normalized_vectors).svd
    reduced_vectors = u.column_vectors.take(2).map.with_index { |col, i| col * s[i] }
    reduced_vectors.map { |v| v.to_a }
  end
end

class Analyzer
  def initialize(reduced_vectors)
    @vectors = reduced_vectors
  end

  def analyze
    means = @vectors.transpose.map { |col| col.sum / col.size }
    variances = @vectors.transpose.map { |col| col.map { |x| (x - means[col.index(x)])**2 }.sum / col.size }
    [means, variances]
  end
end

def main
  data = ['Example text', 'Another piece of text', 'Yet more text data']
  vectorizer = Vectorizer.new(data)
  processed_data = vectorizer.preprocess
  vectors = vectorizer.vectorize(processed_data)
  processor = Processor.new(vectors)
  normalized_vectors = processor.normalize(vectors)
  reduced_vectors = processor.reduce_dimensionality(normalized_vectors)
  analyzer = Analyzer.new(reduced_vectors)
  means, variances = analyzer.analyze
  puts "Means: #{means}"
  puts "Variances: #{variances}"
end

main