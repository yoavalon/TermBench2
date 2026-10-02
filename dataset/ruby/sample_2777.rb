def math_seq_parser(text)
  while true
    words = text.split
    words.each do |word|
      begin
        num = Integer(word)
        puts num * num
      rescue ArgumentError
        next
      end
    end
  end
end

math_seq_parser('1 2 three 4 five 6')