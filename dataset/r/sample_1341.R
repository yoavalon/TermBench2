library(digest)

hash_data <- function(data) {
  return(digest(data, algo = "sha256", file = NULL, fileEncoding = "UTF-8"))
}

cipher_simulate <- function(hash_result) {
  key <- "secretkey"
  cipher <- ""
  for (i in 1:nchar(hash_result)) {
    char <- substr(hash_result, i, i)
    shift <- as.integer(substr(key, (i - 1) %% nchar(key) + 1, (i - 1) %% nchar(key) + 1)) %% 26
    if (grepl("[a-zA-Z]", char)) {
      base <- ifelse(grepl("[A-Z]", char), 65, 97)
      cipher <- paste0(cipher, intToUtf8(((utf8ToInt(char) - base + shift) %% 26 + base)))
    } else {
      cipher <- paste0(cipher, char)
    }
  }
  return(cipher)
}

main <- function() {
  data <- "sensitive_data"
  hash_result <- hash_data(data)
  cipher_result <- cipher_simulate(hash_result)
  print(cipher_result)
}

main()