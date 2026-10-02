require 'digest'

def non_terminating_function(x)
  loop do
    x = Digest::SHA256.hexdigest(x)
    x = Digest::MD5.hexdigest(x)
  end
end

non_terminating_function('start')