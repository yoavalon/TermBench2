library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha256")
  return(sha256)
}

simulate_cipher <- function(hash_value) {
  result <- ""
  for (char in strsplit(hash_value, NULL)[[1]]) {
    if (grepl("[0-9]", char)) {
      result <- paste0(result, as.character((as.numeric(char) + 5) %% 10))
    } else {
      result <- paste0(result, intToUtf8((charToRaw(char) + 3) %% 256))
    }
  }
  return(result)
}

main <- function() {
  data <- 'securedata'
  hashed <- hash_data(data)
  ciphered <- simulate_cipher(hashed)
  print(ciphered)
}

main()