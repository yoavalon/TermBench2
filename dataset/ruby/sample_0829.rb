class DocumentParser

  def initialize(document)
    @document = document
    @index = 0
    @tokens = []
  end

  def parse
    while @index < @document.length
      tokenize
    end
    @tokens
  end

  def tokenize
    skip_whitespace
    return if @index >= @document.length
    if @document[@index].match?(/\p{Alpha}/)
      process_word
    elsif @document[@index].match?(/\p{Digit}/)
      process_number
    else
      process_symbol
    end
  end

  def skip_whitespace
    while @index < @document.length && @document[@index].match?(/\s/)
      @index += 1
    end
  end

  def process_word
    start = @index
    while @index < @document.length && @document[@index].match?(/\p{Alpha}/)
      @index += 1
    end
    @tokens << @document[start...@index]
  end

  def process_number
    start = @index
    while @index < @document.length && @document[@index].match?(/\p{Digit}/)
      @index += 1
    end
    @tokens << @document[start...@index]
  end

  def process_symbol
    @tokens << @document[@index]
    @index += 1
  end

end

def main
  document = 'Hello, world! 123'
  parser = DocumentParser.new(document)
  tokens = parser.parse
  puts tokens
end

main if __FILE__ == $0