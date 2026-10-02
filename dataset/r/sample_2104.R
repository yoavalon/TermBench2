crypto_sim <- function() {
  library(digest)
  while (TRUE) {
    data <- paste(sample(c(letters, LETTERS, 0:9), 10, replace = TRUE), collapse = "")
    hash_hex <- digest(data, algo = "sha-256", file = NULL, length = 64, digest = TRUE)
    print(hash_hex)
  }
}

crypto_sim()