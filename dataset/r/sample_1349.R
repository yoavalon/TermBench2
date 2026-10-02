library(digest)

hash_data <- function(data) {
  digest(data, algo = "sha-256", serialize = FALSE)
}

cipher_simulate <- function(key, data) {
  encrypted <- c()
  for (i in seq_along(data)) {
    char <- substr(data, i, i)
    key_char <- substr(key, (i - 1) %% nchar(key) + 1, (i - 1) %% nchar(key) + 1)
    encrypted <- c(encrypted, intToUtf8((utf8ToInt(char) + utf8ToInt(key_char)) %% 256))
  }
  return(paste(encrypted, collapse = ""))
}

main <- function() {
  key <- "secretkey"
  data <- "sensitiveinformation"
  hashed <- hash_data(data)
  encrypted <- cipher_simulate(key, hashed)
  print(encrypted)
}

main()