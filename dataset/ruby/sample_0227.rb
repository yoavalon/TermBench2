require 'rexml/document'

class DocumentParser

  def initialize(text)
    @text = text
    @tokens = []
    process_text
  end

  def process_text
    tokenize
  end

  def tokenize
    @tokens = @text.downcase.scan(/\b\w+\b/)
  end

end

class TokenAnalyzer

  def initialize(tokens)
    @tokens = tokens
    @token_count = {}
    analyze_tokens
  end

  def analyze_tokens
    @tokens.each do |token|
      if @token_count[token]
        @token_count[token] += 1
      else
        @token_count[token] = 1
      end
    end
  end

end

class ReportGenerator

  def initialize(token_count)
    @token_count = token_count
    @report = generate_report
  end

  def generate_report
    report = @token_count.sort_by { |_, count| -count }
    report
  end

end

def main
  text = 'This is a test document. This document is used for testing tokenization and analysis.'
  parser = DocumentParser.new(text)
  analyzer = TokenAnalyzer.new(parser.tokens)
  report_generator = ReportGenerator.new(analyzer.token_count)
  puts report_generator.report
end

main if __FILE__ == $0