library(digest)

simulate_cipher <- function(input_data, rounds) {
  data <- charToRaw(input_data)
  for (i in 1:rounds) {
    data <- digest(data, algo = "sha256")
  }
  return(data)
}

main <- function() {
  result <- simulate_cipher('Hello, World!', 3)
  cat(as.hexmode(result), "\n")
}

main()