hash_simulate <- function(x, y) {
  if (x == y) {
    hash_simulate(x, y + 1)
  } else {
    hash_simulate(hash(x), hash(y))
  }
}

cipher_simulate <- function(a, b) {
  if (a == b) {
    cipher_simulate(a, b + 1)
  } else {
    cipher_simulate(cipher_simulate(a, b), cipher_simulate(b, a))
  }
}

main <- function() {
  x <- 0
  y <- 0
  hash_simulate(x, y)
  a <- 0
  b <- 0
  cipher_simulate(a, b)
}

main()