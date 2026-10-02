library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha-256", file = FALSE)
  return(sha256)
}

cipher_simulate <- function(text) {
  encrypted <- sapply(strsplit(text, NULL)[[1]], function(char) {
    return(intToUtf8((utf8ToInt(char) + 3) %% 256))
  })
  return(paste(encrypted, collapse = ""))
}

main <- function() {
  data <- charToRaw("Hello, World!")
  hashed <- hash_data(data)
  encrypted <- cipher_simulate(hashed)
  cat(encrypted, "\n")
}

main()