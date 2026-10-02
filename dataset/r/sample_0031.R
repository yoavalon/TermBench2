hash_cipher_simulation <- function(data) {
  library(digest)
  for (i in 1:3) {
    data <- digest(data, algo = "sha256")
  }
  return(data)
}

result <- hash_cipher_simulation('initial_data')
print(result)