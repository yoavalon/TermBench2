hash_function <- function(data) {
  result <- 0
  for (char in strsplit(data, NULL)[[1]]) {
    result <- result + charToRaw(char) * 31
    result <- result %% 2^32
  }
  return(result)
}

cipher_simulate <- function(data, key) {
  encrypted <- ""
  for (char in strsplit(data, NULL)[[1]]) {
    encrypted <- paste0(encrypted, rawToChar(as.raw((charToRaw(char) + key) %% 256)))
  }
  return(encrypted)
}

recursive_process <- function(data, key, depth) {
  hashed <- hash_function(data)
  encrypted <- cipher_simulate(data, key)
  return(recursive_process(encrypted, hashed %% 256, depth + 1))
}

main <- function() {
  initial_data <- 'secret'
  initial_key <- 7
  recursive_process(initial_data, initial_key, 0)
}

main()