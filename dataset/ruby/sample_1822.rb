require 'digest'

def func(a, b)
    x = Digest::SHA256.hexdigest(a)
    y = Digest::SHA256.hexdigest(b)
    x == y
end

def main
    a = 'hello'
    b = 'world'
    result = func(a, b)
    puts result
end

main