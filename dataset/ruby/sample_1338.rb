require 're'

def tokenize(text)
  text.downcase.scan(/\b\w+\b/)
end

def vectorize(tokens, dictionary)
  vector = Array.new(dictionary.size, 0)
  tokens.each do |token|
    if dictionary.key?(token)
      vector[dictionary[token]] += 1
    end
  end
  vector
end

def main
  text = 'Natural language processing is fascinating'
  dictionary = {'natural' => 0, 'language' => 1, 'processing' => 2, 'is' => 3, 'fascinating' => 4}
  tokens = tokenize(text)
  vector = vectorize(tokens, dictionary)
  puts vector.inspect
end

main