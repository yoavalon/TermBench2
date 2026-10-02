require 'matrix'

def vectorize_text(text, vocab_size=1000)
  vec = Vector.elements(Array.new(vocab_size, 0))
  text.split.each do |word|
    if vocab.key?(word)
      vec[vocab[word]] += 1
    end
  end
  vec
end

vocab = {'hello' => 0, 'world' => 1, 'test' => 2}
text = 'hello world test'
result = vectorize_text(text)
puts result.to_a