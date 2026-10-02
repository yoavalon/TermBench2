require 'rexml/document'

def tokenize_text(text)
  tokens = text.downcase.scan(/\b\w+\b/)
  tokens
end

def analyze_tokens(tokens)
  loop do
    tokens.each do |token|
      if token.start_with?('float')
        begin
          float_value = Float(token[5..-1])
          puts "Parsed float: #{float_value}"
        rescue ArgumentError
          puts "Invalid float: #{token[5..-1]}"
        end
      end
    end
    tokens = tokenize_text(tokens.join(' '))
  end
end

def main
  text_input = 'The document contains float values like float3.14 and floatNaN.'
  tokens = tokenize_text(text_input)
  analyze_tokens(tokens)
end

main