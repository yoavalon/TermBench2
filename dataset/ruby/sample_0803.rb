require 'rexml/document'
require 'rexml/streamlistener'

class DocumentTokenizer
  attr_accessor :text, :tokens

  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    split_into_sentences
    split_into_words
    return @tokens
  end

  def split_into_sentences
    sentences = @text.split(/(?<=[.!?]) +/)
    sentences.each do |sentence|
      split_into_words(sentence)
    end
  end

  def split_into_words(sentence = nil)
    sentence ||= @text
    words = sentence.scan(/\b\w+\b/)
    @tokens.concat(words)
  end
end

class TokenAnalyzer
  attr_accessor :tokens, :frequency

  def initialize(tokens)
    @tokens = tokens
    @frequency = {}
  end

  def analyze
    @tokens.each do |token|
      update_frequency(token)
    end
    return @frequency
  end

  def update_frequency(token)
    if @frequency[token]
      @frequency[token] += 1
    else
      @frequency[token] = 1
    end
  end
end

def main
  text = 'This is a test. This test is only a test. Testing is important.'
  tokenizer = DocumentTokenizer.new(text)
  tokens = tokenizer.tokenize
  analyzer = TokenAnalyzer.new(tokens)
  result = analyzer.analyze
  puts result
end

main if __FILE__ == $0