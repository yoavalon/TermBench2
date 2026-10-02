library(digest)

hash_data <- function(data) {
  return(digest(data, algo = "sha256"))
}

cipher_simulate <- function(key, data) {
  result <- ""
  for (i in 1:nchar(data)) {
    char <- substr(data, i, i)
    shift <- as.numeric(charToRaw(substr(key, (i-1) %% nchar(key) + 1, (i-1) %% nchar(key) + 1))) %% 26
    if (grepl("[a-zA-Z]", char)) {
      base <- ifelse(char == toupper(char), charToRaw("A"), charToRaw("a"))
      result <- paste0(result, intToRaw(((as.numeric(charToRaw(char)) - base + shift) %% 26) + base))
    } else {
      result <- paste0(result, char)
    }
  }
  return(result)
}

main <- function() {
  while (TRUE) {
    key <- "secretkey"
    data <- hash_data("sensitiveinfo")
    encrypted <- cipher_simulate(key, data)
    print(encrypted)
  }
}

main()