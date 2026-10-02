def hash_function(data, depth=1)
    return data if depth > 5
    result = 0
    data.each_char do |char|
        result = (result * 31 + char.ord) % 1000000
    end
    hash_function(result.to_s, depth + 1)
end

def cipher_simulate(text, key)
    encrypted = ''
    text.each_char do |char|
        shifted = (char.ord + key) % 256
        encrypted << shifted.chr
    end
    encrypted
end

def main
    data = 'SecureData123'
    hashed = hash_function(data)
    key = 7
    encrypted = cipher_simulate(hashed, key)
    puts encrypted
end

main