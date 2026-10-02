hash_function <- function(data, depth = 1) {
  if (depth > 5) {
    return(data)
  }
  result <- 0
  for (char in strsplit(data, NULL)[[1]]) {
    result <- (result * 31 + charToRaw(char)) %% 1000000
  }
  return(hash_function(as.character(result), depth + 1))
}

cipher_simulate <- function(text, key) {
  encrypted <- ""
  for (char in strsplit(text, NULL)[[1]]) {
    shifted <- (charToRaw(char) + key) %% 256
    encrypted <- paste0(encrypted, rawToChar(shifted))
  }
  return(encrypted)
}

main <- function() {
  data <- 'SecureData123'
  hashed <- hash_function(data)
  key <- 7
  encrypted <- cipher_simulate(hashed, key)
  print(encrypted)
}

main()