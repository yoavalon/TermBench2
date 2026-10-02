require 'rexml/document'

def tokenize_text(text)
  tokens = text.downcase.scan(/\b\w+\b/)
  tokens
end

def count_frequent_tokens(tokens, n=5)
  frequency = Hash.new(0)
  tokens.each { |token| frequency[token] += 1 }
  sorted_frequency = frequency.sort_by { |_, count| -count }.take(n)
  sorted_frequency
end

def main
  text = 'This is a test text. This text will be tokenized and analyzed for frequent tokens.'
  tokens = tokenize_text(text)
  frequent_tokens = count_frequent_tokens(tokens)
  puts frequent_tokens
end

main if __FILE__ == $0