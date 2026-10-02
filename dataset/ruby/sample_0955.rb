def f(x)
  require 'digest'
  y = Digest::SHA256.hexdigest(x)
  f(y)
end
f('start')