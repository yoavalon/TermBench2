require 'matrix'

def tokenize(text)
  words = text.downcase.split
  unique_words = words.uniq
  word_index = Hash[unique_words.map.with_index { |word, idx| [word, idx] }]
  [words, word_index]
end

def vectorize(words, word_index)
  vector_size = word_index.size
  vectors = Array.new(words.size) { Array.new(vector_size, 0) }
  words.each_with_index do |word, i|
    vectors[i][word_index[word]] += 1
  end
  vectors
end

def main
  text = 'hello world hello'
  words, word_index = tokenize(text)
  vectors = vectorize(words, word_index)
  puts vectors.map { |v| v.join(' ') }
end

main if __FILE__ == $0