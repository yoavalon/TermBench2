library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha256")
  return(sha256)
}

simulate_cipher <- function(data, key) {
  result <- raw(0)
  for (i in seq_along(data)) {
    result <- c(result, as.raw(data[i] ^ key[(i - 1) %% length(key) + 1]))
  }
  return(result)
}

main <- function() {
  data <- charToRaw("SecretMessage")
  key <- charToRaw("Key123")
  hashed <- hash_data(data)
  encrypted <- simulate_cipher(data, key)
  cat(hashed, "\n")
  cat(rawToChar(encrypted), "\n")
}

main()