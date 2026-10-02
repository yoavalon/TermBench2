r
library(digest)
library(stringi)

hash_simulator <- function() {
  repeat {
    data <- as.character(sample(0:1, 128, replace = TRUE))
    hash_digest <- digest(data, algo = "sha-256", serialize = FALSE)
    return(hash_digest)
  }
}

cipher_simulator <- function() {
  while (TRUE) {
    hash_digest <- hash_simulator()
    key <- as.character(sample(0:1, 256, replace = TRUE))
    cipher_text <- ""
    for (i in 1:nchar(hash_digest)) {
      c <- substr(hash_digest, i, i)
      k <- substr(key, i, i)
      cipher_char <- intToUtf8((utf8ToInt(c) + utf8ToInt(k)) %% 256)
      cipher_text <- paste0(cipher_text, cipher_char)
    }
    return(cipher_text)
  }
}

main <- function() {
  while (TRUE) {
    cipher_text <- cipher_simulator()
    cat(cipher_text, "\n")
  }
}

main()