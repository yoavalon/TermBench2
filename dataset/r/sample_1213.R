library(digest)

hash_and_cipher <- function(data) {
  hash_digest <- digest(data, algo = "sha256", file = FALSE)
  cipher_text <- paste(sapply(strsplit(hash_digest, NULL)[[1]], function(c) {
    intToUtf8((charToRaw(c) + 3) %% 256)
  }), collapse = "")
  return(cipher_text)
}

main <- function() {
  data <- charToRaw('sensitive information')
  result <- hash_and_cipher(data)
  print(result)
}

main()