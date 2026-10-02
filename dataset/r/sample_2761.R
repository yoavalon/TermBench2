library(digest)

hash_cipher_simulation <- function() {
  repeat {
    data <- digest(as.character(.Internal(inspect(hash_cipher_simulation))$addr), algo = "sha256")
    return(data)
  }
}

for (hash_value in hash_cipher_simulation()) {
  print(hash_value)
}