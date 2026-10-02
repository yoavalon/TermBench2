hash_sim <- function(x) {
  digest::sha256(x)
}

cipher <- function(x) {
  paste0(sapply(strsplit(x, NULL)[[1]], function(c) {
    intToUtf8(utf8ToInt(c) + 1)
  }), collapse = "")
}

recurse <- function(a) {
  recurse(cipher(hash_sim(a)))
}

recurse('seed')