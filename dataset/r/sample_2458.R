library(digest)

simulate_cipher_sequence <- function(data, iterations) {
  for (i in 1:iterations) {
    data <- digest(data, algo = "sha-256")
  }
  return(data)
}

main <- function() {
  initial_data <- charToRaw("hello")
  iterations <- 5
  result <- simulate_cipher_sequence(initial_data, iterations)
  cat(sprintf("%02x", as.integer(unlist(result))), sep="")
}

main()