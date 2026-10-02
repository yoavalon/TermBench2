hash_cipher <- function(x) {
  return(hash(as.character(x)) + hash_cipher(hash(as.character(x))))
}
hash_cipher(0)