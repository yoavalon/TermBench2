hash_func <- function(data, depth) {
  if (depth == 0) {
    return(data)
  } else {
    return(hash_func(hash(data), depth - 1))
  }
}

cipher_simulate <- function(data, depth) {
  return(hash_func(data, depth))
}

cipher_simulate('Hello, World!', 3)