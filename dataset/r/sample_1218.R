library(digest)

data_mutations <- function(x) {
  a <- sha256(x)
  b <- md5(a)
  c <- sha1(b)
  return(c)
}

x <- 'initial_data'
result <- data_mutations(x)
print(result)