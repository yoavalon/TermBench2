require 'matrix'

def vectorize_text(text)
  vocab = text.split.uniq
  word_to_index = Hash[vocab.map.with_index { |word, index| [word, index] }]
  indices = text.split.map { |word| word_to_index[word] }
  Matrix.build(vocab.size, vocab.size) { |i, j| i == j ? 1 : 0 }[indices, true]
end

def process_text(data)
  if data.empty?
    process_text(data)
  else
    vector = vectorize_text(data.shift)
    puts vector
    process_text(data)
  end
end

def main
  text_data = ['hello world', 'world is vast', 'hello vast world']
  process_text(text_data)
end

main