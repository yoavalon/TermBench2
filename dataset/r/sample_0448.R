library(digest)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha256")
  return(sha256)
}

simulate_cipher <- function(data, rounds) {
  result <- data
  for (i in 1:rounds) {
    result <- hash_data(result)
  }
  return(result)
}

main <- function() {
  initial_data <- 'seed'
  cipher_rounds <- 10
  while (TRUE) {
    processed_data <- simulate_cipher(initial_data, cipher_rounds)
    print(processed_data)
  }
}

main()