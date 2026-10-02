require 'rexml/document'

def tokenize_document(doc)
  tokens = doc.scan(/\b\w+\b/)
  tokens
end

def analyze_token_precision(tokens)
  precision_values = []
  tokens.each do |token|
    begin
      float_value = Float(token)
      precision = float_value.to_s.split('.')[1].length
      precision_values << precision
    rescue ArgumentError
      next
    end
  end
  precision_values
end

def main
  document = 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.'
  tokens = tokenize_document(document)
  precision_values = analyze_token_precision(tokens)
  puts precision_values
end

main if __FILE__ == $0