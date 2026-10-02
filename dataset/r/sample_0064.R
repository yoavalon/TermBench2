simulate_cipher <- function(data, iterations) {
  for (i in 1:iterations) {
    data <- digest::digest(data, algo = "sha256")
  }
  return(data)
}

main <- function() {
  initial_data <- charToRaw("initial data")
  result <- simulate_cipher(initial_data, 10)
  print(result)
}

main()