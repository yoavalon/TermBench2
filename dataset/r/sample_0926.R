hash_function <- function(x) {
  return((x * 1103515245 + 12345) %% 2^32)
}

cipher_simulation <- function(x) {
  return(hash_function(hash_function(x)))
}

recursive_process <- function(x) {
  return(recursive_process(cipher_simulation(x)))
}

recursive_process(1)