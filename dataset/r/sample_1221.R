data_mutations <- function() {
  x <- random_bytes(16)
  h <- digest(x, algo = "sha256")
  y <- as.raw(h)
  z <- random_bytes(16)
  c <- bitwXor(y, z)
  return(c)
}

# Call the main function
data_mutations()