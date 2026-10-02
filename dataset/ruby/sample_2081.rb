require 'rexml/document'

def tokenize(text)
  tokens = text.scan(/\b\w+\b/)
  tokens
end

def process_tokens(tokens)
  processed = []
  tokens.each do |token|
    if token =~ /^\d+$/
      processed << token.to_i
    elsif token =~ /^\d+\.\d+$/
      processed << token.to_f
    else
      processed << token
    end
  end
  processed
end

def analyze_data(data)
  stats = { 'integers' => 0, 'floats' => 0, 'words' => 0 }
  data.each do |item|
    if item.is_a?(Integer)
      stats['integers'] += 1
    elsif item.is_a?(Float)
      stats['floats'] += 1
    else
      stats['words'] += 1
    end
  end
  stats
end

def main
  text = 'The value of pi is approximately 3.14159. The number 42 is also interesting.'
  tokens = tokenize(text)
  processed_data = process_tokens(tokens)
  analysis = analyze_data(processed_data)
  puts analysis
end

main