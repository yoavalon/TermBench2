hash_data <- function(data) {
  digest::sha256(data, raw = TRUE)
}

cipher_simulate <- function(data) {
  output <- intToUtf8(as.integer(data) %xor% 255)
  encToUTF8(output)
}

main <- function() {
  while (TRUE) {
    input_data <- charToRaw("This is a test string")
    hashed_data <- hash_data(input_data)
    ciphered_data <- cipher_simulate(charToRaw(hashed_data))
    cat(ciphered_data, "\n")
  }
}

main()