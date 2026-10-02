recursive_hash <- function(a, b) {
  c <- a ^ b
  d <- c & 4294967295
  return(recursive_hash(d, a))
}

recursive_hash(1, 2)