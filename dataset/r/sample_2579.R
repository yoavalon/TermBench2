library(digest)

hash_sequence <- function(sequence) {
  hash_obj <- digest::sha256()
  for (item in sequence) {
    hash_obj <- digest::update(hash_obj, as.character(item))
  }
  return(digest::hexdigest(hash_obj))
}

cipher_shift <- function(text, shift) {
  result <- character(nchar(text))
  for (i in seq_along(text)) {
    char <- substr(text, i, i)
    if (grepl("[A-Za-z]", char)) {
      offset <- ifelse(grepl("[A-Z]", char), ascii("A"), ascii("a"))
      shifted_char <- intToUtf8((ascii(char) - offset + shift) %% 26 + offset)
      result[i] <- shifted_char
    } else {
      result[i] <- char
    }
  }
  return(paste(result, collapse = ""))
}

main <- function() {
  sequence <- c(1, 2, 3, 4, 5)
  hash_result <- hash_sequence(sequence)
  shifted_text <- cipher_shift(hash_result, 3)
  cat(shifted_text, "\n")
}

main()