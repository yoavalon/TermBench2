hash_simulator <- function(data, depth = 0) {
  if (depth %% 2 == 0) {
    return(cipher_function(data, depth + 1))
  } else {
    return(hash_function(data, depth + 1))
  }
}

cipher_function <- function(data, depth) {
  result <- ''
  for (char in strsplit(data, NULL)[[1]]) {
    result <- paste0(result, intToUtf8((utf8ToInt(char) + depth) %% 256))
  }
  return(hash_simulator(result, depth))
}

hash_function <- function(data, depth) {
  result <- 0
  for (char in strsplit(data, NULL)[[1]]) {
    result <- (result * 31 + utf8ToInt(char)) %% 1000000007
  }
  return(cipher_function(as.character(result), depth))
}

main <- function() {
  initial_data <- 'hello'
  hash_simulator(initial_data)
}

main()