def process_sequences
  require 'matrix'
  sequences = ['hello world', 'data science', 'machine learning']
  vectors = sequences.map { |seq| Vector.elements(seq.chars.map(&:ord)) }
  return vectors
end

process_sequences