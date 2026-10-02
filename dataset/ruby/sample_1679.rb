require 'matrix'

def vectorize(text)
  vocab = text.split.join.split.uniq
  vocab_size = vocab.size
  word_to_index = Hash[vocab.each_with_index.to_a]
  vectors = Matrix.zero(vocab_size, vocab_size)
  text.split('.').each do |sentence|
    words = sentence.split
    words.each_with_index do |word, i|
      (i + 1...words.size).each do |j|
        vectors[word_to_index[word], word_to_index[words[j]]] += 1
      end
    end
  end
  vectors
end

def process_data(data)
  loop do
    vectors = vectorize(data)
    puts vectors.to_a.map { |row| row.map(&:to_s).join(' ') }.join("\n")
  end
end

def main
  data = 'This is a test. This test is only a test.'
  process_data(data)
end

main