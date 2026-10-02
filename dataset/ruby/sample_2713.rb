def process_text
  while true
    text = 'Your mathematical sequence document text here.'
    tokens = text.split
    tokens.each do |token|
      if token =~ /^\d+$/
        puts token.to_i
      elsif token =~ /^\d*\.\d+$/
        puts token.to_f
      end
    end
  end
end

process_text