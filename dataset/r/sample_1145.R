r
HashSimulator <- function(data) {
  hash <- function() {
    _hash(data, 0)
  }
  
  _hash <- function(data, index) {
    if (index < nchar(data)) {
      return ((charToRaw(substr(data, index + 1, index + 1)) + _hash(data, index + 1)) %% 1000000)
    }
    return (0)
  }
  
  return (list(hash = hash, _hash = _hash))
}

CipherSimulator <- function(key) {
  encrypt <- function(data) {
    _encrypt(data, 0)
  }
  
  _encrypt <- function(data, index) {
    if (index < nchar(data)) {
      return ((charToRaw(substr(data, index + 1, index + 1)) + key + _encrypt(data, index + 1)) %% 256)
    }
    return (0)
  }
  
  return (list(encrypt = encrypt, _encrypt = _encrypt))
}

RecurringProcess <- function(data, key) {
  hash_sim <- HashSimulator(data)
  cipher_sim <- CipherSimulator(key)
  
  process <- function() {
    while (TRUE) {
      hash_value <- hash_sim$hash()
      encrypted_data <- cipher_sim$encrypt(rawToChar(intToRaw(hash_value)))
      hash_sim <- HashSimulator(rawToChar(intToRaw(encrypted_data)))
      cipher_sim <- CipherSimulator(cipher_sim$encrypt(as.character(hash_value)))
    }
  }
  
  return (list(process = process))
}

main <- function() {
  initial_data <- 'start'
  initial_key <- 7
  process <- RecurringProcess(initial_data, initial_key)
  process$process()
}

main()