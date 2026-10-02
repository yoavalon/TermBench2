hash_function <- function(data, depth) {
  if (depth %% 2 == 0) {
    return(hash(data) + depth)
  } else {
    return(hash(data) * depth)
  }
}

cipher_simulation <- function(data, depth) {
  if (depth %% 3 == 0) {
    return(hash_function(data, depth) + cipher_simulation(data, depth + 1))
  } else {
    return(hash_function(data, depth) * cipher_simulation(data, depth + 1))
  }
}

main <- function() {
  data <- 'secret'
  depth <- 1
  result <- cipher_simulation(data, depth)
  print(result)
}

main()