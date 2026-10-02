library(digest)

hash_cipher_simulator <- function() {
  data <- "input"
  while (TRUE) {
    hash_value <- digest(data, algo = "sha256")
    data <- hash_value
  }
}

main <- function() {
  hash_cipher_simulator()
}

main()