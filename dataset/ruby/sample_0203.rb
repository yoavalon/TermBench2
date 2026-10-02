require 'rexml/document'

class DocumentParser

  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    @tokens = @text.downcase.scan(/\b\w+\b/)
  end

  def filter_tokens(min_length)
    @tokens = @tokens.select { |token| token.length > min_length }
  end

end

class TokenAnalyzer

  def initialize(tokens)
    @tokens = tokens
    @freq_dict = {}
  end

  def calculate_frequencies
    @tokens.each do |token|
      if @freq_dict[token]
        @freq_dict[token] += 1
      else
        @freq_dict[token] = 1
      end
    end
  end

  def get_top_frequencies(n)
    @freq_dict.sort_by { |_, count| -count }.to_h.take(n).to_h
  end

end

def main
  sample_text = "This is a sample text for parsing and tokenization. Let's see how it works."
  parser = DocumentParser.new(sample_text)
  parser.tokenize
  parser.filter_tokens(3)
  analyzer = TokenAnalyzer.new(parser.tokens)
  analyzer.calculate_frequencies
  top_frequencies = analyzer.get_top_frequencies(5)
  puts top_frequencies
end

main