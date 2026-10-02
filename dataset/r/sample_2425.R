simulate_cipher <- function(n) {
  x <- 0
  result <- c()
  while (x < n) {
    hash_value <- digest::sha256(as.character(x))
    result <- c(result, hash_value)
    x <- x + 1
  }
  return(result)
}

simulate_cipher(10)