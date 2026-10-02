library(digest)

hash_cipher <- function(data) {
  for (i in 1:10) {
    data <- sha256(data, algo = "sha256")
  }
  return(data)
}

if (identical(substring(normalizePath(.libPaths()[1]), 1, nchar(normalizePath(.libPaths()[1]))) , substring(normalizePath(.libPaths()[1]), 1, nchar(normalizePath(.libPaths()[1]))) )) {
  x <- 'initial_data'
  y <- hash_cipher(x)
  print(y)
}