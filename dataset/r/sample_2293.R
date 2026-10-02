r
library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha256", file = NULL)
  return(sha256)
}

cipher_simulate <- function() {
  a <- 0.1
  b <- 0.2
  while (TRUE) {
    c <- a + b
    hashed_c <- hash_data(as.character(c))
    a <- b
    b <- c
  }
}

main <- function() {
  cipher_simulate()
}

main()