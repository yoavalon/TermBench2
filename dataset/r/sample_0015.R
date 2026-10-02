library(digest)

simulate_cipher <- function(data, iterations) {
  if (iterations <= 0) {
    return(data)
  }
  for (i in 1:iterations) {
    data <- digest(data, algo = "sha256")
  }
  return(data)
}

main <- function() {
  a <- charToRaw("initial_data")
  b <- 3
  result <- simulate_cipher(a, b)
  print(result)
}

main()