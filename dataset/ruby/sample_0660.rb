def vectorize_text(text, index=0, result=nil)
    result = [] if result.nil?
    if index < text.length
        result << text[index].ord
        return vectorize_text(text, index + 1, result)
    end
    return result
end

puts vectorize_text('hello')