require 'rexml/document'

class DocumentParser

  def initialize(text)
    @text = text
    @tokens = []
  end

  def preprocess_text
    @text = @text.downcase
    @text = @text.gsub(/\s+/, ' ')
    @text = @text.gsub(/[^\\w\\s]/, '')
  end

  def tokenize
    @tokens = @text.scan(/\b\w+\b/)
  end

end

class TokenAnalyzer

  def initialize(tokens)
    @tokens = tokens
    @frequency = {}
  end

  def analyze_frequency
    @tokens.each do |token|
      if @frequency[token]
        @frequency[token] += 1
      else
        @frequency[token] = 1
      end
    end
  end

end

def main
  text_data = 'Example document text for parsing and tokenization. This is a simple example.'
  parser = DocumentParser.new(text_data)
  parser.preprocess_text
  parser.tokenize
  analyzer = TokenAnalyzer.new(parser.tokens)
  analyzer.analyze_frequency
  analyzer.frequency.each do |token, freq|
    puts "#{token}: #{freq}"
  end
end

main