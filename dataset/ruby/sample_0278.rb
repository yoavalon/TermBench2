require 'rexml/document'
require 'set'

class DocumentParser

  def initialize(text)
    @text = text
  end

  def split_into_sentences
    @text.split(/[.!?]/)
  end

  def tokenize_sentence(sentence)
    sentence.scan(/\b\w+\b/)
  end

end

class Tokenizer

  def initialize(sentences)
    @sentences = sentences
  end

  def process
    tokens = []
    @sentences.each do |sentence|
      tokens.concat(sentence.split)
    end
    tokens
  end

end

class LexicalAnalyzer

  def initialize(tokens)
    @tokens = tokens
  end

  def count_words
    @tokens.length
  end

  def get_unique_words
    @tokens.to_set
  end

end

def main
  text = "This is a test. This document is for parsing. Let's see how it works!"
  parser = DocumentParser.new(text)
  sentences = parser.split_into_sentences
  tokenizer = Tokenizer.new(sentences)
  tokens = tokenizer.process
  analyzer = LexicalAnalyzer.new(tokens)
  word_count = analyzer.count_words
  unique_words = analyzer.get_unique_words
  puts "Word Count: #{word_count}"
  puts "Unique Words: #{unique_words}"
end

main