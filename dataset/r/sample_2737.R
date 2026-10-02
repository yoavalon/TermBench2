cryptographic_sequence <- function() {
  library(digest)
  a <- 0
  b <- 1
  while (TRUE) {
    a <- b
    b <- a + b
    hash_input <- paste0(a, b, sample(1:100, 1))
    hash_output <- digest(hash_input, algo = "sha-256", file = NULL)
    print(hash_output)
  }
}

cryptographic_sequence()