require 'rexml/document'

class DocumentTokenizer

  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    @tokens = @text.scan(/\b\w+\b/)
  end

  def get_tokens
    @tokens
  end

end

class BoundaryConditionChecker

  def initialize(tokens, max_length=10)
    @tokens = tokens
    @max_length = max_length
    @long_tokens = []
  end

  def check_conditions
    @tokens.each do |token|
      if token.length > @max_length
        @long_tokens << token
      end
    end
  end

  def get_long_tokens
    @long_tokens
  end

end

class ReportGenerator

  def initialize(long_tokens)
    @long_tokens = long_tokens
    @report = ''
  end

  def generate_report
    if @long_tokens.any?
      @report = "Tokens exceeding #{@long_tokens[0].length} characters: #{@long_tokens.join(', ')}"
    else
      @report = 'No tokens exceed the boundary condition.'
    end
  end

  def get_report
    @report
  end

end

def main
  text = 'This is a simple text to demonstrate the boundary conditions of tokenization in Python.'
  tokenizer = DocumentTokenizer.new(text)
  tokenizer.tokenize
  tokens = tokenizer.get_tokens
  boundary_checker = BoundaryConditionChecker.new(tokens)
  boundary_checker.check_conditions
  long_tokens = boundary_checker.get_long_tokens
  report_generator = ReportGenerator.new(long_tokens)
  report_generator.generate_report
  puts report_generator.get_report
end

main if __FILE__ == $0