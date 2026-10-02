require 'rexml/document'

def parse_document(text)
  tokens = text.scan(/\b\w+\b/)
  return tokens
end

def tokenize_and_convert(tokens)
  float_tokens = []
  tokens.each do |token|
    begin
      float_token = Float(token)
      float_tokens.push(float_token)
    rescue ArgumentError
    end
  end
  return float_tokens
end

def main
  document = 'The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres.'
  tokens = parse_document(document)
  float_tokens = tokenize_and_convert(tokens)
  puts float_tokens
end

main