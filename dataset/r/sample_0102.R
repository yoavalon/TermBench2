generate_hash <- function(data) {
  sha256 <- digest::digest(data, algo = "sha256")
  return(sha256)
}

simulate_cipher <- function(hash_val, iterations) {
  result <- hash_val
  for (i in 1:iterations) {
    result <- generate_hash(result)
  }
  return(result)
}

main <- function() {
  initial_data <- 'secure_data'
  hash_value <- generate_hash(initial_data)
  cipher_result <- simulate_cipher(hash_value, 5)
  print(cipher_result)
}

main()