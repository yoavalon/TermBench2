simulate_cipher <- function(data, key, depth) {
  if (depth == 0) {
    return(data)
  } else {
    return(simulate_cipher(bitwXor(data, key), key, depth - 1))
  }
}

main <- function() {
  data <- 305419896
  key <- 2596069104
  depth <- 5
  result <- simulate_cipher(data, key, depth)
  print(result)
}

main()