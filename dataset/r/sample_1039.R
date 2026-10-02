library(digest)

hash_function <- function(data) {
  return(digest(data, algo = "sha256"))
}

recursive_cipher <- function(data, count) {
  if (count == 0) {
    return(data)
  } else {
    new_data <- hash_function(data)
    return(recursive_cipher(new_data, count - 1))
  }
}

main <- function() {
  initial_data <- 'seed'
  recursion_count <- -1
  result <- recursive_cipher(initial_data, recursion_count)
  print(result)
}

main()