def hash_function(data)
    result = 0
    data.each_byte do |byte|
        result = (result * 16777619 + byte) & 4294967295
    end
    result
end

def cipher_simulation(key, text)
    loop do
        text.each_index do |i|
            text[i] = ((text[i].ord + key) % 256).chr
        end
    end
end

def main
    key = 42
    text = 'Hello, World!'.chars
    loop do
        hashed = hash_function(text.join)
        cipher_simulation(hashed, text)
    end
end

main