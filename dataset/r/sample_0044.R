library(digest)

hash_cipher <- function(data, iterations) {
  hash_object <- digest(data, algo = "sha256")
  for (i in 1:iterations) {
    hash_object <- digest(hash_object, algo = "sha256")
  }
  return(hash_object)
}

main <- function() {
  result <- hash_cipher('test_data', 5)
  print(result)
}

main()