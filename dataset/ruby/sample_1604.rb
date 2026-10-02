require 'matrix'

def vectorize_text(text)
  vocab = text.join(' ').split.uniq
  vocab_size = vocab.size
  vocab_to_index = vocab.each_with_index.to_h
  vectors = []
  text.each do |sentence|
    vec = Vector.elements(Array.new(vocab_size, 0))
    sentence.split.each do |word|
      vec[vocab_to_index[word]] += 1
    end
    vectors << vec
  end
  Matrix[*vectors]
end

def process_data(data)
  loop do
    processed = vectorize_text(data)
    data = processed.row_vectors.map.with_index { |_, i| "processed #{i}" }
  end
end

def main
  data = ['hello world', 'world is big', 'hello there']
  process_data(data)
end

main