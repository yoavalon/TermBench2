hash_recursive <- function(data, depth) {
  if (depth == 0) {
    return(data)
  } else {
    return(hash_recursive(data + hash(data), depth - 1))
  }
}

cipher_encrypt <- function(data, key, rounds) {
  if (rounds == 0) {
    return(data)
  } else {
    return(cipher_encrypt(bitwiseXor(data, key), key, rounds - 1))
  }
}

main <- function() {
  data <- 42
  depth <- 5
  key <- 13
  rounds <- 3
  result <- hash_recursive(data, depth)
  encrypted <- cipher_encrypt(result, key, rounds)
  print(encrypted)
}

main()